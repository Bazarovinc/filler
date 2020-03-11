import pygame

class Settings():

    def __init__(self):
        self.screen_width = 1800
        self.screen_height = 1000
        self.bg_color = 255, 255, 255
        self.block_size = 30
        self.map_width = 1500
        self.map_height = 700
        self.top_left_x = (self.screen_width - self.map_width) // 2
        self.top_left_y = self.screen_height - self.map_height

