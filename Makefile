# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:26:28 by haarab            #+#    #+#              #
#    Updated: 2024/01/21 09:55:45 by haarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

MY_LIB = "/Users/haarab/MLX42/build/libmlx42.a" -lglfw -L"/Users/haarab/.brew/opt/glfw/lib/"

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g
SRCS = cub3d.c maps.c libft.c ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_strtrim.c 


OBJ = ${SRCS:.c=.o}

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

run : $(NAME)
	./cub3d ./maps/map.cub