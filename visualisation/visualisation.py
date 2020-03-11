from os import path
from typing import Union
from players import Player
from button import Button
from settings import Settings

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


def run_game():
    # Initialise pygame
    pygame.init()
    filler_settings = Settings()
    screen = pygame.display.set_mode((filler_settings.screen_width, filler_settings.screen_height))
    white = pygame.Color(255, 255, 255)
    screen.fill(white)
    pygame.display.set_caption("Filler")
    # Создание кнопки Play
    #play_button = Button(screen, "Start")
    #screen.fill(white)
    for y in range(15):
        for x in range(17):
            rect = pygame.Rect(x * 5 + 1, y * 5 + 1, 5, 5)
            pygame.draw.rect(screen, (255, 0, 0), rect)
    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                sys.exit()



run_game()