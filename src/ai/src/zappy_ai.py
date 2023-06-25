import tcp_client as tc
import myexception
import socket
import sys
from parsing import *
from player import Player, push
from movement import Movement
from items import Items
from macro import *
from levelup import *
from fork import *
from utils import *
from broadcast import *

class AI:
    def __init__(self, port:str, machine:str, name:str) -> None:
        """
        Run the AI script

        Args:
            port (int): Port parameter
            name (str): Team name
            machine (str): Machine parameter

        Returns:
            int: 1 if an error occurs, 0 if not
        """
        # Connecting to server
        try:
            self.client_socket = tc.connection(machine, port)
        except (socket.gaierror, ConnectionRefusedError) as e:
            raise myexception.Exception(e)
        self.broadcastmsg:list = []
        self.broadcast_direction:list = []
        self.client_socket.send((name + "\n").encode())
        self.itemHandling = Items(self.client_socket)
        self.player:Player
        self.setPlayer(name)
        self.move = Movement(self.client_socket, self.player.item_needed)
        self.broadcast:Broadcast = Broadcast()

    def setPlayer(self, name:str) -> None:
        """
        Set up player's information for the object

        Args:
            name (str): name of the player
        """
        recv_data = self.client_socket.recv(1024)
        print(recv_data.decode(), end="")
        rcv_data = self.client_socket.recv(1024)
        tmp = rcv_data.decode().split("\n")
        map_size = tmp[1].split(" ")
        try:
            # self.client_socket.send((f'Broadcast {name}').encode())
            self.player = Player(int(tmp[0]), 1, name)
        except IndexError:
            print(f"Error while creating the player, check if team name is correct", file=sys.stderr)

    def rcvServerResponse(self) -> None:
        """
        Set the sight, invetory and update the team slot free
        """
        self.client_socket.send(("Look\n").encode())
        self.player.sight = parseLook(rcvFromatter(self.client_socket, SIGHT, self.broadcastmsg, self.broadcast_direction)[2:-2])
        # print(f'sight = {self.player.sight}')
        self.client_socket.send(("Inventory\n").encode())
        self.player.inventory = parseInventory(rcvFromatter(self.client_socket, NORMAL, self.broadcastmsg, self.broadcast_direction)[2:-2])
        # print(f'inventory = [{self.player.inventory}]')
        try:
            self.client_socket.send(("Connect_nbr\n").encode())
            self.player.nb_player = int(rcvFromatter(self.client_socket, NORMAL, self.broadcastmsg, self.broadcast_direction))
        except ValueError:
            return
        # print(f'nbplayer = {self.player.nb_player}')

    def reproduction(self) -> None:
        if check_if_need_fork(self.player, self.player.sight):
            self.client_socket.send("fork\n".encode())
            rcv_data = rcvFromatter(self.client_socket, NORMAL, self.broadcastmsg, self.broadcast_direction)

    def playerAction(self) -> None:
        levelUp(self.player, self.client_socket, self.broadcastmsg, self.broadcast_direction)
        self.itemHandling.needsFood(self.player.inventory, self.player.needList)
        self.itemHandling.takeItem(self.player.sight, self.player.item_needed, self.player.needList, self.player.inventory, self.broadcastmsg, self.broadcast_direction)
        self.move.handleMovement(self.player.sight, self.player.needList)
        push(self.player, self.client_socket)
        self.reproduction()
        self.broadcast.updatePlayer(self.player)
        self.broadcast.broadcast(self.player, self.client_socket, self.broadcastmsg, self.broadcast_direction)


    def run_ai(self) -> int:
        """
        Main loop of the program, sending and receiving informations to/from the server.

        Returns:
            int: _description_
        """
        try:
            while True:
                self.rcvServerResponse()
                if self.player.inventory != "{}":
                    # print("inv ok")
                    self.playerAction()
                    self.broadcast.analyse_broadcast(self.broadcastmsg, self.broadcast_direction)
        except KeyboardInterrupt:
            return SUCCESS
        except BrokenPipeError:
            print("Your are dead !")
            return FAILURE
        return SUCCESS