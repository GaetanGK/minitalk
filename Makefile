SERVER   = server

CLIENT   = client

CC	     = gcc $(FLAGS)

FLAGS    = -Wall -Werror -Wextra

SERVER_SRC = src/server.c src/utils.c src/utils1.c

CLIENT_SRC = src/client.c src/utils.c src/utils1.c

SERVER_SRC_OBJ	= $(SERVER_SRC:.c=.o)

CLIENT_SRC_OBJ	= $(CLIENT_SRC:.c=.o)

all : $(CLIENT) $(SERVER)
$(CLIENT) : ${CLIENT_SRC_OBJ}
	${CC} $(CFLAGS) -o $(CLIENT) $(CLIENT_SRC_OBJ)
$(SERVER) : ${SERVER_SRC_OBJ}
	${CC} $(CFLAGS) -o $(SERVER) $(SERVER_SRC_OBJ)


clean :
	@rm -rf ./src/*.o ./bonus/*.o

fclean: clean
	@rm -rf $(SERVER) $(CLIENT) $(CLIENT_BONUS) $(SERVER_BONUS)

re: fclean all

.PHONY : bonus all clean fclean