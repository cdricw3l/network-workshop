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
	make -C libft clean
	rm -f src/*.o
	rm -rf *.dSYM

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

r: $(NAME)
	@./$(NAME)

re: fclean $(NAME) r

lib:
	make -C libft bonus
	make -C libft clean

git: fclean
	git add .
	git commit -m $(GCOM)
	git push $(shell git branch --show-current)

