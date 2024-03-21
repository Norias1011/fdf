SRCS = fdf.c dimension.c draw.c hook.c initwin.c mapcheck.c mapslimit.c

OBJS = $(SRCS:%.c=%.o)

NAME = fdf

CC = cc 

CFLAGS = -Wall -Wextra -Werror

RM = rm -f 

all: $(NAME)

%.o:	%.c 
		$(CC) $(CFLAGS) -Ilibft -Iminilibx-linux -c $? -o $@

$(NAME):		$(OBJS)
		@make -C libft
		@make -C minilibx-linux
		$(CC) $(CFLAGS) $^ -lft -Llibft -Lminilibx-linux -lmlx -lX11 -lXext -lm -o $(NAME)

libft:
		make -C libft

minilibx:
		make -C minilibx-linux

clean:
		make clean -C libft
		make clean -C minilibx-linux
		$(RM) $(OBJS)

fclean:	clean
				$(RM) $(NAME)

re:				fclean all