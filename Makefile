NAME = libftprintf.a

LIBFT = libft/libft.a

PRINTF_HEADER = libftprintf.h

LIBFT_PATH = libft/

CC = cc -Wall -Wextra -Werror

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

%.o: %.c $(PRINTF_HEADER)
	@$(CC) -c $< -o $@

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@cp $< $@
	@ar rcs $@ $(OBJ)
	@echo "PRINTF: libftprintf.a created"

$(LIBFT):
	@make -s -C $(LIBFT_PATH) all

clean:
	@rm -rf $(OBJ)
	@make -s -C $(LIBFT_PATH) clean

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)

re: fclean all

.PHONY: all clean fclean re