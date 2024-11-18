NAME = libftprintf.a

SRC = ft_printf.c

CFALGS = -Wall -Wextra -Werror

LIBC = ar rc

OBJ = $(SRC:.c=.o)

all : $(NAME)
$(NAME) : $(OBJ)
	$(LIBC) $(NAME) $(OBJ)

clean : 
	$(RM) $(OBJ)

fclean : clean 
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re