import random
from macro import *
import sys

LEVEL1 = [("linemate", 1)]
LEVEL2 = [("linemate", 1), ("deraumere", 1), ("sibur", 1)]

class Movement:
    def __init__(self):
        self.movementList:list = [FORWARD, FORWARD, RIGHT, LEFT]
        self.preMove:str = None
    
    def handleObjectives(self, objective:int) -> int:
        return 0
    
    def getActionCost(self, frequency:list) -> int:
        return 0
    
    def handleMovement(self, sight:str) -> str:
        if (self.preMove != None):
            tmp = self.preMove
            self.preMove = None
            return tmp
        liste:list = []
        for i in range(len(sight)):
            if sight[i].find(LEVEL1[0][0]) != -1:
                liste.append(i)
        if (len(liste) != 0):
            return self.handleObjectives()
        tmp:str = random.choice(self.movementList)
        return tmp