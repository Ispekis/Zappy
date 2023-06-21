INV_LEN = 7

def parseLook(look:str):
    tmp:str = look.split(',')
    res = [[]]

    for i in range(len(tmp)):
        v = tmp[i].split()
        res.append(v)
    return res[1:]

def parseInventory(inventory:str):
    tmp = inventory.split(',')
    res = {}
    if len(tmp) != INV_LEN:
        return res
    for i in range(len(tmp)):
        v = tmp[i].split()
        res[v[0]] = int(v[1])
    return res

def updateNbPlayer(nbPlayer:str):
    return nbPlayer