import pygame
from players import Player

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


def draw_window(surface, filler_settings, map):
    surface.fill(filler_settings.bg_color)
    pygame.font.init()
    font = pygame.font.SysFont('dejavuserif', 60)
    label = font.render('FILLER', 1, (255, 0, 0))
    surface.blit(label, (filler_settings.top_left_x + filler_settings.map_width / 2 - (label.get_width() / 2), 30))
    map.draw_map(surface, filler_settings)
    pygame.display.update()
