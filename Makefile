NAME		= philo
CFLAGS		= -Wall -Wextra -Werror -g3 -fsanitize=address
RM			= rm -rf

OBJ			= $(SRC:.c=.o)

SRC =	main.c \

all:	$(NAME)

%.o : %.c
	${CC} -c -o $@ $^ ${CFLAGS}
	
$(NAME):	$(OBJ) 
			${MAKE} -C
			$(CC) ${CFLAGS} -o ${NAME} ${OBJ} -framework OpenGL -framework AppKit


clean:
			$(RM) $(OBJ)
			$(MAKE) -C

fclean:		clean
			$(RM) $(NAME)
			$(MAKE) -C

re:			fclean all

.PHONY:		all clean fclean re
