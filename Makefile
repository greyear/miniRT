# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msavelie <msavelie@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 16:27:22 by azinchen          #+#    #+#              #
#    Updated: 2025/04/09 11:39:17 by msavelie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

# Standard
NAME 			=	miniRT

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
SRC				=	$(SRC_DIR)/main.c

# Object files
OBJ 			=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

#Build rules
all: 			$(NAME)

$(LIBFT):
				@echo "$(CYAN)🛠  Compiling libft... 🛠$(DEF_COLOR)"
				@make -C ./libft --no-print-directory

$(MLX42):
				@echo "$(CYAN)🛠  Compiling mlx... 🛠$(DEF_COLOR)"
				@touch .mlx
				@git clone https://github.com/codam-coding-college/MLX42.git ${MLX_DIR}
				@cmake $(MLX_DIR) -B $(MLX_DIR)/build
				@cmake --build $(MLX_DIR)/build -j4

$(NAME): 		$(MLX42) $(LIBFT) $(OBJ)
				@echo "$(MAGENTA)🪄 Compiling miniRT... 🪄$(DEF_COLOR)"
				@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(HEADERS) $(LIB) -o $(NAME)
				@echo "$(GREEN)🥳 Success!🥳$(DEF_COLOR)"

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INCLUDE_DIR) -Imlx -c $< -o $@

clean:
				@echo "$(YELLOW)🧹 Deleting object files in libft dir... 🧹$(DEF_COLOR)"
				@make clean -C ./libft --no-print-directory
				@echo "$(YELLOW)🧹 Deleting object files... 🧹$(DEF_COLOR)"
				@$(RM) -rf $(OBJ_DIR)
				@$(RM) .cache_exists
		
fclean: 		clean 
				@echo "$(RED)🧽 Deleting libft... 🧽$(DEF_COLOR)"
				@$(RM) $(LIBFT)
				@echo "$(RED)🧽 Deleting mlx... 🧽$(DEF_COLOR)"
				@$(RM) -rf $(MLX_DIR)
				@$(RM) .mlx
				@echo "$(RED)🧽 Deleting miniRT... 🧽$(DEF_COLOR)"
				@$(RM) $(NAME)
				@echo "$(RED)☣️  CLEAR ☣️$(DEF_COLOR)"
			
re: 			fclean all

.PHONY: 		all clean fclean re