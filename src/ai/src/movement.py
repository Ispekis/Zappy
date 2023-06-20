import random
import socket
from math import floor
from macro import *

class Movement:
    def __init__(self, client_socket:socket, objectives:list):
        self.cli_socket:socket = client_socket
        self.movementList:list = [FORWARD, FORWARD, RIGHT, LEFT]
        self.preMove:list = []
        self.costList:list = []
        self.objectiveList:list = []
        self.sightIdx:list = []
        self.itemObj:str = None
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
        tmp:int = 1
        sum:int = tmp
        for i in range(8):
            if objective == 0:
                break
            if sum < objective + 1 <= sum + tmp + 2:
                tmp = tmp + 2
                sum = sum + tmp
                for j in range(i + 1):
                    self.preMove.append(FORWARD)
                var = (objective + 1) - (sum - floor(tmp / 2))
                if var < 0:
                    self.preMove.append(LEFT)
                elif var > 0:
                    self.preMove.append(RIGHT)
                for i in range(abs(var)):
                    self.preMove.append(FORWARD)
                break
            tmp = tmp + 2
            sum = sum + tmp

    def getClosest(self, closeList:list, sight:list) -> int:
        tmp:int = min(closeList)
        tmpList:list = []
        tmpObjList:list = []
        for i in range(len(closeList)):
            if closeList[i] == tmp:
                tmpList.append(self.sightIdx[i])
                tmpObjList.append(closeList[i])
        self.sightIdx = tmpList
        tmp = random.choice(self.sightIdx)
        if len(self.preMove) > tmp or len(self.preMove) == 0:
            self.preMove = []
            self.handleObjectives(tmp)
            for i in range(len(self.objectiveList)):
                try:
                    sight[tmp].index(self.objectiveList[i])
                    self.itemObj = self.objectiveList[i]
                    break
                except ValueError:
                    continue

    def getActionCost(self, frequency:list) -> list:
        tmpList:list = []
        for i in range(len(frequency)):
            tmpList.append(self.costList[frequency[i]])
            self.sightIdx.append(frequency[i])
        return tmpList
    
    def itemNotThereAnymore(self, sight:list) -> str:
        inc:int = 0
        if self.preMove.count(LEFT) == 0 and self.preMove.count(RIGHT) == 0 and len(self.preMove) != 0:
            print(self.preMove)
            count:int = self.preMove.count(FORWARD)
            for i in range(1, count + 1):
                inc = inc + (2 * i)
            try:
                sight[inc].index(self.itemObj)
                print("item is still here")
            except ValueError:
                print("item isn't there anymore", inc, self.itemObj, sight, count)
                self.itemObj = None
    
    def handleMovement(self, sight:list) -> str:
        self.sightIdx = []
        liste:list = []
        self.itemNotThereAnymore(sight)
        for i in range(len(sight)):
            for j in range(len(self.objectiveList)):
                try:
                    sight[i].index(self.objectiveList[j])
                    liste.append(i)
                except ValueError:
                    continue
        if len(liste) != 0:
            self.getClosest(self.getActionCost(liste), sight)
            try:
                print(self.preMove)
                tmp:str = self.preMove.pop(0)
            except IndexError:
                self.itemObj = None
                tmp:str = random.choice(self.movementList)
        else:
            self.itemObj = None
            tmp:str = random.choice(self.movementList)
        self.lastMove = tmp
        self.cli_socket.send((tmp + "\n").encode())
        print("The movement is " + tmp)