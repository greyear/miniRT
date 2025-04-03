# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azinchen <azinchen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/19 12:03:15 by azinchen          #+#    #+#              #
#    Updated: 2025/01/20 18:22:39 by azinchen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Standard
NAME 			=	libft.a

# Directories
INCLUDE_DIR 	=	include/
SRC_DIR 		=	src/
OBJ_DIR 		=	obj/

# Compiler and compilation flags
CC 				=	cc
CFLAGS 			=	-Wall -Wextra -Werror -I
RM				=	rm -f
AR				=	ar rcs

# Source files
FTIS_DIR		=	$(SRC_DIR)ft_is/ft_isalnum.c \
					$(SRC_DIR)ft_is/ft_isalpha.c \
					$(SRC_DIR)ft_is/ft_isascii.c \
					$(SRC_DIR)ft_is/ft_isdigit.c \
					$(SRC_DIR)ft_is/ft_isprint.c \
					$(SRC_DIR)ft_is/ft_issign.c \
					$(SRC_DIR)ft_is/ft_isspace.c \
					$(SRC_DIR)ft_is/ft_isquote.c \
					$(SRC_DIR)ft_is/ft_isemptystring.c
				
FTLST_DIR		=	$(SRC_DIR)ft_lst/ft_lstadd_back.c \
					$(SRC_DIR)ft_lst/ft_lstadd_front.c \
					$(SRC_DIR)ft_lst/ft_lstclear.c \
					$(SRC_DIR)ft_lst/ft_lstdelone.c \
					$(SRC_DIR)ft_lst/ft_lstiter.c \
					$(SRC_DIR)ft_lst/ft_lstlast.c \
					$(SRC_DIR)ft_lst/ft_lstmap.c \
					$(SRC_DIR)ft_lst/ft_lstnew.c \
					$(SRC_DIR)ft_lst/ft_lstsize.c

FTMEM_DIR		=	$(SRC_DIR)ft_mem/ft_bzero.c \
					$(SRC_DIR)ft_mem/ft_calloc.c \
					$(SRC_DIR)ft_mem/ft_memchr.c \
					$(SRC_DIR)ft_mem/ft_memcmp.c \
					$(SRC_DIR)ft_mem/ft_memcpy.c \
					$(SRC_DIR)ft_mem/ft_memmove.c \
					$(SRC_DIR)ft_mem/ft_memset.c
				
FTPUT_DIR		=	$(SRC_DIR)ft_put/ft_putchar_fd.c \
					$(SRC_DIR)ft_put/ft_putendl_fd.c \
					$(SRC_DIR)ft_put/ft_putnbr_fd.c \
					$(SRC_DIR)ft_put/ft_putstr_fd.c
				
FTSTR_DIR		=	$(SRC_DIR)ft_str/ft_split.c \
					$(SRC_DIR)ft_str/ft_strchr.c \
					$(SRC_DIR)ft_str/ft_strrchr.c \
					$(SRC_DIR)ft_str/ft_strdup.c \
					$(SRC_DIR)ft_str/ft_striteri.c \
					$(SRC_DIR)ft_str/ft_strjoin.c \
					$(SRC_DIR)ft_str/ft_strcat.c \
					$(SRC_DIR)ft_str/ft_strlcat.c \
					$(SRC_DIR)ft_str/ft_strcpy.c \
					$(SRC_DIR)ft_str/ft_strncpy.c \
					$(SRC_DIR)ft_str/ft_strlcpy.c \
					$(SRC_DIR)ft_str/ft_strlen.c \
					$(SRC_DIR)ft_str/ft_strmapi.c \
					$(SRC_DIR)ft_str/ft_strcmp.c \
					$(SRC_DIR)ft_str/ft_strncmp.c \
					$(SRC_DIR)ft_str/ft_strnstr.c \
					$(SRC_DIR)ft_str/ft_strtrim.c \
					$(SRC_DIR)ft_str/ft_substr.c
				
FTTO_DIR		=	$(SRC_DIR)ft_to/ft_atoi.c \
					$(SRC_DIR)ft_to/ft_atoi_hexa.c \
					$(SRC_DIR)ft_to/ft_itoa.c \
					$(SRC_DIR)ft_to/ft_tolower.c \
					$(SRC_DIR)ft_to/ft_toupper.c
				
FTPRINTF_DIR	=	$(SRC_DIR)ft_printf/ft_print_char.c \
					$(SRC_DIR)ft_printf/ft_printf.c \
					$(SRC_DIR)ft_printf/ft_print_hexa.c \
					$(SRC_DIR)ft_printf/ft_print_int.c \
					$(SRC_DIR)ft_printf/ft_print_pointer.c \
					$(SRC_DIR)ft_printf/ft_print_str.c \
					$(SRC_DIR)ft_printf/ft_print_unsign.c
				
GNL_DIR			=	$(SRC_DIR)get_next_line/get_next_line.c \
					$(SRC_DIR)get_next_line/get_next_line_utils.c

SRC 			=	$(FTIS_DIR) $(FTLST_DIR) $(FTMEM_DIR) $(FTPUT_DIR) $(FTSTR_DIR) $(FTTO_DIR) $(FTPRINTF_DIR) $(GNL_DIR)

# Object files
OBJ				=	$(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC))

# Colors
BLUE			=	\033[1;34m
GREEN			=	\033[1;32m
NC				=	\033[0m

#Build rules
all:			$(NAME)

$(NAME):		$(OBJ)
				@$(AR) $(NAME) $(OBJ)
				@echo "$(BLUE)Created Libft$(NC)"

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
				@mkdir -p $(@D)
				@$(CC) $(CFLAGS) $(INCLUDE_DIR) -c $< -o $@

clean:
				@$(RM) -r $(OBJ_DIR)
				@$(RM) .cache_exists
		
fclean:			clean 
				@$(RM) $(NAME)
				@echo "$(BLUE)Libft removed!$(NC)"
			
re:				fclean all

.PHONY:			all clean fclean re
