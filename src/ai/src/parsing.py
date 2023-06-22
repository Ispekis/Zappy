INV_LEN = 7

def parseLook(look:str) -> list:
    """Parse the vision array sent by the server

    Args:
        look (str): look being the vision sent by the server

    Returns:
        list: return the parsed vision array
    """
    tmp:str = look.split(',')
    res = [[]]

    for i in range(len(tmp)):
        v = tmp[i].split()
        res.append(v)
    return res[1:]

def parseInventory(inventory:str) -> list:
    """Parse the inventory array sent by the server

    Args:
        inventory (str): array for the inventory sent by the server

    Returns:
        list: return the parsed inventory list
    """
    tmp = inventory.split(',')
    res = {}
    if len(tmp) != INV_LEN:
        return res
    for i in range(len(tmp)):
        v = tmp[i].split()
        res[v[0]] = int(v[1])
    return res

def updateNbPlayer(nbPlayer:str) -> int:
    """Update the number of player

    Args:
        nbPlayer (str): new number of player
    Returns:
        int: number of player
    """
    return nbPlayer