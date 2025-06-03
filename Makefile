NAME_1 = libftprintf.a

NAME_2 = libft/libft.a

HEADER_1 = libftprintf.h

HEADER_2 = libft/libft.h

LIBFT_PATH = libft/

COMP = cc -Wall -Wextra -Werror

SRC = ft_printf.c

OBJ = $(SRC:.c=.o)

%.o: %.c $(HEADER_1)
	@$(COMP) -c $< -o $@

all: $(NAME_1)

$(NAME_1): $(NAME_2) $(OBJ)
	@cp $< $@
	@ar rcs $@ $(OBJ)
	@echo "libftprintf.a created"

$(NAME_2):
	@$(MAKE) -C $(LIBFT_PATH) all --no-print-directory

clean:
	@rm -rf $(OBJ)
	@$(MAKE) -C $(LIBFT_PATH) clean --no-print-directory

fclean: clean
	@rm -rf $(NAME_1)
	@rm -rf $(NAME_2)

re: fclean all

.PHONY: all clean fclean re