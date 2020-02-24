# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctelma <ctelma@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/26 14:45:43 by ctelma            #+#    #+#              #
#    Updated: 2020/02/09 13:03:37 by ctelma           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -Wall -Werror -Wextra
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS_DIRECTORY)

# LIBFT

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./../libft/

# LIBFT_HEADERS

LIBFT_HEADERS_LIST = \
	libft.h
LIBFT_HEADERS_DIRECTORY = $(LIBFT_DIRECTORY)includes/
LIBFT_HEADERS = $(addprefix $(LIBFT_HEADERS_DIRECTORY), $(LIBFT_HEADERS_LIST))

# LIBFT_SOURCES

LIBFT_SOURCES_DIRECTORY = $(LIBFT_DIRECTORY)
LIBFT_SOURCES_LIST =\
	        ../libft/ft_memset.c ../libft/ft_bzero.c ../libft/ft_memcpy.c ../libft/ft_memccpy.c ../libft/ft_memmove.c \
	        ../libft/ft_memchr.c ../libft/ft_memcmp.c ../libft/ft_strlen.c ../libft/ft_strdup.c ../libft/ft_strcpy.c \
	        ../libft/ft_strncpy.c ../libft/ft_strcat.c ../libft/ft_strncat.c ../libft/ft_strlcat.c ../libft/ft_strchr.c \
	        ../libft/ft_strrchr.c ../libft/ft_strstr.c ../libft/ft_strnstr.c ../libft/ft_strcmp.c ../libft/ft_strncmp.c \
	        ../libft/ft_atoi.c ../libft/ft_isalpha.c ../libft/ft_isdigit.c ../libft/ft_isalnum.c ../libft/ft_isascii.c \
	        ../libft/ft_isprint.c ../libft/ft_toupper.c ../libft/ft_tolower.c \
	        ../libft/ft_memalloc.c ../libft/ft_memdel.c ../libft/ft_strnew.c ../libft/ft_strdel.c ../libft/ft_strclr.c \
	        ../libft/ft_striter.c ../libft/ft_striteri.c ../libft/ft_strmap.c ../libft/ft_strmapi.c ../libft/ft_strequ.c \
	        ../libft/ft_strnequ.c ../libft/ft_strsub.c ../libft/ft_strjoin.c ../libft/ft_strtrim.c ../libft/ft_strsplit.c \
	        ../libft/ft_itoa.c ../libft/ft_putchar.c ../libft/ft_putstr.c ../libft/ft_putendl.c ../libft/ft_putnbr.c \
	        ../libft/ft_putchar_fd.c ../libft/ft_putstr_fd.c ../libft/ft_putendl_fd.c ../libft/ft_putnbr_fd.c \
	        ../libft/ft_lstnew.c ../libft/ft_lstdelone.c ../libft/ft_lstdel.c ../libft/ft_lstadd.c ../libft/ft_lstiter.c \
	        ../libft/ft_lstmap.c \
	        ../libft/ft_islower.c ../libft/ft_isupper.c ../libft/ft_iswhitespace.c ../libft/ft_swap.c ft_sqrt.c \
	        ../libft/ft_recursive_factorial.c ../libft/ft_issymb.c

LIBFT_SOURCES = $(addprefix $(LIBFT_SOURCES_DIRECTORY), $(LIBFT_SOURCES_LIST))

# LIBFT_OBJECTS

LIBFT_OBJECTS_DIRECTORY = $(LIBFT_DIRECTORY)
LIBFT_OBJECTS_LIST = $(patsubst %.c, %.o, $(LIBFT_SOURCES_LIST))
LIBFT_OBJECTS = $(addprefix $(LIBFT_OBJECTS_DIRECTORY), $(LIBFT_OBJECTS_LIST))

# HEADERS

HEADERS_LIST = ft_printf.h

HEADERS_DIRECTORY = ./header/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

# SOURCES

SOURCES_LIST = \
	base.c check_flags.c f.c ft_itoa_u.c hash.c \
	length.c p.c print_base.c rounding.c \
	space_back.c validation.c c.c check_mem.c \
	ft_itoa_base.c ft_print.c initialization.c make_prec.c \
	pre_print.c print_cs.c print_p.c s.c space_forward.c \
	types.c width.c cast_len.c di.c ft_itoa_l.c \
	ft_printf.c len_5_l.c one_space_forward.c precision.c \
	print_diuf.c print_symb.c size_str.c str_w.c u.c check_point_f.c \
	check_inf.c make_color.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

# OBJECTS

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(LIBFT) $(LIBFT_OBJECTS) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@ar rc $(NAME) $(OBJECTS) $(LIBFT_OBJECTS)
	@ranlib $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all
