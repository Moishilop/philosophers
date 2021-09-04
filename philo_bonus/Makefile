BONUS = philo_bonus

FLAGS = -Wall -Wextra -Werror

SRC =	./bonus_main.c \
		./ft_atoi.c \
		./ft_isdigit.c \
		./ft_strlen.c \
		./my_usleep.c \
		./l_func.c \
		./print_mes.c \
		./main_liv.c \
		./parser.c

OBJ = $(SRC:.c=.o)

all: $(BONUS)

$(BONUS): $(OBJ)
	gcc $(FLAGS) $^ -o $(BONUS)

%.o: %.c philo.h
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(BONUS)

re: fclean all