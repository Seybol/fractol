# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scebula <scebula@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:07:00 by scebula           #+#    #+#              #
#    Updated: 2016/06/05 19:57:25 by scebula          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =	./ft_atoi.c \
		./ft_bzero.c \
		./ft_free_charchar.c \
		./get_next_line.c \
		./ft_isalnum.c \
		./ft_isalpha.c \
		./ft_isascii.c \
		./ft_isdigit.c \
		./ft_isdigits.c \
		./ft_isprint.c \
		./ft_isspace.c \
		./ft_itoa.c \
		./ft_itoa_base.c \
		./ft_list_clear.c \
		./ft_listlen.c \
		./ft_lst_pushback.c \
		./ft_lstadd.c \
		./ft_lstdel.c \
		./ft_lstdelone.c \
		./ft_lstiter.c \
		./ft_lstmap.c \
		./ft_lstnew.c \
		./ft_memalloc.c \
		./ft_memccpy.c \
		./ft_memchr.c \
		./ft_memcmp.c \
		./ft_memcpy.c \
		./ft_memdel.c \
		./ft_memmove.c \
		./ft_memset.c \
		./ft_printlst.c \
		./ft_putchar.c \
		./ft_putchar_fd.c \
		./ft_putendl.c \
		./ft_putendl_fd.c \
		./ft_putnbr.c \
		./ft_putnbr_fd.c \
		./ft_putstr.c \
		./ft_putstr_fd.c \
		./ft_strcat.c \
		./ft_strchr.c \
		./ft_strclr.c \
		./ft_strcmp.c \
		./ft_strcpy.c \
		./ft_strdel.c \
		./ft_strdup.c \
		./ft_strequ.c \
		./ft_striter.c \
		./ft_striteri.c \
		./ft_strjoin.c \
		./ft_strlcat.c \
		./ft_strlen.c \
		./ft_strmap.c \
		./ft_strmapi.c \
		./ft_strncat.c \
		./ft_strncmp.c \
		./ft_strncpy.c \
		./ft_strndup.c \
		./ft_strnequ.c \
		./ft_strnew.c \
		./ft_strnstr.c \
		./ft_strrchr.c \
		./ft_strrchr_n.c \
		./ft_strrev.c \
		./ft_strsplit.c \
		./ft_strsplit_lst.c \
		./ft_strsplit_whitespaces.c \
		./ft_strstr.c \
		./ft_strsub.c \
		./ft_strtrim.c \
		./ft_tablen.c \
		./ft_tolower.c \
		./ft_toupper.c

CFLAGS = -c -Wall -Werror -Wextra

CC = gcc

OBJS = $(SRCS:.c=.o)

NAME = libft.a

HEADER = libft.h

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS)
	ar cr $(NAME) $(OBJS)
	ranlib $(NAME)
	rm -rf ./includes
	mkdir -p ./includes
	cp $(HEADER) ./includes/$(HEADER)

clean:
	rm -f $(OBJS)
	rm -rf ./includes

fclean: clean
	rm -f $(NAME)

re: fclean all
