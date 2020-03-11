import pygame


def create_grid(locked_positions={}):
    grid = [[(0, 0, 0) for x in range(10)] for x in range(20)]

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            if (j, i) in locked_positions:
                c = locked_positions[(j, i)]
                grid[i][j] = c
    return grid


def draw_grid(surface, grid, f_s):

    for i in range(len(grid)):
        for j in range(len(grid[i])):
            pygame.draw.rect(surface, grid[i][j], (f_s.top_left_x + j * f_s.block_size, f_s.top_left_y + i * f_s.block_size,
                                                    f_s.block_size, f_s.block_size), 0)
    pygame.draw.rect(surface, (255, 0, 0), (f_s.stop_left_x, f_s.top_left_y, f_s.map_width, f_s.map_height), 5)


def draw_window(surface, grid, filler_settings):
    surface.fill(filler_settings.bg_color)
    pygame.font.init()
    font = pygame.font.SysFont('comicsans', 60)
    label = font.render('FILLER', 1, (255, 255, 255))
    surface.blit(label, (filler_settings.top_left_x + filler_settings.play_width / 2 - (label.get_width() / 2), 30))
    draw_grid(surface, grid)
    pygame.display.update()