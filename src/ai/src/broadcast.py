from macro import *
from utils import comp_obj, crypt, rcvFromatter
from player import Player
import random
import socket

def ask(team:str, type:int, value:str=None, level:int=0) -> str:
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
        return "{} {} {} {}".format(msg_id, team, str(type), value)
    elif level != 0:
        # ask player with a same level
        return "{} {} {} {} {}".format(msg_id, team, str(type), value, level)

def broadcast(player:Player, client_socket:socket, broadcast:list, broadcast_direction:list) -> None:
    """Créate the broadcast message

    Args:
        player (Player): player info
        client_socket (socket): client socket
    """
    message:str = None
    if player.check_necessity() == True and player.ask == False and player.level >= 2:
        message = ask(player.team, ASK, player.item_needed[0])
    elif len(player.item_needed) and player.ask == False and player.level >= 2:
        message = ask(player.team, ASK, PLAYER, player.level)
    if message != None:
        # message = crypt(player.team, message)
        client_socket.send(("Broadcast" + message + "\n").encode())
        res = rcvFromatter(client_socket, BROADCAST, broadcast, broadcast_direction)
        if res == "ok\n":
            player.ask = True

def analyse_broadcast(player:Player, broadcast:list, broadcast_direction:list) -> str:
    for i in range(len(broadcast)):
            print(f"chiffre = {len(broadcast[i])}")
            print(f"dechiffrer = {crypt(player.team, broadcast[i])}")
            print(broadcast_direction[i])
    return
