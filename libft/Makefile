# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/19 15:27:24 by user42            #+#    #+#              #
#    Updated: 2021/03/11 16:54:44 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = clang

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 -fno-omit-frame-pointer -I includes/

HEADERS = libft.h get_next_line.h

FTGNL = get_next_line get_next_line_utils
FTIS = alnum alpha ascii digit print space instr
FTLST = add_back add_front clear delone iter last map new size
FTMEM = ccpy chr cmp cpy move set
FTPUT = char endl nbr str
FTSTR = split strchr strdup strjoin strlcat strlcpy strlen strmapi strncmp strcmp strncpy strnstr strrchr strtrim substr
FTTO = atoi atol itoa tolower toupper
FTSKIP = space

SRCS = 	$(addsuffix .c, $(addprefix ft_gnl/, $(FTGNL))) \
		$(addsuffix .c, $(addprefix ft_is/ft_is, $(FTIS))) \
		$(addsuffix .c, $(addprefix ft_lst/ft_lst, $(FTLST))) \
		$(addsuffix .c, $(addprefix ft_mem/ft_mem, $(FTMEM))) \
		$(addsuffix _fd.c, $(addprefix ft_put/ft_put, $(FTPUT))) \
		$(addsuffix .c, $(addprefix ft_str/ft_, $(FTSTR))) \
		$(addsuffix .c, $(addprefix ft_to/ft_, $(FTTO))) \
		$(addsuffix .c, $(addprefix ft_skip/ft_skip_, $(FTSKIP)))

OBJS = ${SRCS:.c=.o}

all:	$(NAME)

$(NAME):	$(OBJS)
				ar rc $(NAME) $^
				ranlib $(NAME)

%.o:%.c
				${CC} ${CFLAGS} -c $< -o $@

clean:
				rm -f $(OBJS)

fclean:		clean
				rm -f $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
