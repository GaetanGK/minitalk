SERVER   = server

CLIENT   = client

SERVER_BONUS   = server_bonus

CLIENT_BONUS   = client_bonus

CC	     = gcc $(FLAGS)

FLAGS    = -Wall -Werror -Wextra -fsanitize=address

SERVER_SRC = src/server.c src/utils.c src/utils1.c

CLIENT_SRC = src/client.c src/utils.c src/utils1.c

SERVER_BONUS_SRC = src/server_bonus.c src/utils.c src/utils1.c

CLIENT_BONUS_SRC = src/client_bonus.c src/utils.c src/utils1.c

SERVER_SRC_OBJ	= $(SERVER_SRC:.c=.o)

CLIENT_SRC_OBJ	= $(CLIENT_SRC:.c=.o)

SERVER_BONUS_SRC_OBJ	= $(SERVER_BONUS_SRC:.c=.o)

CLIENT_BONUS_SRC_OBJ	= $(CLIENT_BONUS_SRC:.c=.o)

all : $(CLIENT) $(SERVER)
$(CLIENT) : ${CLIENT_SRC_OBJ}
	${CC} $(CFLAGS) -o $(CLIENT) $(CLIENT_SRC_OBJ)
$(SERVER) : ${SERVER_SRC_OBJ}
	${CC} $(CFLAGS) -o $(SERVER) $(SERVER_SRC_OBJ)

bonus : $(CLIENT_BONUS) $(SERVER_BONUS)
$(CLIENT_BONUS) : ${CLIENT_BONUS_SRC_OBJ}
		${CC} $(CFLAGS) -o $(CLIENT_BONUS) $(CLIENT_BONUS_SRC_OBJ)
$(SERVER_BONUS) : ${SERVER_BONUS_SRC_OBJ}
		${CC} $(CFLAGS) -o $(SERVER_BONUS) $(SERVER_BONUS_SRC_OBJ)
clean :
	@rm -rf ${CLIENT_SRC_OBJ} ${SERVER_SRC_OBJ} ${CLIENT_BONUS_SRC_OBJ} ${SERVER_BONUS_SRC_OBJ} 

fclean: clean
	@rm -rf $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY : bonus all clean fclean re