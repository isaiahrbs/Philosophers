CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -Iinc
SRC     = src/init.c src/main.c src/validate_input.c src/utils.c src/threads.c src/cleanup.c src/routines.c src/monitor.c
OBJ     = $(SRC:src/%.c=obj/%.o)
NAME    = philo

GREEN   = \033[0;32m
RESET   = \033[0m

all: objdir $(NAME)
	@echo -e "$(GREEN)Successfully compiled$(RESET)"

objdir:
	@mkdir -p obj

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

obj/%.o: src/%.c inc/philo.h inc/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f obj/*.o

fclean: clean
	rm -f $(NAME)
	rm -rf obj

re: fclean all

.PHONY: all clean fclean re