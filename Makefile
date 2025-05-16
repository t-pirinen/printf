NAME_1 = libftprintf.a

NAME_2 = libft.a

LIBFT_PATH = ./libft

COMP = cc -Wall -Wextra -Werror

LIBFT_OBJS = ft_isalnum.o \
		ft_isalpha.o \
		ft_isascii.o \
		ft_isdigit.o \
		ft_isprint.o \
		ft_tolower.o \
		ft_toupper.o \
		ft_bzero.o \
		ft_calloc.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_memcpy.o \
		ft_memmove.o \
		ft_memset.o \
		ft_atoi.o \
		ft_itoa.o \
		ft_split.o \
		ft_strchr.o \
		ft_strdup.o \
		ft_striteri.o \
		ft_strjoin.o \
		ft_strlcat.o \
		ft_strlcpy.o \
		ft_strlen.o \
		ft_strmapi.o \
		ft_strncmp.o \
		ft_strnstr.o \
		ft_strrchr.o \
		ft_strtrim.o \
		ft_substr.o \
		ft_putchar_fd.o \
		ft_putstr_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o \
		ft_putchar_fd_ret.o \
		ft_putnbr_fd_ret.o \
		ft_putstr_fd_ret.o \
		ft_lstnew_bonus.o \
		ft_lstadd_front_bonus.o \
		ft_lstsize_bonus.o \
		ft_lstlast_bonus.o \
		ft_lstadd_back_bonus.o \
		ft_lstdelone_bonus.o \
		ft_lstclear_bonus.o \
		ft_lstiter_bonus.o \
		ft_lstmap_bonus.o

SRCS = ft_printf.c

OBJS = $(SRCS:.c=.o)

.c.o:
	$(COMP) -c $< -o $@

all: $(NAME_1)

$(NAME_1): $(OBJS)

	$(MAKE) -C $(LIBFT_PATH) all
	ar rcs $(NAME_1) $(OBJS) $(addprefix $(LIBFT_PATH)/, $(LIBFT_OBJS))

clean:
	rm -rf *.o
	$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	rm -rf $(NAME_1) $(NAME_2)

re: fclean all

.PHONY: all clean fclean re