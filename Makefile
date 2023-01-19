# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: digoncal <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/19 11:01:17 by digoncal          #+#    #+#              #
#    Updated: 2023/01/19 15:31:32 by digoncal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
DEPS = minitalk.h

SRC_S = server.c
OBJ_S = server.o
SRC_C = client.c
OBJ_C = client.o

BONUS_SR_S = server_bonus.c
BONUS_OBJ_S = server_bonus.o
BONUS_SR_C = client_bonus.c
BONUS_OBJ_C = client_bonus.o

LIBFT  = libft/libft.a

all: $(OBJ_S) $(OBJ_C) $(DEPS)
	$(MAKE) -C ./libft
	@$(CC) $(OBJ_S) $(LIBFT)  -o server
	@$(CC) $(OBJ_C) $(LIBFT) -o client

bonus: $(BONUS_OBJ_C) $(BONUS_OBJ_S) $(DEPS)
	$(MAKE) -C ./libft
	@$(CC) $(BONUS_OBJ_S) $(LIBFT)  -o server_b
	@$(CC) $(BONUS_OBJ_C) $(LIBFT) -o client_b

clean:
	$(MAKE) clean -C ./libft
	@rm -rf $(OBJ_C) $(OBJ_S) $(BONUS_OBJ_C) $(BONUS_OBJ_S)

fclean: clean
	$(MAKE) fclean -C ./libft
	@rm -rf libft.a server client server_b client_b

re: fclean all
	$(MAKE) re -C ./libft

