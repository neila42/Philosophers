NAME		= philo
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			= rm -rf

OBJ			= $(SRC:.c=.o)

SRC =	main.c \
		day.c \
		func.c \
		util.c \
		fork.c \

all:	$(NAME)

%.o : %.c
	${CC} -c -o $@ $^ ${CFLAGS}
	
$(NAME):	$(OBJ) 
			$(CC) ${CFLAGS} -o ${NAME} ${OBJ}


clean:
			$(RM) $(OBJ)
			$(MAKE) -C

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
