# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alegay <alegay@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/18 09:49:24 by eseveno           #+#    #+#              #
#    Updated: 2015/06/08 15:01:02 by alegay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME =			philo

CC =			gcc -O3 $(FLAGS) $(INCLUDES)

LIBFT =			-L./libft -lft -L ~/.brew/Cellar/sdl/1.2.15/lib -lSDL -lSDLmain -framework Cocoa

LIB =			./libft/libft.a

 INCLUDES =		-I./includes -I./libft/includes  -I ~/.brew/Cellar/sdl/1.2.15/include/SDL -I /Volumes/Data/nfs/zfs-student-3/users/2013/eseveno/.brew/Cellar/sdl/1.2.15/libexec

 SRC =			main.c sdl.c wait.c init.c

 OBJ =			$(SRC:.c=.o)

 FLAGS =		-Wall -Wextra -Werror

 all:			$(LIB) $(NAME)

$(LIB):

				@echo "\033[32m[Make]\033[0m   " | tr -d '\n'
				@echo "\033[36m[libft]\033[0m Building libft... " | tr -d '\n'
				Make -C libft


$(NAME):		$(OBJ)
				echo "\033[32m[Make]\033[0m   " | tr -d '\n'
				echo "\033[36m[$(NAME)]\033[0m " | tr -d '\n'
				echo "Building $(NAME)... " | tr -d '\n'
				$(CC) -o $(NAME) $(OBJ) $(LIBFT)
				echo "\033[32m   -> \033[0m" | tr -d '\n'
				echo "\033[36m$(NAME) \033[0m\033[32mcreated\033[0m"


# sdl:
# 				mkdir -p SDL/junk
# 				curl http://www.libsdl.org/release/SDL-1.2.1.tar.gz -o "SDL-1.2.1.tar.gz"
# 				tar -xf SDL-1.2.1.tar.gz
# 				cd SDL-1.2.1 && ./configure --prefix=$(shell pwd)/SDL/ && $(MAKE) && $(MAKE) install
# 				mv SDL-1.2.1.tar.gz SDL-1.2.1 SDL/junk

clean:
				Make -C libft clean
				@echo "\033[31m[clean] " | tr -d '\n'
				@echo "\033[36m[$(NAME)]\033[0m Remove ofiles"
				rm -f $(OBJ)

fclean:
				Make -C libft fclean
				rm -rf lpng1617
				rm -f $(OBJ)
				rm -f $(NAME)
				@echo "\033[31m[fclean] \033[36m[$(NAME)]\033[0m" | tr -d '\n'
				@echo " Remove ofiles & $(NAME)"

cleansdl:
				rm -rf SDL1

re:				fclean all

.PHONY:			all clean re fclean
.SILENT:

%.o:			%.c
				$(CC) -c $< -o $@
