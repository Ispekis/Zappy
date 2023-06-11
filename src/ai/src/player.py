from macro import *
from level import setobjectif

class Player:
    def __init__(self, nb_player, map_size, level):
        self.nb_player = nb_player
        self.map_size = map_size
        self.obj_list = setobjectif(level)
        self.inventory:str
        self.sight:str

    def multiplePlayerTile(self):
        if find_value(self.sight, "player") > 1:
            return True
        return False

def find_value(sight_list, value):
    """find a value in a list of list

    Args:
        sight_list (list): sight in list
        value (str): the value

    Returns:
        int: number of time that we find the value
    """

    res = 0
    for sublist in sight_list:
        for item in sublist:
            if item == value:
                res += 1
    return res