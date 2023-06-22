from player import Player
from macro import *
import socket
from items import Items
from utils import count_player, comp_obj
from level import level

def drop_obj(inventory:dict, obj_list:dict, objectives:list, client_socket:socket) -> None:
    items:Items = Items(client_socket)
    tmp = obj_list.copy()
    i:int = 0
    del tmp[PLAYER]

    for key, value in tmp.items():
        if inventory[key] == tmp[key]:
            i += 1
            print(i)
            res = items.setItem(key, objectives)

def split_lvl(return_value:str, actual_lvl:int):
    tmp = return_value.split(" ")
    if len(tmp) == 3:
        return int(tmp[2][0])
    return actual_lvl

def get_return_value(return_value:str, player:Player):
    # if return_value == "Elevation underway\n":
    player.attitude = NORMAL
    player.level = split_lvl(return_value)
    player.obj_list = player.lvl_instance.setObj(player.level)
    player.set_item_needed()
    player.ask = False

def levelUp(player:Player, client_socket:socket) -> None:
    """Launche the incantation if he can

    Args:
        player (Player): player info
        client_socket (socket): client socket
    """
    player_needed = count_player(player.sight[0])
    print(player.inventory)
    if len(player.item_needed) == 0 and player_needed == player.obj_list[PLAYER]:
        drop_obj(player.inventory, player.obj_list, player.item_needed, client_socket)
        client_socket.send(("Incantation\n").encode())
        elevation_ko = client_socket.recv(1024).decode()
        print(f"elevation = {elevation_ko}")
        if elevation_ko != "ko\n":
            level_ko = client_socket.recv(1024).decode()
            print(f"level = {level_ko}")
            if level_ko != "ko\n":
                get_return_value(level_ko, player)
