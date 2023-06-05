from player import Player

class Team:
    def __init__(self, nb_player):
        self.nb_player = nb_player
        self.player_info = self.init_all_player()

    def init_all_player(self):
        for i in range(self.nb_player):
            tmp = Player()
            print(f'{tmp.food}')
