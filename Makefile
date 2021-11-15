NAME	= philo
HEADER	= philo.h

LIST		= philo.c parser.c libft_func_0.c secondary_func_0.c secondary_func_1.c

OBJ			= $(LIST:.c=.o)

FLAGS       = -Wall -Wextra -Werror

%.o:%.c		$(HEADER)
		    gcc $(FLAGS) -c $< -o $(<:.c=.o)

$(NAME) :	$(OBJ) $(HEADER)
			gcc $(OBJ) -o $(NAME)

all :		$(NAME)

clean :
			rm -f $(OBJ)

fclean :	clean
			rm -f $(NAME)
debug:
		gcc -g ${LIST} -o philo
re :		fclean all

.PHONY :	all clean fclean re
