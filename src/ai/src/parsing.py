def parseLook(look:str):
    tmp:str = look.split(',')
    res = [[]]

    for i in range(len(tmp)):
        v = tmp[i].split()
        res.append(v)
    return res[1:]

def parseInventory(inventory:str):
    tmp = inventory.split(',')
    res = [()]
    for i in range(len(tmp)):
        v = tmp[i].split()
        res.append((v[0], v[1]))
    return res[1:]

def updateNbPlayer(nbPlayer:str):
    return nbPlayer