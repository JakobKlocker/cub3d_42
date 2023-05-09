# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iengels <iengels@student.42vienna.com>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 20:06:35 by iengels           #+#    #+#              #
#    Updated: 2023/05/08 20:36:40 by iengels          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	cub3D

NAME_B =	cub3D_bonus

SRCS = 	main.c	\
		createBG.c	\
		mallocMap.c	\
		mapChecks_1.c	\
		mapChecks.c \
		mapInfos.c \
		mapInfos_1.c \
		mlxCalls.c \
		rayCasting.c \
		rayCasting_utils.c \
		errorFree.c \
		errorFree_1.c \
		textures.c \
		moveHooks.c \
		mallocMap_1.c

B_SRCS = createBG_bonus.c	\
		main_bonus.c	\
		errorFree_bonus.c	\
		errorFree_1_bonus.c \
		mallocMap_1_bonus.c	\
		mallocMap_bonus.c	\
		mapChecks_1_bonus.c	\
		mapChecks_bonus.c	\
		mapInfos_1_bonus.c	\
		mapInfos_bonus.c	\
		mlxCalls_bonus.c	\
		moveHooks_bonus.c	\
		rayCasting_bonus.c	\
		rayCasting_utils_bonus.c	\
		textures_bonus.c	\
		minimap.c	\
		minimap_player.c	\
		minimap_helper.c

SRCSDIR		:= ./srcs/
SRC			:= $(addprefix ${SRCSDIR}, ${SRCS})
OBJS		:= ${SRCS:.c=.o}
OBJ			:= $(addprefix ${SRCSDIR}, ${OBJS})

B_SRCSDIR	:= ./bonus_srcs/
B_SRC		:= $(addprefix ${B_SRCSDIR}, ${B_SRCS})
B_OBJS		:= ${B_SRCS:.c=.o}
B_OBJ		:= $(addprefix ${B_SRCSDIR}, ${B_OBJS})

CC =	cc
CFLAGS =	-Wall -Wextra -Werror


all :		$(NAME)

$(NAME) :	
		(cd libft && make)
		cp libft/libft.a libft.a
		$(CC) -c $(SRC)
		mv *.o ./srcs/
		$(CC) -o $(NAME) $(OBJ) $(CFLAGS) libft.a mlx/libmlx_Linux.a -lXext -lX11 -lm

$(NAME_B) :
		(cd libft && make)
		cp libft/libft.a libft.a
		$(CC) -c $(B_SRC)
		mv *.o ./bonus_srcs/
		$(CC) -o $(NAME_B) $(B_OBJ) $(CFLAGS) libft.a mlx/libmlx_Linux.a -lXext -lX11 -lm

clean :		
		(cd libft && make fclean)
		rm -f $(OBJ)
		rm -f $(B_OBJ)
		rm -f libft.a
	

fclean :	clean
			rm -f cub3D
			rm -f cub3D_bonus

re :		fclean all

bonus :	$(NAME_B)


.PHONY:		all clean fclean re