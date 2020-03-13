import pygame
import functions as f

class Map():

    def __init__(self, rows, columns):
        self.rows = rows
        self.columns = columns
        self.map = self.make_map()

    def make_map(self):
        return [[0 for j in range(self.columns)] for i in range(self.rows)]

    def draw_map(self, surface, f_s):
        for i in range(self.rows):
            pygame.draw.line(surface, pygame.Color("grey"), [f_s.top_left_x, f_s.top_left_y + i * f_s.block_size],
                             [f_s.top_left_x + f_s.block_size * f_s.columns, f_s.top_left_y + i * f_s.block_size],
                             1)
            for j in range(self.columns):
                if self.map[i][j] == 0:
                    color = "black"
                elif self.map[i][j] == 1:
                    color = "red"
                elif self.map[i][j] == -1:
                    color = (255, 102, 102)
                elif self.map[i][j] == -2:
                    color = (102, 102, 255)
                elif self.map[i][j] == 2:
                    color = "blue"
                if color in ["black", "red", "blue"]:
                    pygame.draw.rect(surface, pygame.Color(color), (f_s.top_left_x + j * f_s.block_size + 1,
                                                                      f_s.top_left_y + i * f_s.block_size + 1,
                                                                      f_s.block_size,
                                                                      f_s.block_size), 0)
                else:
                    pygame.draw.rect(surface, color, (f_s.top_left_x + j * f_s.block_size + 1,
                                                                    f_s.top_left_y + i * f_s.block_size + 1,
                                                                    f_s.block_size,
                                                                    f_s.block_size), 0)
                pygame.draw.line(surface, pygame.Color("grey"), [f_s.top_left_x + j * f_s.block_size, f_s.top_left_y],
                                 [f_s.top_left_x + j * f_s.block_size, f_s.top_left_y + f_s.block_size * f_s.rows])

        #pygame.draw.rect(surface, pygame.Color("white"),
                         #(f_s.top_left_x, f_s.top_left_y, f_s.map_width, f_s.map_height), 5)

    def read_map(self, flag, player_1, player_2):
        if flag == 0:
            skip = 1
        elif flag == 1:
            skip = 2
        while skip != 0:
            s = f.check_input()
            if s == '-1':
                return -1
            if "==" in s:
                return 0
            if "Piece" in s:
                size = s.split()
                for i in range(int(size[1]) + 3):
                    s = input()
                skip = 1
            skip -= 1
        player_1.flag_put = True
        player_2.flag_put = True
        for i in range(self.rows):
            line = input().split()
            if int(line[0]) == i:
                for j in range(len(line[1])):
                    if line[1][j] == '.':
                        self.map[i][j] = 0
                    elif line[1][j] in player_1.player_symb:
                        if line[1][j] == player_1.player_symb[0]:
                            self.map[i][j] = -1
                            if player_1.flag_put:
                                player_1.score += 1
                                player_1.flag_put = False
                        else:
                            self.map[i][j] = 1
                    elif line[1][j] in player_2.player_symb:
                        if line[1][j] == player_2.player_symb[0]:
                            self.map[i][j] = -2
                            if player_2.flag_put:
                                player_2.score += 1
                                player_2.flag_put = False
                        else:
                            self.map[i][j] = 2
        return 1








