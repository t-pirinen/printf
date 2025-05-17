# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpirinen <tpirinen@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/15 17:32:33 by tpirinen          #+#    #+#              #
#    Updated: 2025/05/17 03:59:11 by tpirinen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# variables
NAME = libft.a

HEADER = libft.h

COMPILER = cc

CFLAGS = -Wall -Wextra -Werror

SRC	=	ft_atoi.c			\
		ft_bzero.c			\
		ft_calloc.c			\
		ft_isalnum.c		\
		ft_isalpha.c		\
		ft_isascii.c		\
		ft_isdigit.c		\
		ft_isprint.c		\
		ft_itoa.c			\
		ft_lstadd_back.c	\
		ft_lstadd_front.c	\
		ft_lstclear.c		\
		ft_lstdelone.c		\
		ft_lstiter.c		\
		ft_lstlast.c		\
		ft_lstmap.c			\
		ft_lstnew.c			\
		ft_lstsize.c		\
		ft_memchr.c			\
		ft_memcmp.c			\
		ft_memcpy.c			\
		ft_memmove.c		\
		ft_memset.c			\
		ft_putchar_fd_ret.c	\
		ft_putchar_fd.c		\
		ft_putendl_fd.c		\
		ft_puthex_low_fd.c	\
		ft_puthex_up_fd.c	\
		ft_putnbr_fd_ret.c	\
		ft_putnbr_fd.c		\
		ft_putptr_fd.c		\
		ft_putstr_fd_ret.c	\
		ft_putstr_fd.c		\
		ft_putunbr_fd.c		\
		ft_split.c			\
		ft_strchr.c			\
		ft_strdup.c			\
		ft_striteri.c		\
		ft_strjoin.c		\
		ft_strlcat.c		\
		ft_strlcpy.c		\
		ft_strlen.c			\
		ft_strmapi.c		\
		ft_strncmp.c		\
		ft_strnstr.c		\
		ft_strrchr.c		\
		ft_strtrim.c		\
		ft_substr.c			\
		ft_tolower.c		\
		ft_toupper.c		\

OBJS = $(SRC:.c=.o)

%.o: %.c $(HEADER)
	@$(COMPILER) $(CFLAGS) -c $< -o $@

# rules
all: $(NAME)

$(NAME): $(OBJS)
		@ar rcs $(NAME) $^
		@echo ".o files and libft.a created"
		
clean:
		@rm -f $(OBJS)
		@echo "Removed .o files"

fclean: clean
		@rm -f $(NAME)
		@echo "Removed libft.a"

re: fclean all

.PHONY: all clean fclean re