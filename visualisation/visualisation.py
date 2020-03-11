from os import path
from typing import Union
from players import Player
from button import Button
from settings import Settings
import functions as f


import pygame
import os
import sys

def first_input():
    """In this function checks the right filler_vm header.
        Inputs the players name and initializing the objects player_1 and player_2 of class Player"""
    s = ["# -------------- VM  version 1.1 ------------- #",
         "#                                              #",
         "# 42 / filler VM Developped by: Hcao - Abanlin #",
         "#                                              #",
         "# -------------------------------------------- #"]
    for i in s:
        str = input()
        if i != str:
            return False
    p1 = input().split()
    if p1[0] != "launched":
        return False
    player_1 = Player(p1[1])  # Initialise the player_1 name and object
    s1 = input()
    s1_check = "$$$ exec p1 : [" + player_1.player_name + "]"
    player_1.get_number_of_player(s1_check[10])
    if s1_check != s1:
        return False
    p2 = input().split()
    if p2[0] != "launched":
        return False
    player_2 = Player(p2[1])  # Initialise the player_1 name and object
    s2 = input()
    s2_check = "$$$ exec p2 : [" + player_2.player_name + "]"
    if s2_check != s2:
        return False
    return True


def create_grid(f_s, locked_positions={}):
    grid = [[(0, 0, 0) for x in range(int(f_s.map_width / f_s.block_size))] for x in range(int(f_s.map_width / f_s.block_size))]

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if (j, i) in locked_positions:
                c = locked_positions[(j, i)]
                grid[i][j] = c
    return grid


def draw_grid(surface, grid, f_s):

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            pygame.draw.rect(surface, grid[i][j], (f_s.top_left_x + j * f_s.block_size + 1, f_s.top_left_y + i * f_s.block_size + 1,
                                                    f_s.block_size, f_s.block_size), 0)
    pygame.draw.rect(surface, pygame.Color("green"), (f_s.top_left_x, f_s.top_left_y, f_s.map_width, f_s.map_height), 5)


def draw_window(surface, grid, filler_settings):
    surface.fill(filler_settings.bg_color)
    pygame.font.init()
    font = pygame.font.SysFont('comicsans', 60)
    label = font.render('FILLER', 1, (255, 0, 0))
    surface.blit(label, (filler_settings.top_left_x + filler_settings.map_width / 2 - (label.get_width() / 2), 30))
    draw_grid(surface, grid, filler_settings)
    pygame.display.update()

def run_game():
    settings = Settings()
    win = pygame.display.set_mode((settings.screen_width, settings.screen_height))
    locked_positions = {}  # (x,y):(255,0,0)
    grid = create_grid(settings, locked_positions)
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
        draw_window(win, grid, settings)


run_game()