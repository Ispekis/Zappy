def setobjectif(level):
    levels = [level2, level3, level4, level5, level6, level7, level8]

    for i in range(len(levels)):
        if level == levels[i]:
            return levels[i]()

def level2():
    return [("linemate", 1)]

def level3():
    return [("linemate", 1), ("deraumere", 1), ("sibur", 1)]

def level4():
    return [("linemate", 2), ("sibur", 1), ("phiras", 2)]

def level5():
    return [("linemate", 1), ("deraumere", 1), ("sibur", 2), ("phiras", 1)]

def level6():
    return [("linemate", 1), ("deraumere", 2), ("sibur", 1), ("mendiane", 3)]

def level7():
    return [("linemate", 1), ("deraumere", 2), ("sibur", 3), ("phiras", 1)]

def level8():
    return [("linemate", 2), ("deraumere", 2), ("sibur", 2), ("mendiane", 1), ("phiras", 2), ("thystame", 1)]

