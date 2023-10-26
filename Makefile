# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martorre <martorre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 14:18:06 by martorre          #+#    #+#              #
#    Updated: 2023/10/26 11:27:10 by martorre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
FLAGS 	= -Wall -Wextra -Werror -I./libft
INCLUDE = push_swap.h
CC = cc
DIR_OBJ = temp/

SOURCES = main.c input_check.c lst_utils.c push.c reverse_rotate.c rotate.c\
swap.c sort_nums.c sort_all.c\

OBJECTS = $(addprefix $(DIR_OBJ), $(SOURCES:.c=.o))

all: temp MAKELIB $(NAME)

temp:
	mkdir -p $(DIR_OBJ)

$(NAME): $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) libft/libft.a -o $(NAME)
	@echo Libft compiled

all_test: temp MAKELIB test

test: $(OBJECTS)
	$(CC)  ./libft/libft.a $(OBJECTS)

MAKELIB:
	$(MAKE) -C ./libft

$(DIR_OBJ)%.o: %.c Makefile $(INCLUDE)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo Compiling $< ...

clean:
	@rm -rf $(DIR_OBJ)
	@echo Deleting all objs

fclean: clean
	@rm -rf $(NAME)
	@echo Deleting all printf

re : fclean all

.PHONY: all clean fclean re