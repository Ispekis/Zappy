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
            print(parsed_list)
        return parsed_list