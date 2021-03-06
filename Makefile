# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/06 16:25:01 by ctelma            #+#    #+#              #
#    Updated: 2020/03/17 11:53:22 by ctelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ctelma.filler

CC = gcc

FLAG = -Wall -Wextra -Werror

FLAGINC = -I

PATH_LIB = ./libft/

HEADER = filler.h

OBG = src/check_valid.o src/filler.o src/solve.o \
		src/get_next_line.o src/check_1_line.o \
		src/read_map.o src/read_sizes.o src/set_mem.o src/check_last_line.o \
		src/check_mid_lines.o src/ft_min.o src/choose_player.o src/make_map.o \
		src/get_score.o src/stars.o src/clean_memory.o

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: lib $(NAME)

lib:
	@make $(FLAG) -C $(PATH_LIB)

$(NAME): $(OBG)
	@$(CC) -I $(HEADER) -o $(NAME) $(OBG) -L $(PATH_LIB) -lft
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

%.o: %.c %.h
	@$(CC) $(FLAGINC) $(FLAG) -MD -c  $< -o $@

clean:
	@make -C $(PATH_LIB) clean
	@rm -f $(OBG)
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@make -C $(PATH_LIB) fclean
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all