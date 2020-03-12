from os import path
from typing import Union
from players import Player
from map import Map
from button import Button
from settings import Settings
import functions as f


import pygame
import os
import sys


def run_game():
    map_size = input().split()
    settings = Settings(map_size[1], map_size[2][:2])
    map = Map(settings.rows, settings.columns)
    win = pygame.display.set_mode((settings.screen_width, settings.screen_height))
    clock = pygame.time.Clock()
    run = True
    pygame.display.set_caption("Filler")
    while run:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            if event.type == pygame.K_q:
                run = False
                sys.exit()
        f.draw_window(win, settings, map)


if f.first_input():
    run_game()
