# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hait-sal <hait-sal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 11:53:07 by hait-sal          #+#    #+#              #
#    Updated: 2024/01/25 13:36:40 by hait-sal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  cub3D

BONUS = cub3D_bonus

CC = cc

MY_LIB = "/Users/hait-sal/MLX42/build/libmlx42.a" -lglfw -L"/Users/hait-sal/.brew/opt/glfw/lib/"

FLAGS = -Wall -Wextra -Werror -O3 #-fsanitize=address -g


SRC = mandatory/initialization/player_init.c \
		mandatory/map/map.c\
		mandatory/player/draw_line.c mandatory/player/player.c\
		mandatory/ray_casting/key_hook.c mandatory/main.c mandatory/ray_casting/ray_casting_p1.c mandatory/ray_casting/ray_casting_p2.c mandatory/ray_casting/ray_casting_p3.c\
		mandatory/textures/textures.c mandatory/textures/walls.c mandatory/textures/walls_textures.c\
		mandatory/parsing/parse.c mandatory/parsing/ft_split.c mandatory/parsing/ft_strtrim.c mandatory/parsing/libft.c mandatory/parsing/maps.c mandatory/parsing/path.c mandatory/parsing/rgb.c\
		mandatory/parsing/free.c mandatory/parsing/error.c mandatory/parsing/derection.c mandatory/parsing/initialization_variables.c mandatory/parsing/counter.c\
		mandatory/parsing/error2.c mandatory/parsing/libft2.c mandatory/parsing/alocation.c\
		mandatory/get_next_line/get_next_line.c mandatory/get_next_line/get_next_line_utils.c

SRC_BONUS = bonus/initialization/player_init.c \
		bonus/map/map.c \
		bonus/player/draw_line.c bonus/player/player.c \
		bonus/ray_casting/key_hook.c bonus/main.c bonus/ray_casting/ray_casting_p1.c bonus/ray_casting/ray_casting_p2.c bonus/ray_casting/ray_casting_p3.c\
		bonus/textures/textures.c bonus/textures/walls.c bonus/textures/walls_textures.c\
		bonus/parsing/parse.c bonus/parsing/ft_split.c bonus/parsing/ft_strtrim.c bonus/parsing/libft.c bonus/parsing/maps.c bonus/parsing/path.c bonus/parsing/rgb.c\
		bonus/parsing/free.c bonus/parsing/error.c bonus/parsing/derection.c bonus/parsing/initialization_variables.c bonus/parsing/counter.c\
		bonus/parsing/error2.c bonus/parsing/libft2.c bonus/parsing/alocation.c\
		bonus/get_next_line/get_next_line.c bonus/get_next_line/get_next_line_utils.c

OBJ = ${SRC:.c=.o}

OBJ_BONUS = ${SRC_BONUS:.c=.o}

%.o : %.c 
	$(CC) $(FLAGS) -c $< -o $@


	
all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJ)
	@$(CC) $(OBJ) $(FLAGS) $(MY_LIB) -o $(NAME)

$(BONUS) : $(OBJ_BONUS)
	@$(CC) $(OBJ_BONUS) $(FLAGS) $(MY_LIB) -o $(BONUS)

clean :
	rm -f $(OBJ) $(OBJ_BONUS)

fclean :
	rm -f $(OBJ) $(OBJ_BONUS) $(NAME) $(BONUS)

re : fclean all

.PHONY : all bonus clean fclean