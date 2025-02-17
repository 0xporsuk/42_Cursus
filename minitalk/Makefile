NAME_SERVER = server
NAME_CLIENT = client
NAME_SERVER_BONUS = server_bonus
NAME_CLIENT_BONUS = client_bonus

CC = cc
CFLAGS = -Wall -Wextra -Werror

$(NAME_SERVER): server.c minitalk.h
	$(CC) $(CFLAGS) server.c -o $(NAME_SERVER)

$(NAME_CLIENT): client.c minitalk.h
	$(CC) $(CFLAGS) client.c -o $(NAME_CLIENT)

$(NAME_SERVER_BONUS): server_bonus.c minitalk_bonus.h
	$(CC) $(CFLAGS) server_bonus.c -o $(NAME_SERVER_BONUS)

$(NAME_CLIENT_BONUS): client_bonus.c minitalk_bonus.h
	$(CC) $(CFLAGS) client_bonus.c -o $(NAME_CLIENT_BONUS)

all: $(NAME_SERVER) $(NAME_CLIENT)

bonus: $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

clean:
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	rm -f $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)

fclean: clean

re: fclean all

bonus_re: fclean bonus

.PHONY: all clean fclean re bonus bonus_re