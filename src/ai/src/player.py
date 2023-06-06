from macro import *

class Player:
    def __init__(self, team):
        self.team = team
        self.orientation = NORD
        self.level = 0

        # Invetaire
        self.food = 1260
        self.linemate = 0
        self.deraumere = 0
        self.sibur = 0
        self.mendiane = 0
        self.phiras = 0
        self.thystame = 0
