# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irobinso <irobinso@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 11:39:11 by irobinso          #+#    #+#              #
#    Updated: 2024/10/10 11:17:54 by irobinso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler settings
CC = gcc
CFLAGS = -Wall -Werror -Wextra
SRCS_DIR = functions
GNL_DIR = GNL
FT_PRINTF_DIR = ft_printf
OBJ_DIR = obj

# Source files and object files for the main part
SRCS = $(SRCS_DIR)/ft_atoi.c $(SRCS_DIR)/ft_bzero.c $(SRCS_DIR)/ft_calloc.c \
       $(SRCS_DIR)/ft_isalnum.c $(SRCS_DIR)/ft_isalpha.c $(SRCS_DIR)/ft_isascii.c \
       $(SRCS_DIR)/ft_isdigit.c $(SRCS_DIR)/ft_isprint.c $(SRCS_DIR)/ft_memchr.c \
       $(SRCS_DIR)/ft_memcmp.c $(SRCS_DIR)/ft_memcpy.c $(SRCS_DIR)/ft_memmove.c \
       $(SRCS_DIR)/ft_memset.c $(SRCS_DIR)/ft_putchar_fd.c $(SRCS_DIR)/ft_putendl_fd.c \
       $(SRCS_DIR)/ft_putstr_fd.c $(SRCS_DIR)/ft_strchr.c $(SRCS_DIR)/ft_strdup.c \
       $(SRCS_DIR)/ft_putnbr_fd.c $(SRCS_DIR)/ft_strjoin.c $(SRCS_DIR)/ft_strlcat.c \
       $(SRCS_DIR)/ft_strlcpy.c $(SRCS_DIR)/ft_strlen.c $(SRCS_DIR)/ft_striteri.c \
       $(SRCS_DIR)/ft_strnstr.c $(SRCS_DIR)/ft_strrchr.c $(SRCS_DIR)/ft_substr.c \
       $(SRCS_DIR)/ft_itoa.c $(SRCS_DIR)/ft_strmapi.c $(SRCS_DIR)/ft_tolower.c \
       $(SRCS_DIR)/ft_toupper.c $(SRCS_DIR)/ft_strtrim.c $(SRCS_DIR)/ft_strncmp.c \
       $(SRCS_DIR)/ft_split.c $(SRCS_DIR)/ft_atol.c $(SRCS_DIR)/ft_lstnew.c \
       $(SRCS_DIR)/ft_lstadd_front.c $(SRCS_DIR)/ft_lstsize.c $(SRCS_DIR)/ft_lstlast.c \
       $(SRCS_DIR)/ft_lstadd_back.c $(SRCS_DIR)/ft_lstdelone.c $(SRCS_DIR)/ft_lstclear.c \
       $(SRCS_DIR)/ft_lstiter.c $(SRCS_DIR)/ft_lstmap.c $(SRCS_DIR)/ft_strcpy.c \
       $(SRCS_DIR)/ft_strslen.c \
       $(FT_PRINTF_DIR)/ft_printf.c $(FT_PRINTF_DIR)/ft_putptr.c $(FT_PRINTF_DIR)/ft_putnbrbasehex.c \
       $(FT_PRINTF_DIR)/ft_putunbr.c $(FT_PRINTF_DIR)/ft_putchar.c $(FT_PRINTF_DIR)/ft_putstr.c \
	   $(FT_PRINTF_DIR)/ft_putnbr.c \
	   $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c

OBJ = $(patsubst $(SRCS_DIR)/%.c,$(OBJ_DIR)/$(SRCS_DIR)/%.o,$(filter $(SRCS_DIR)/%,$(SRCS)))
OBJ += $(patsubst $(FT_PRINTF_DIR)/%.c,$(OBJ_DIR)/$(FT_PRINTF_DIR)/%.o,$(filter $(FT_PRINTF_DIR)/%,$(SRCS)))
OBJ += $(patsubst $(GNL_DIR)/%.c,$(OBJ_DIR)/$(GNL_DIR)/%.o,$(filter $(GNL_DIR)/%,$(SRCS)))

# Library name
NAME = libft.a

# Default target - compiles the main library without bonus
a: $(NAME)
	@echo "Library compiled."

all: $(NAME)
	@echo "Library compiled."

# Compile main library
$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

# Rule to compile individual .c files to .o files
$(OBJ_DIR)/$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(SRCS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/$(FT_PRINTF_DIR)/%.o: $(FT_PRINTF_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(FT_PRINTF_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/$(GNL_DIR)/%.o: $(GNL_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/$(GNL_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove object files
c:
	rm -rf $(OBJ_DIR)
	@echo "Cleaned object files."

clean:
	rm -rf $(OBJ_DIR)
	@echo "Cleaned object files."

# Fclean target to remove object files and the library
f: clean
	rm -f $(NAME)
	@echo "Cleaned library."

fclean: clean
	rm -f $(NAME)
	@echo "Cleaned library."

# Re target to recompile everything
re: fclean all

christophe:
	@echo "Christophe compiled."

# Phony targets
.PHONY: a all c clean f fclean re christophe
