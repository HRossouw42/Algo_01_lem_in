# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hrossouw <hrossouw@42.FR>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/09 13:31:24 by hrossouw          #+#    #+#              #
#    Updated: 2018/09/17 17:32:09 by hrossouw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

 CC = gcc
 CFLAGS = -Wall -Wextra -Werror -I -g
 
 SRC_PATH = src/
 INC_PATH = includes/
 OBJ_PATH = obj/
 LIBFT_PATH = libft/

 SRC_NAME = push_swap_main.c\
			swap_ops.c \
			reverse_ops.c \
			push_ops.c \
			rotate_ops.c \
			visualiser.c \
			get_input.c \
			is_sorted.c \
			algo_start.c \
			print_swap_ops.c \
			print_push_ops.c \
			print_rotate_ops.c \
			algo_len.c \
			algo_tools.c \
			error_check.c \
			get_args.c \
			list_tools.c \
			list_free.c \
			algo_tools_2.c \

SRC_NAME2 = checker_main.c \
			swap_ops.c \
			reverse_ops.c \
			push_ops.c \
			rotate_ops.c \
			visualiser.c \
			get_input.c \
			is_sorted.c \
			algo_start.c \
			print_swap_ops.c \
			print_push_ops.c \
			print_rotate_ops.c \
			algo_len.c \
			algo_tools.c \
			error_check.c \
			get_args.c \
			list_tools.c \
			list_free.c \
			algo_tools_2.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME2 = $(SRC_NAME2:.c=.o)

OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
OBJ2 = $(addprefix $(OBJ_PATH),$(OBJ_NAME2))
INC = $(addprefix -I,$(INC_PATH))
INC_LIBFT = $(addprefix -I, $(addprefix $(LIBFT_PATH), $(INC_PATH)))

all: $(NAME) $(NAME2)

$(NAME): $(OBJ)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L$(LIBFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(INC) $(INC_LIBFT) -o $@ -c $<

$(NAME2): $(OBJ2)
	make -C $(LIBFT_PATH)
	$(CC) $(CFLAGS) -o $@ $(OBJ2) -L$(LIBFT_PATH) -lft

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(INC) $(INC_LIBFT) -o $@ -c $<

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJ_PATH)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	rm -f $(NAME)
	rm -f $(NAME2)

test: $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L$(LIBFT_PATH) -lft

checker: $(OBJ2)
	$(CC) -o $(NAME2) $(OBJ2) -L$(LIBFT_PATH) -lft

re: fclean all

.PHONY: all, $(NAME), clean, fclean, re
