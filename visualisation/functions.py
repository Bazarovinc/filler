import pygame
from players import Player


def first_input():
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
    return player_1, player_2


def draw_player_info(player_1, player_2, flag, f_s, surface):
    color1 = 'red'
    color2 = 'blue'
    if flag == 1:
        color1 = 'red'
        color2 = 'blue'
    elif flag == -1:
        if player_1.score > player_2.score:
            color1 = 'yellow'
            color2 = 'blue'
        elif player_1.score < player_2.score:
            color1 = 'red'
            color2 = 'yellow'
    font_1 = pygame.font.SysFont("comicsansms", 60)
    name_1 = font_1.render(player_1.printed_name, 1, pygame.Color(color1))
    surface.blit(name_1, (50, 50))
    font_1_1 = pygame.font.SysFont("comicsansms", 60)
    score_1 = font_1_1.render(str(player_1.score), 1, pygame.Color(color1))
    surface.blit(score_1, (50, (name_1.get_height() + 55)))
    font_2 = pygame.font.SysFont("comicsansms", 60)
    name_2 = font_2.render(player_2.printed_name, 1, pygame.Color(color2))
    surface.blit(name_2, (f_s.screen_width - 50 - name_2.get_width(), 50))
    font_2_2 = pygame.font.SysFont("comicsansms", 60)
    score_2 = font_2_2.render(str(player_2.score), 1, pygame.Color(color2))
    surface.blit(score_2, (f_s.screen_width - 50 - score_2.get_width(), (name_2.get_height() + 55)))


def draw_window(surface, filler_settings, map, p1, p2, flag):
    surface.fill(filler_settings.bg_color)
    pygame.font.init()
    font = pygame.font.SysFont("comicsansms", 150)
    label = font.render('FILLER', 1, (0, 153, 0))
    surface.blit(label, (filler_settings.top_left_x + filler_settings.map_width / 2 - (label.get_width() / 2), 30))
    draw_player_info(p1, p2, flag, filler_settings, surface)
    map.draw_map(surface, filler_settings)
    pygame.display.flip()
    

def check_input():
    try:
        s = input()
        return s
    except EOFError:
        return '-1'


def skip_lines():
    piece_size = input().split()
    n = int(piece_size[1])
    for i in range(n):
        s = input()
    s1 = input().split()
    if s1[0] != "<got":
        return 1
