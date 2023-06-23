from enum import Enum

FAILURE = 1
SUCCESS = 0

NORD = 0
EAST = 1
SOUTH = 3
WEST = 4

FORWARD = "Forward"
LEFT = "Left"
RIGHT = "Right"

# Macro for the broadcast message format

ASK = 0
RESPONSE = 1
LVL = "level"
PLAYER = 0
FOOD = 1
LINEMATE = 2
DERAUMERE = 3
SIBUR = 4
MENDIANE = 5
PHIRAS = 6
THYSTAME = 7

# Macro for the different attitude of the player

NORMAL = 0
ATTACK = 1
REACH_INCANTATION = 2
GIVE_STONE = 3
STEAL_STONE = 4
INCANTATION = 5

items_list = ["food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]
