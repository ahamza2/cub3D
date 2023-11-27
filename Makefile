# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haarab <haarab@student.1337.ma>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 11:26:28 by haarab            #+#    #+#              #
#    Updated: 2023/11/27 17:49:06 by haarab           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
MINI = -lmlx -lmlx -framework OpenGL -framework AppKit

SRCS = cub3d.c maps.c libft.c ft_split.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c ft_strtrim.c maps2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)


$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MINI) -o $(NAME)

clean:
	$(RM) $(OBJS)
	
fclean: clean
	$(RM) $(NAME)

re: fclean all

run : $(NAME)
	./cub3d ./maps/map.cub