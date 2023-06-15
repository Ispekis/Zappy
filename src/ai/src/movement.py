import random
from macro import *
import sys


class Movement:
    def __init__(self):
        self.movementList = [FORWARD, FORWARD, FORWARD, RIGHT, LEFT]
       
    def handleMovement(self):
        tmp = random.choice(self.movementList)
        print(f"{tmp}", file=sys.stderr)
        return tmp