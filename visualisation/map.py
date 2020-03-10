class Map():

    def __init__(self):
        self.width = 0
        self.heigh = 0
        self.map = [[]]

    def read_map(self):
        map_size = input().spit()
        self.heigh = map_size[1]
        self.width = map_size[2]
        skip_line = input()
        for i in range(self.heigh):
            line = input().split()
            for c in line[1]:

