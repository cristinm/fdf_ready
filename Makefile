# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cristinm <cristinm@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/01 14:52:01 by cristinm          #+#    #+#              #
#    Updated: 2024/08/24 18:46:04 by cristinm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = src/adjust.c src/allocate.c src/cleanup.c src/draw_iso_grid.c \
	src/draw.c src/hooks.c src/initialize.c src/limits.c src/main.c \
	src/map_check.c src/map_color.c src/map_cols_rows.c src/map_process.c \
	src/map_buffer.c
OBJS = $(SRC:.c=.o)
CC = gcc
CFLAGS = 
MLX_DIR = ./mlx
MLX_LIB = $(MLX_DIR)/libmlx_linux.a
LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
FT_PRINTF_DIR = ./ft_printf
FT_PRINTF_LIB = $(FT_PRINTF_DIR)/libftprintf.a
INCLUDES = -I/usr/include -Imlx -I$(LIBFT_DIR) -I$(FT_PRINTF_DIR)
MLX_FLAGS = -Lmlx -lmlx -L$(LIBFT_DIR) -lft -L$(FT_PRINTF_DIR) -lftprintf -lXext -lX11 -lm
VALGRIND = valgrind --leak-check=full --show-leak-kinds=all

all: $(MLX_LIB) $(LIBFT_LIB) $(FT_PRINTF_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT_LIB):
	@make -C $(LIBFT_DIR)

$(FT_PRINTF_LIB):
	@make -C $(FT_PRINTF_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(MLX_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(FT_PRINTF_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(FT_PRINTF_DIR)

re: fclean all

leaks: all clean
	$(VALGRIND) ./$(NAME) maps/42.fdf

.PHONY: all clean fclean re leaks

