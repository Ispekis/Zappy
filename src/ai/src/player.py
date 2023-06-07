from macro import *
from level import setobjectif

class Player:
    def __init__(self, nb_player, map_size, level):
        self.nb_player = nb_player
        self.map_size = map_size
        self.obj_list = setobjectif(level)
        self.inventory:str
        self.sight:str
