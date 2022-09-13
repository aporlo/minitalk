# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lsomrat <lsomrat@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/07 20:00:42 by lsomrat           #+#    #+#              #
#    Updated: 2022/09/07 20:01:22 by lsomrat          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS	= -Wall -Wextra -Werror
NAME	= minitalk
SERVER  = server
CLIENT	= client
SRCS_SER = server.c
SRCS_CNT = client.c
SRCS	= ft_printf.c \
		ft_putnbr.c \
		ft_put_str.c

# SRCS_B	= ft_lstnew.c \
# 	  ft_lstadd_front.c \
# 	  ft_lstlast.c \
# 	  ft_lstsize.c \
# 	  ft_lstadd_back.c \
# 	  ft_lstdelone.c \
# 	  ft_lstclear.c \
# 	  ft_lstiter.c \
# 	  ft_lstmap.c 

OBJS	= ${SRCS:.c=.o}

# OBJS_B    = ${SRCS_B:.c=.o}

%.o: %.c
	gcc ${FLAGS} -c $< -o $@
	
$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

# bonus: ${OBJS_B}
# 	ar rcs ${NAME} ${OBJS_B}

# norminette:
# 	norminette ${SRCS} ${SRCS_B}

norminette:
	norminette ${SRCS}
	
all: ${NAME}

clean:
	rm -f ${OBJS}
	# rm -f ${OBJS} ${OBJS_B}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: norminette all
