import json

class level:
    def __init__(self):
        self.levels = parseLevel("/home/bsteven/delivery/TEK2/YEP/B-YEP-400-PAR-4-1-zappy-vincent.shao/src/ai/level.json")

    def setObj(self, level):
        return self.levels[str(level)]

def parseLevel(filename):
    with open(filename) as file:
        data = json.load(file)
        parsed_list = {}
        for key, value in data.items():
            parsed_list[str(key)] = {k: v for k, v in value.items()}
        return parsed_list

def check_dict(dict):
    for tmp in dict:
        if tmp != 0:
            return False
    return True

def comp_obj(obj_list, player_tile):
    tmp = obj_list
    for element in player_tile:
        if element in obj_list:
            if tmp[element] == 0:
                continue
            else:
                tmp[element] -= 1
    if check_dict(tmp):
        return True
    return False

def levelUp(obj_list, player_tile):
    if len(obj_list) == 0 or comp_obj(obj_list, player_tile):
        return True
    return False
