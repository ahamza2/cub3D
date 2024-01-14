# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 11:53:07 by hait-sal          #+#    #+#              #
#    Updated: 2024/01/14 21:10:15 by haarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  cube

CC = cc

MY_LIB = "/Users/haarab/MLX42/build/libmlx42.a" -lglfw -L"/Users/haarab/.brew/opt/glfw/lib/"

FLAGS = -Wall -Wextra -Werror -fsanitize=address


SRC = main.c map.c player.c key_hook.c draw_line.c ray_casting.c walls.c render_text.c

OBJ = ${SRC:.c=.o}

%.o : %.c 
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME) clean

$(NAME) : $(OBJ) 
	$(CC) $(OBJ) $(FLAGS) $(MY_LIB) -o $(NAME)

clean :
	rm -f $(OBJ)

fclean :
	rm -f $(OBJ) $(NAME)

re : fclean all