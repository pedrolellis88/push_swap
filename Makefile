# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pdiniz-l <pdiniz-l@student.42.rio>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/24 11:41:51 by pdiniz-l          #+#    #+#              #
#    Updated: 2025/12/01 15:33:34 by pdiniz-l         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

LIBFT_DIR = ./libft_applier
LIBFT = libft.a

INCLUDES = -I./include -I$(LIBFT_DIR)

MY_SOURCES = srcs/create_head_with_ints.c \
	     srcs/parse_args.c \
	     srcs/error_and_exit.c \
	     srcs/is_str_valid.c \
	     srcs/is_doubled.c \
	     srcs/main.c \
	     srcs/safe_atoi.c \
	     srcs/swap_utils.c \
	     srcs/push_utils.c \
	     srcs/rotate_utils.c \
	     srcs/reverse_rotate_utils.c \
	     srcs/indexing1.c \
	     srcs/indexing2.c \
	     srcs/is_list_sorted.c \
	     srcs/two_three_five_sort_utils.c \
	     srcs/sort_five_especific_utils.c \
	     srcs/chunk_sort.c    
	     


MY_OBJECTS = $(MY_SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(MY_OBJECTS)
	$(CC) $(CFLAGS) $(MY_OBJECTS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(MY_OBJECTS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
