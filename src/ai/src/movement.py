import random
from macro import *
import sys
import math

LEVEL1 = [("linemate", 1)]
LEVEL2 = [("linemate", 1), ("deraumere", 1), ("sibur", 1)]

class Movement:
    def __init__(self, objectives:list):
        self.movementList:list = [FORWARD, FORWARD, RIGHT, LEFT]
        self.preMove:str = None
        self.costList:list = []
        self.objectiveList:list = []
        for i in range(9):
            for n in range(i):
                self.costList.append((i * 2) + 1 - n)
            self.costList.append(i)
            for n in range(i, 0, -1):
                self.costList.append((i * 2) + 1 - (n - 1))
        print(self.costList)

    def setObjectivesList(self, objectives:list):
        for i in len(objectives):
            for j in range(objectives[i][1]):
                self.objectivesList.append(objectives[i][0])

    def handleObjectives(self, objective:int) -> int:
        return 0
    
    def handleSameCostObjectives(self, ):
    
    def getClosest(self, closeList:list) -> int:
        tmp:int = min(closeList)
        nbrOfLowest:list = []
        inc:int = -1
        while True:
            try:
                nbrOfLowest.append(closeList.index(tmp, inc + 1))
            except ValueError:
                break
        if len(nbrOfLowest) == 1:
            return tmp
        if len(self.objectiveList) < 2:
            return tmp
        return 
    
    def getActionCost(self, frequency:list) -> list:
        tmpList:list = []
        for i in len(frequency):
            tmpList.append(frequency[i])
        return tmpList
    
    def handleMovement(self, sight:str, cli_sock, player_lever:int) -> str:
        if self.preMove != None:
            tmp = self.preMove
            self.preMove = None
            return tmp
        liste:list = []
        for i in range(len(sight)):
            for j in range(len(self.objectiveList)):
                try:
                    if sight[i].find(self.objectiveList[j]) != -1:
                        liste.index(self.objectiveList[j])
                    continue
                except:
                    liste.append(i)
        if len(liste) != 0:
            self.handleObjectives(self.getClosest(self.getActionCost(liste)))
        tmp:str = random.choice(self.movementList)
        return tmp