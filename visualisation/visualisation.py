from players import Player
from map import Map
from settings import Settings
import functions as f
import pygame
import os
import sys


def run_game(player_1, player_2):
    flag = 0
    map_size = input().split()
    settings = Settings(map_size[1], map_size[2][:2])
    map = Map(settings.rows, settings.columns)
    map.read_map(flag, player_1, player_2)
    f.skip_lines()
    win = pygame.display.set_mode((settings.screen_width, settings.screen_height))
    pygame.display.set_caption("Filler")
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.key == pygame.K_ESCAPE:
                    sys.exit()
                elif event.key == pygame.K_SPACE:
                    if flag == 1:
                        flag = 0
                    elif flag == 0:
                        flag = 1
        f.draw_window(win, settings, map, player_1, player_2, flag)
        if flag == 1:
            flag = map.read_map(flag, player_1, player_2)
        if flag == 1:
            f.skip_lines()


p1, p2 = f.first_input()
run_game(p1, p2)
