from macro import *
from utils import comp_obj
from player import Player
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
    if type == SIGNAL:
        return "{} {}\n".format(team, type)
    elif level == 0:
        # ask stone
        return "{} {} {} {}\n".format(team, type, value)
    elif level != 0:
        # ask player with a same level
        return "{} {} {} {} {}\n".format(team, type, value, level)
    else:
        # ask food
        return "{} {} {}\n".format(team, type, value)

def broadcast(player:Player, client_socket:socket) -> None:
    signal_value = player.analyse_sight()
    if signal_value != None and player.ask == False:
        client_socket.send(f"Broadcast {ask(player.team, SIGNAL, signal_value)}")
        player.ask = True
    elif player.check_necessity() == True and player.ask == False:
        client_socket.send(f"Broadcast {ask(player.team, ASK, player.item_needed[0], len(player.item_needed))}")
        player.ask = True
    elif comp_obj(player.obj_list, player.sight[0]) and player.ask == False:
        client_socket.send(f"Broadcast {ask(player.team, ASK, PLAYER, player.level)}")
        player.ask = True

# def analyse_broadcast(broadcast:str, player:Player) -> int:
    # if 
