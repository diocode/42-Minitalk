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
DEPS = includes/minitalk.h

SRC_S = src/server.c
OBJ_S = src/server.o
SRC_C = src/client.c
OBJ_C = src/client.o

BONUS_SR_S = src/server_bonus.c
BONUS_OBJ_S = src/server_bonus.o
BONUS_SR_C = src/client_bonus.c
BONUS_OBJ_C = src/client_bonus.o

LIBFT  = libs/libft/libft.a

all: $(OBJ_S) $(OBJ_C) $(DEPS)
	$(MAKE) -C ./libs/libft
	@$(CC) $(OBJ_S) $(LIBFT)  -o server
	@$(CC) $(OBJ_C) $(LIBFT) -o client

bonus: $(BONUS_OBJ_C) $(BONUS_OBJ_S) $(DEPS)
	$(MAKE) -C ./libs/libft
	@$(CC) $(BONUS_OBJ_S) $(LIBFT)  -o server_bonus
	@$(CC) $(BONUS_OBJ_C) $(LIBFT) -o client_bonus

clean:
	$(MAKE) clean -C ./libs/libft
	@rm -rf $(OBJ_C) $(OBJ_S) $(BONUS_OBJ_C) $(BONUS_OBJ_S)

fclean: clean
	$(MAKE) fclean -C ./libs/libft
	@rm -rf libft.a server client server_bonus client_bonus

re: fclean all
	$(MAKE) re -C ./libs/libft

