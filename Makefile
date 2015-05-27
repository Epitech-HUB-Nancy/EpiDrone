
SRC1=		./src_server/server.c	\
		./src_server/do_cmd.c

SRC2=		./src_client/client.c


NAME1=		server

NAME2=		client

OBJ1=		$(SRC1:.c=.o)

OBJ2=		$(SRC2:.c=.o)

all:		$(NAME1) $(NAME2)

$(NAME1):	$(OBJ1)
		cc -o $(NAME1) $(OBJ1)

$(NAME2):	$(OBJ2)
		cc -o $(NAME2) $(OBJ2)

clean:
		rm -f $(OBJ1)
		rm -f $(OBJ2) *~ *#

fclean:		clean
		rm -f $(NAME1)
		rm -f $(NAME2)

re:		fclean all

.PHONY:		all clean fclean re
