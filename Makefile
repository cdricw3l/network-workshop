NAME=workshop
CC= clang
GFLAGS= -Werror -Wextra -Wall -g
LIB= 	-Llibft -lft
SRCS= 	$(wildcard src/*.c)

SRCS_OBJ= $(SRCS:.cpp=.o)
GCOM="default commit message"

$(NAME): $(SRCS_OBJ) $(LIBFT_DIR)
	$(CC) $(GFLAGS) $(SRCS_OBJ) $(LIB) -o $(NAME)

clean:
	rm -f src/*.o
	rm -rf *.dSYM

fclean: clean
	rm -f $(NAME)
r:
	./$(NAME)

re: fclean $(NAME) r



git: fclean
	git add .
	git commit -m $(GCOM)
	git push origin main

lib:
	cd libft && make bonus && make clean