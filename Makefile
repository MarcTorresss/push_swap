# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martorre <martorre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 14:18:06 by martorre          #+#    #+#              #
#    Updated: 2023/11/09 11:39:22 by martorre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
BONUS_NAME = checker
FLAGS 	= -Wall -Wextra -Werror -I./libft
INCLUDE = push_swap.h
CC = cc
DIR_OBJ = temp/
BONUS = bonus
DIR_BONUS = bonus/


SOURCES = main.c input_pushswap.c stack_utils.c push.c reverse_rotate.c rotate.c\
swap.c sort_nums.c sort_all.c sort_utils.c sort_opt.c\

BONUS_FILES = main_bonus.c input_checker_bonus.c stack_utils_bonus.c\
reverse_rotate_bonus.c rotate_bonus.c swap_bonus.c push_bonus.c\

BONUS_SRC = $(addprefix $(DIR_BONUS), $(BONUS_FILES))

OBJ = $(addprefix $(DIR_OBJ), $(SOURCES:.c=.o))

BONUS_OBJ = $(addprefix $(DIR_OBJ), $(BONUS_SRC:.c=.o))


all: temp MAKELIB $(NAME)

temp:
	mkdir -p $(DIR_OBJ)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@echo Push_swap compiled

bonus: temp MAKELIB $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	@$(CC) $(FLAGS) $(BONUS_OBJ) libft/libft.a -o $(BONUS_NAME)
	@echo Checker compiled
	
all_test: temp MAKELIB test

test: $(OBJ)
	$(CC)  ./libft/libft.a $(OBJ)

MAKELIB:
	$(MAKE) -C ./libft

$(DIR_OBJ)%.o: %.c Makefile $(INCLUDE)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo Compiling $< ...

clean:
	@rm -rf $(DIR_OBJ)
	@echo Deleting all objs

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME)
	@echo Deleting all printf

re : fclean all

.PHONY: all clean fclean re