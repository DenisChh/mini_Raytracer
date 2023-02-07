NAME		= minirt
LIBFT		= libft/libft.a
LIBMLX		= minilibx/libmlx.a

SRCS		= $(wildcard src/*/*.c)

SRCDIR		= src
INCLUDDIR	= includes
MLXDIR		= minilibx
LIBFTDIR	= libft
SUBDIRS		= color hook intersection math_tools objects parser rt transformation

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -g
LIBFTFLAGS	= -L $(LIBFTDIR) -lft
MLXFLAGS	= -L $(MLXDIR) -lmlx -lXext -lX11
LFLAGS		= $(LIBFTFLAGS) $(MLXFLAGS) -lm
INCLUDES	= -I $(LIBFTDIR) -I $(MLXDIR) -I $(INCLUDDIR)

RM			= rm -Rf

all :		$(LIBMLX) $(LIBFT) $(NAME)

$(NAME) :	$(OBJS)
			$(CC) -o $@ $^ $(CFLAGS) $(INCLUDES) $(LFLAGS)

$(LIBFT) :
			make -C $(LIBFTDIR)

$(LIBMLX) :
			make -C $(MLXDIR)

.c.o :
			$(CC) -c $< -o $(<:.c=.o) $(CFLAGS) $(INCLUDES)

clean :
			$(RM) $(OBJS)

fclean :	clean
			make clean -C $(MLXDIR)
			make fclean -C $(LIBFTDIR)
			$(RM) $(NAME)

re :		fclean all

.PHONY :	all clean fclean re libft
