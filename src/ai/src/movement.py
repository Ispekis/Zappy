import random
import socket
from macro import *

LEVEL1 = [("linemate", 1)]
LEVEL2 = [("linemate", 1), ("deraumere", 1), ("sibur", 1)]

class Movement:
    def __init__(self, client_socket:socket, objectives:list):
        self.cli_socket:socket = client_socket
        self.movementList:list = [FORWARD, FORWARD, RIGHT, LEFT]
        self.preMove:str = ""
        self.costList:list = []
        self.objectiveList:list = []
        for i in range(9):
            for n in range(i):
                self.costList.append((i * 2) + 1 - n)
            self.costList.append(i)
            for n in range(i, 0, -1):
                self.costList.append((i * 2) + 1 - (n - 1))
        self.setObjectivesList(objectives)

    def setObjectivesList(self, objectives:list):
        self.objectiveList = objectives

    def handleObjectives(self, objective:int) -> int:
        return "Forward"

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
        return random.choice(nbrOfLowest)

    def getActionCost(self, frequency:list) -> list:
        tmpList:list = []
        for i in range(len(frequency)):
            tmpList.append(self.costList[frequency[i]])
        return tmpList
    
    def handleMovement(self, sight:list) -> str:
        if self.preMove != "":
            tmp = self.preMove
            self.preMove = ""
            return tmp
        liste:list = []
        for i in range(len(sight)):
            for j in range(len(self.objectiveList)):
                try:
                    sight[i].index(self.objectiveList[j])
                    liste.append(i)
                except ValueError:
                    continue
        if len(liste) != 0:
            tmp:str = self.handleObjectives(self.getClosest(self.getActionCost(liste)))
        else:
            tmp:str = random.choice(self.movementList)
        self.cli_socket.send((tmp + "\n").encode())
        print(tmp)