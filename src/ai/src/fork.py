from player import Player

def check_sight_food(sight):
    food = 0

    for i in sight[3:]:
        for j in sight[i]:
            if j == "food":
                food += 1
    return food

def no_food(sight, food):
    if food < 5 and check_sight_food == 0:
        return True
    return False

def check_nb_player(max_player, team_mate):
    if max_player == 0 and team_mate < 6:
        return False
    return True

def check_if_need_fork(player:Player, sight):
    if check_nb_player(player.nb_player, player.team_mate) or no_food(sight, player.inventory["food"]):
        return True
    return False