# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: scebula <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/04 16:48:05 by scebula           #+#    #+#              #
#    Updated: 2016/06/05 19:57:02 by scebula          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = event.c \
		   fractal.c \
		   julia.c \
		   main.c \
		   putpixel.c \
		   batman.c \
		   event_mouse.c \
		   init_img.c \
		   mandelbrot.c \
		   ship.c \
		   bow.c \
		   colors.c \
		   init_mlx.c \
		   sizetitoa.c \
		   tricorn.c \
		   cactus.c \
		   flower.c \
		   init_struct.c \
		   snorlax.c

INC_NAME = fractol.h \
		   mlx.h \
		   libft.h \
		   keys.h

OBJ_NAME = $(SRC_NAME:.c=.o)
NAME = fractol
CC = gcc
CFLAGS =  -Werror -Wextra -Wall -O3
EXEC_NAME = fractol
MLX_FLAGS = -lft -lmlx -framework OpenGL -framework Appkit
LIBFT = libft.a
LIBMLX = libmlx.a
LIBFT_DIR = libft/
MLX_DIR = mlx/
LIB_DIR = lib/
INC_DIR = inc/
SRC_FILES = $(addprefix src/,$(SRC_NAME))
OBJ_FILES = $(addprefix obj/,$(OBJ_NAME))
INC_FILES = $(addprefix inc/,$(INC_NAME))

all: $(NAME) welcome

$(NAME): objects
ifeq ($(wildcard $(EXEC_NAME)),) 
	@echo "\x1b[31mMaking LIBFT ...\033[0m"
	@make -s -C $(LIBFT_DIR)
	@mkdir -p lib
	@cp $(LIBFT_DIR)$(LIBFT) $(LIB_DIR)$(LIBFT)
	@echo "\x1b[31mMaking LIBMLX ...\033[0m"
	@make -s -C $(MLX_DIR)
	cp $(MLX_DIR)$(LIBMLX) $(LIB_DIR)$(LIBMLX)
	@echo "\x1b[33m-- COMPILING ... --\033[0m"
	$(CC) $(CFLAGS) -o $(EXEC_NAME) $(OBJ_FILES) -Llib $(MLX_FLAGS)
	$(EXEC_EXIST = 1)
	@echo "\x1b[32m-- COMPILING SUCCESSFULL --"
else
	@echo "\x1b[31mNo need another compilation."
endif

first_task: $(NAME) norminette welcome

second_task:
	echo "ERROR"

welcome:
	@echo "\x1b[36m"
	@echo "Have fun with Fractol !"
	@echo "./fractol with one argument :"
	@echo "->mandelbrot"
	@echo "->julia"
	@echo "->cactus"
	@echo "->ship"
	@echo "->batman"
	@echo "->flower"
	@echo "->bow"
	@echo "->tricorn"
	@echo "->snorlax"

objects:
ifeq ($(wildcard $(EXEC_NAME)),) 
	$(CC) $(CFLAGS) -c -Iinc/ $(SRC_FILES)
	mkdir -p obj
	mv $(OBJ_NAME) obj/
else
endif

clean:
	make fclean -C $(LIBFT_DIR)
	rm -rf ./obj
	rm -rf ./lib
	

fclean: clean
	rm -f $(NAME)

re: fclean
	@make all
fcleanlibft: 
	make fclean -C $(LIBFT_DIR)
