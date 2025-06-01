NAME_1 = libftprintf.a

NAME_2 = libft.a

HEADER_1 = libftprintf.h

HEADER_2 = libft.h

LIBFT_PATH = ./libft

COMP = cc -Wall -Wextra -Werror

LIBFT_OBJS = ft_putchar_fd.o \
		ft_puthex_low_fd.o	\
		ft_puthex_up_fd.o	\
		ft_putnbr_fd.o		\
		ft_putptr_fd.o		\
		ft_putstr_fd.o	\
		ft_putunbr_fd.o		\
		ft_strlen.o

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

%.o: %.c $(HEADER_1)
	@$(COMP) -c $< -o $@

all: $(NAME_1)

$(NAME_1): $(OBJS) $(LIBFT_PATH)/$(NAME_2) $(HEADER_1)
	@ar rcs $(NAME_1) $(OBJS) $(addprefix $(LIBFT_PATH)/, $(LIBFT_OBJS))
	@echo "libftprintf.a created"

$(LIBFT_PATH)/$(NAME_2): $(addprefix $(LIBFT_PATH)/, $(LIBFT_OBJS)) $(LIBFT_PATH)/$(HEADER_2)
	@$(MAKE) -C $(LIBFT_PATH) all --no-print-directory

clean:
	@rm -rf $(OBJS)
	@$(MAKE) -C $(LIBFT_PATH) clean --no-print-directory

fclean: clean
	@rm -rf $(NAME_1)
	@rm -rf $(LIBFT_PATH)/$(NAME_2)

re: fclean all

.PHONY: all clean fclean re