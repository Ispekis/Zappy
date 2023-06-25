from macro import *
from utils import comp_obj, crypt, rcvFromatter
from player import Player
import random
import socket

class Broadcast:
    def __init__(self, socket:socket):
        self.client_socket = socket
        self.currentTask:int = None
        self.player:Player = None
        self.state:str = None

    def updatePlayer(self, play:Player) -> None:
        self.player = play

    def answer(self, message:str) -> None:
        msg:str = "{} {} {} {}".format(self.currentTask, self.player.team, 1, message)
        self.client_socket.send(("Broadcast " + msg + "\n").encode())

    def ask(self, team:str, type:int, value:str=None, level:int=0) -> str:
        """Create the different type of broadcast

        Args:
            team (str): team name
            type (int): type of message SIGNAL ASK OR RESPONSE
            value (str, optional): Stone or food. Defaults to None.
            quantity (int, optional): Quantity of value. Defaults to 0.
            level (int, optional): Level of player needed. Defaults to 0.

        Returns:
            str: Message for the broadcast
        """
        msg_id = random.randint(0, 1000)
        if level == 0:
            # ask stone
            return "{} {} {} {}".format(msg_id, team, type, value)
        elif level != 0:
            # ask player with a same level
            return "{} {} {} {} {}".format(msg_id, team, type, value, level)

    def broadcast(self, player:Player, broadcast:list, broadcast_direction:list) -> None:
        """Créate the broadcast message

        Args:
            player (Player): player info
            client_socket (socket): client socket
        """
        message:str = None
        if player.check_necessity() == True and player.ask == False and player.level >= 2:
            message = self.ask(player.team, ASK, player.item_needed[0])
        elif len(player.item_needed) and player.ask == False and player.level >= 2:
            message = self.ask(player.team, ASK, PLAYER, player.level)
        if message != None:
            # message = crypt(player.team, message)
            self.client_socket.send(("Broadcast " + message + "\n").encode())
            res = rcvFromatter(self.client_socket, BROADCAST, broadcast, broadcast_direction)
            if res == "ok\n":
                player.ask = True
                self.state = "sender"
                self.currentTask = message[0]

    def goesToPlayer(self, direction:int) -> str:
        if direction == 1 or direction == 2 or direction == 8:
            return FORWARD
        if direction == 3 or direction == 4 or direction == 5:
            return LEFT
        if direction == 7 or direction == 6:
            return RIGHT

    def checkItemRequirement(self, broadcast:list) -> int:
        if broadcast[1] != self.player.team:
            return FAILURE
        try:
            if self.player.inventory[broadcast[2]] < broadcast[3]:
                return FAILURE
            self.currentTask = broadcast[0]
            self.answer("ok")
            self.state = "receiver"
            return SUCCESS
        except ValueError:
            return FAILURE

    def checkRankUpRequirement(self, broadcast:list) -> int:
        if broadcast[4] != self.player.level:
            return FAILURE
        self.currentTask = broadcast[0]
        self.answer("ok")
        self.state = "receiver"
        return SUCCESS

    def acceptRequest(self, broadcast:list) -> int:
        if len(broadcast) == 4:
            self.checkItemRequirement(broadcast)
        elif len(broadcast) == 5:
            self.checkRankUpRequirement(broadcast)
            
    def checkDirection(self, broadcast:list) -> int:
        if len(broadcast) != 4:
            return FAILURE
        if broadcast[0] != self.currentTask:
            return FAILURE
        if broadcast[2] != 1:
            return FAILURE
        if broadcast[3] != "Come":
            return FAILURE
        return SUCCESS

    def checkInformation(self, broadcast:list):
        if len(broadcast) != 4:
            return FAILURE
        if broadcast[0] != self.currentTask:
            return FAILURE
        if broadcast[2] != 1:
            return FAILURE
        if broadcast[3] != "Ok":
            return FAILURE
        return SUCCESS

    def analyseSender(self, broadcast:list):
        for i in range(len(broadcast)):
            if self.checkInformation(broadcast[i]) == SUCCESS:
                broadcast.pop(i)
            self.answer("Come")
            

    def analyse_broadcast(self, broadcast:list, broadcast_direction:list) -> str:
        status:str = None
        tmp:int = -1
        if self.state == "sender":
            self.analyseSender(broadcast)
        else:
            if self.currentTask != None:
                for i in range(len(broadcast_direction)):
                    if self.checkDirection(broadcast[i]) == SUCCESS:
                        broadcast.pop[i]
                        tmp = i
                        status = "Ok"
                        break
                if status != "Ok":
                    return None
                self.answer("Ok")
                return self.goesToPlayer(broadcast_direction[tmp])
            for i in range(len(broadcast)):
                    # print(broadcast[i])
                    self.acceptRequest(broadcast[i])
            return None
        return None
