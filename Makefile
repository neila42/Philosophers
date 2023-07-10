NAME		= philo
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=thread
RM			= rm -rf

OBJ			= $(SRC:.c=.o)

SRC =	main.c \
		day.c \
		func.c \
		util.c \
		util2.c \
		fork.c \

HEADER = philo.h \

all:	$(NAME)

%.o : %.c $(HEADER)
	${CC} -c -o $@ $< ${CFLAGS}
	
$(NAME):	$(OBJ) 
			$(CC) ${CFLAGS} -o ${NAME} ${OBJ}


clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
