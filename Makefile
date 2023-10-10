# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martorre <martorre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/10 14:18:06 by martorre          #+#    #+#              #
#    Updated: 2023/10/10 14:42:49 by martorre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= push_swap
FLAGS 	= -Wall -Wextra -Werror -I $(INCLUDE)
INCLUDE = push_swap.h
CC = cc
DIR_OBJ = ./temp/

SOURCES = \

OBJECTS = $(addprefix $(DIR_OBJ), $(SOURCES:.c=.o))

all: temp MAKELIB $(NAME)

temp:
	mkdir -p $(DIR_OBJ)

$(NAME): $(OBJECTS)
	@cp ./libft/libft.a $(NAME)
	@$(LIB) $(NAME) $(OBJECTS)
	@echo Libft compiled

all_test: temp MAKELIB test

test: $(OBJECTS)
	$(CC)  ./libft/libft.a $(OBJECTS)

MAKELIB:
	$(MAKE) -C ./libft

$(DIR_OBJ)%.o: %.c Makefile $(INCLUDE)
	@$(CC)  -c $< -o $@
	@echo Compiling $< ...

clean:
	@rm -rf $(DIR_OBJ)
	@echo Deleting all objs

fclean: clean
	@rm -rf $(NAME)
	@echo Deleting all printf

re : fclean all

.PHONY: all clean fclean re