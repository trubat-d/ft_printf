SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils2.c ft_printf_utils3.c

LIB = ./libft/

OBJS = $(SRCS:.c=.o)

NAME = libftprintf.a
AR = ar rcs
CC		= gcc
RM		= rm -f

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		cd ${LIB} && ${MAKE} && cp -v libft.a ../${NAME}
		$(AR) $(NAME) $(OBJS)

.c.o:
		$(CC) $(CFLAGS) -g -c -I$(LIB) $< -o $(<:.c=.o)

clean:
		$(RM) $(OBJS) $(OBJSBONUS)
		cd $(LIB) && $(MAKE) clean

fclean:	clean
		$(RM) $(NAME)
		cd $(LIB) && $(MAKE) fclean

re:		fclean all

.PHONY: all clean fclean re 