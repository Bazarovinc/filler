import pygame
from players import Player

def draw_window(surface, filler_settings, map):
    surface.fill(filler_settings.bg_color)
    pygame.font.init()
    font = pygame.font.SysFont("comicsansms", 60)
    label = font.render('FILLER', 1, (255, 0, 0))
    surface.blit(label, (filler_settings.top_left_x + filler_settings.map_width / 2 - (label.get_width() / 2), 30))
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


