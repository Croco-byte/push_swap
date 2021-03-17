# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/05 15:18:35 by user42            #+#    #+#              #
#    Updated: 2021/03/17 12:02:21 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSHNAME = push_swap
CHECKNAME = checker

CC = clang

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g3 -fno-omit-frame-pointer -I includes/ -I libft/includes/

LIBFT = -L libft -lft

HEADER = push_swap.h

COMMONFILES = errors stack stack2 utils instr instr2
PUSHFILES = push_swap sort sort_utils sort_utils2 sort_stack_less_2 sort_less_3 sort_less_50 sort_less_200 sort_more_200 big_utils big_utils2
CHECKFILES = checker read

COMMONSRCS = $(addsuffix .c, $(addprefix srcs/common/, $(COMMONFILES)))
PUSHSRCS = $(addsuffix .c, $(addprefix srcs/push_swap/, $(PUSHFILES)))
CHECKSRCS = $(addsuffix .c, $(addprefix srcs/checker/, $(CHECKFILES)))

COMMONOBJS = ${COMMONSRCS:.c=.o}
PUSHOBJS = ${PUSHSRCS:.c=.o}
CHECKOBJS = ${CHECKSRCS:.c=.o}

all:			$(PUSHNAME) $(CHECKNAME)

$(PUSHNAME):	$(PUSHOBJS) $(COMMONOBJS)
				make -C libft/
				$(CC) $(CFLAGS) -o $(PUSHNAME) $(PUSHOBJS) $(COMMONOBJS) $(LIBFT)

$(CHECKNAME):	$(CHECKOBJS)
				$(CC) $(CFLAGS) -o $(CHECKNAME) $(CHECKOBJS) $(COMMONOBJS) $(LIBFT)

%.o:%.c
				${CC} ${CFLAGS} -c $< -o $@

clean:
				make clean -C libft
				rm -f $(PUSHOBJS)
				rm -f $(CHECKOBJS)

fclean:
				make fclean -C libft
				rm -f $(PUSHOBJS)
				rm -f $(CHECKOBJS)
				rm -f $(COMMONOBJS)
				rm -f $(PUSHNAME)
				rm -f $(CHECKNAME)

re:				fclean all

.PHONY:			all clean fclean re




