CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -Iinc -Ilibft/inc
SRC     = src/init.c src/main.c src/validate_input.c src/utils.c src/threads.c src/cleanup.c src/routines.c src/monitor.c src/routine_utils.c
OBJ     = $(SRC:src/%.c=obj/%.o)
NAME    = philo

LIBFT_DIR = libft
LIBFT_A   = $(LIBFT_DIR)/libft.a

GREEN   = \033[0;32m
RESET   = \033[0m

all: objdir $(LIBFT_A) $(NAME)
	@echo -e "$(GREEN)Successfully compiled$(RESET)"

objdir:
	@mkdir -p obj

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT_A)

obj/%.o: src/%.c inc/philo.h inc/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f obj/*.o
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	rm -rf obj
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
