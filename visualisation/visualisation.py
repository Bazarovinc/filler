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


def run_game(player_1, player_2):
    flag = 0
    map_size = input().split()
    settings = Settings(map_size[1], map_size[2][:2])
    map = Map(settings.rows, settings.columns)
    flag = map.read_map(flag, player_1, player_2)
    f.skip_lines()
    win = pygame.display.set_mode((settings.screen_width, settings.screen_height))
    clock = pygame.time.Clock()
    run = True
    pygame.display.set_caption("Filler")
    while run:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()
            elif event.type == pygame.KEYDOWN:
                if event.type == pygame.K_ESCAPE:
                    run = False
                    sys.exit()
        f.draw_window(win, settings, map)
        if flag == 1:
            flag = map.read_map(flag, player_1, player_2)
        if flag == 1:
            f.skip_lines()
        print("1:", player_1.score)
        print("2:", player_2.score)



s = ["# -------------- VM  version 1.1 ------------- #",
     "#                                              #",
     "# 42 / filler VM Developped by: Hcao - Abanlin #",
     "#                                              #",
     "# -------------------------------------------- #"]
for i in s:
    str = input()
    if i != str:
        sys.exit(1)
p1 = input().split()
if p1[0] != "launched":
    sys.exit(1)
player_1 = Player(p1[1])  # Initialise the player_1 name and object
s1 = input()
s1_check = "$$$ exec p1 : [" + player_1.player_name + "]"
player_1.get_number_of_player(s1_check[10])
if s1_check != s1:
    sys.exit(1)
p2 = input().split()
if p2[0] != "launched":
    sys.exit(1)
player_2 = Player(p2[1])  # Initialise the player_1 name and object
s2 = input()
s2_check = "$$$ exec p2 : [" + player_2.player_name + "]"
player_2.get_number_of_player(s2_check[10])
if s2_check != s2:
    sys.exit(1)
run_game(player_1, player_2)
