NAME=workshop
CC= c++
GFLAGS= -Werror -Wextra -Wall
LIB= 	-Llibft -lft
SRCS= 	src/ft_ip.cpp \
		src/main.cpp	\
		src/ft_decimal_to_hex.cpp

SRCS_OBJ= $(SRCS:.cpp=.o)
GCOM="default commit message"

$(NAME): $(SRCS_OBJ) $(LIBFT_DIR)
	$(CC) $(GFLAGS) $(SRCS_OBJ) $(LIB) -o $(NAME)

clean:
	rm -f src/*.o

fclean: clean
	rm -f $(NAME)

git: fclean
	git add .
	git commit -m $(GCOM)
	git push origin main