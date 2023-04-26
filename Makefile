NAME =	cub3D

SRCS = 	main.c	\
		createBG.c	\
		mallocMap.c	\
		mapChecks_1.c	\
		mapChecks.c \
		mapInfos.c \
		mapInfos_1.c \
		mlxCalls.c \
		rayCasting.c

SRCSDIR			:= ./srcs/
SRC			:= $(addprefix ${SRCSDIR}, ${SRCS})


CC =	cc

#CFLAGS =	-Wall -Wextra -Werror

OBJSDIR	:= ./objs/
OBJS	:= ${SRCS:.c=.o}
OBJ		:= $(addprefix ${SRCSDIR}, ${OBJS})

all :		$(NAME)

$(NAME) :	
		(cd libft && make)
		cp libft/libft.a libft.a
		$(CC) -c $(SRC)
		mv *.o ./srcs/
		$(CC) -o $(NAME) $(OBJ) libft.a mlx/libmlx_Linux.a -lXext -lX11

clean :		
		(cd libft && make fclean)
		rm -f $(OBJS)
		rm -f libft.a
	

fclean :	clean
			rm -f cub3D

re :		fclean all

.PHONY:		all clean fclean re