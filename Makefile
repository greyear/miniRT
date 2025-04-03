# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 16:27:22 by azinchen          #+#    #+#              #
#    Updated: 2024/10/04 17:09:13 by azinchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME 			=	fdf

# Directories
LIBFT_DIR		= 	./libft
MLX_DIR			=	./MLX42
SRC_DIR 		=	./src
OBJ_DIR 		=	./obj

#Includes
LIBFT_INC		=	$(LIBFT_DIR)/include
MLX_INC			=	$(MLX_DIR)/include
INCLUDE 		=	./include/
HEADERS			=	-I$(LIBFT_INC)/libft.h -I$(LIBFT_INC)/get_next_line.h -I$(MLX_INC)

#Libraries
LIBFT			=	$(LIBFT_DIR)/libft.a
MLX42			=	$(MLX_DIR)/build/libmlx42.a
LIB				=	-L$(MLX_DIR)/build -lmlx42 -L$(LIBFT_DIR) -ldl -lglfw -pthread -lm

# Compiler and compilation flags
CC 				=	cc
CFLAGS 			=	-g -Wall -Wextra -Werror
RM				=	rm -f

# Source files
READING_DIR			=	$(SRC_DIR)/reading/read_map.c \
						$(SRC_DIR)/reading/parse.c \
						$(SRC_DIR)/reading/read_utils.c \
						$(SRC_DIR)/reading/checkers.c \
						$(SRC_DIR)/reading/clean_maps.c \
						$(SRC_DIR)/reading/clean_other.c \
						$(SRC_DIR)/reading/errors.c
TRANSFORMING_DIR	= 	$(SRC_DIR)/transforming/rotate.c \
						$(SRC_DIR)/transforming/iso_matrix.c
DRAWING_DIR			=	$(SRC_DIR)/drawing/px_matrix.c \
						$(SRC_DIR)/drawing/draw_line.c \
						$(SRC_DIR)/drawing/draw_utils.c \
						$(SRC_DIR)/drawing/colors.c \
						$(SRC_DIR)/drawing/colors_rgba.c \
						$(SRC_DIR)/drawing/colors_utils.c \
						$(SRC_DIR)/drawing/draw_actions.c \
						$(SRC_DIR)/drawing/bonus_functions.c \
						$(SRC_DIR)/drawing/picture.c
SRC					=	$(READING_DIR) \
						$(TRANSFORMING_DIR) \
						$(DRAWING_DIR) \
						$(SRC_DIR)/main.c

# Object files
OBJ 			=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

#Build rules
all: 			$(NAME)

$(LIBFT):
				@make -C ./libft

$(MLX42):
				@cmake $(MLX_DIR) -B $(MLX_DIR)/build
				@cmake --build $(MLX_DIR)/build -j4

$(NAME): 		$(OBJ) $(LIBFT) $(MLX42)
				$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(HEADERS) $(LIB) -o $(NAME) 

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INCLUDE_DIR) -Imlx -c $< -o $@

clean:
				@$(RM) -r $(OBJ_DIR)
				@$(RM) .cache_exists
				@make clean -C ./libft
		
fclean: 		clean 
				@$(RM) $(NAME)
				@$(RM) $(LIBFT)
				@$(RM) -r $(MLX_DIR)/build
			
re: 			fclean all

.PHONY: 		all clean fclean re

BLUE = \033[1;34m
GREEN = \033[1;32m
NC = \033[0m