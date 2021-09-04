NAME = philo
FLAGS = -Wall -Wextra -Werror

SRC =		./main.c \
			./ft_atoi.c \
			./ft_isdigit.c \
			./ft_print.c \
			./ft_strlen.c \
			./ft_time.c \
			./my_usleep.c \
			./ft_check_de_and_stop.c \
			./parser.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $^ -o $(NAME)

%.o: %.c philo.h
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all