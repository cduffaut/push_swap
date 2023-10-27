# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cduffaut <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/11 14:23:21 by cduffaut          #+#    #+#              #
#    Updated: 2023/10/27 10:20:03 by csil             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= \
	 algo_for_5_or_less.c assign_index.c assign_previous_nodes.c check_error_argv.c \
	 check_error_quotes.c create_stack_a.c free_all.c is_sorted_list.c \
	 main_create_stack.c push.c push_swap.c reverse_rotate.c rotate.c swap.c radix.c

LIBFT	=		./libft/libft.a

MLIBFT	=		@$(MAKE) -C libft

OBJS	= $(SRCS:.c=.o)

GCC	= gcc -Wall -Wextra -Werror

NAME	= push_swap

all:	lib $(NAME) 

lib:
	$(MLIBFT) all

%.o:	%.c ./libft/libft.h Makefile
	$(GCC) -c $< -o $@

$(NAME) :	${OBJS}
		$(GCC) -o ${NAME} ${OBJS} ${LIBFT}

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	${MLIBFT} clean

fclean:	clean
	rm -f $(NAME)
	${MLIBFT} fclean

re:	fclean all

.PHONY : re fclean clean all bonus
