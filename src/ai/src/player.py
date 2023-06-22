from macro import *
from level import level

class Player:
    def __init__(self, nb_player, map_size, player_level):
        """Init the player object

        Args:
            nb_player (_type_): _description_
            map_size (_type_): _description_
            player_level (_type_): _description_
        """
        self.nb_player = nb_player
        self.team_mate = 1
        self.map_size = map_size
        self.count_players = 1
        self.lvl_instance = level()
        self.obj_list = self.lvl_instance.setObj(player_level)
        self.inventory:dict
        self.sight:str
        self.item_needed:list = []
        self.needList:list = []
        for i in self.obj_list:
            if (i == "player"):
                continue
            else:
                for j in range(self.obj_list[i]):
                    self.item_needed.append(i)

    def multiplePlayerTile(self) -> bool:
        """_summary_

        Returns:
            bool: _description_
        """
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
