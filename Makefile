NAME =		microshell

SRCS =		utils.c \
			parser.c \
			run.c \
			microshell.c

OBJS =		$(SRCS:.c=.o)
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $@
			
debug:		$(OBJS)
			$(CC) $(CFLAGS) -fsanitize=address $(OBJS) -o $@

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re			
