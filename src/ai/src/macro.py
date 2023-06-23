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
SIGNAL = 2
LVL = "level"
PLAYER = "player"
FOOD = "food"
LINEMATE = "linemate"
DERAUMERE = "deraumere"
SIBUR = "sibur"
MENDIANE = "mendiane"
PHIRAS = "phiras"
THYSTAME = "thystame"

# Macro for the different attitude of the player

NORMAL = 0
ATTACK = 1
REACH_INCANTATION = 2
REACH_SIGNAL = 3
GIVE_STONE = 4
STEAL_STONE = 5
INCANTATION = 6

items_list = ["food", "linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]
