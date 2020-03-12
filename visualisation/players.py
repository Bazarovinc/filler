class Player():

    def __init__(self, player_name):
        self.player_name = player_name
        self.player_number = 0
        self.score = 0
        self.printed_name = self.make_name()
        self.player_symb = ''

    def make_name(self):
        line = self.player_name.split(".")
        name = line[1]
        return name[1:]

    def get_number_of_player(self, n):
        self.player_number = int(n)
        self.choose_symb()

    def choose_symb(self):
        if self.player_number == 1:
            self.player_symb = 'oO'
        elif self.player_number == 2:
            self.player_symb = 'xX'


