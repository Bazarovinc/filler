import pygame

class Settings():

    def __init__(self, rows, columns):
        self.screen_width = 1800
        self.screen_height = 1000
        self.bg_color = 224, 224, 224
        self.rows = int(rows)
        self.columns = int(columns)
        self.block_size = 0
        self.map_width = 0
        self.map_height = 0
        self.make_map()
        self.top_left_x = (self.screen_width - self.map_width) // 2
        self.top_left_y = self.screen_height - self.map_height

    def make_map(self):
        if self.rows == 15:
            self.block_size = 45
            self.map_width = self.block_size * self.columns
            self.map_height = self.block_size * self.rows
        elif self.rows == 24:
            self.block_size = 30
            self.map_width = self.block_size * self.columns
            self.map_height = self.block_size * self.rows
        elif self.rows == 100:
            self.block_size = 8
            self.map_width = self.block_size * self.columns + 3
            self.map_height = self.block_size * self.rows + 3
