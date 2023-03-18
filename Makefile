# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sryou <sryou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:17:08 by junhelee          #+#    #+#              #
#    Updated: 2023/03/18 16:56:46 by sryou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	cub3D

SRCS_DIR:=	./src
SRCS	:=	cub3d.c \
			ft_mlx.c \
			calculate.c \
			draw.c \
			render.c \
			move.c

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
COMPILE	:=	$(CC) $(CFLAGS)

RM		:= rm -rf
NORM	:= norminette
MKDIR	:= mkdir -p

LIBFT	:=	./libft
MLX_DIR	:=	./mlx
INCLUDES:=	-I./include -I$(LIBFT) -I$(MLX_DIR)

OBJ_DIR	:=	./object
OBJS	:=	$(patsubst %,$(OBJ_DIR)/%,$(SRCS:%.c=%.o))

LINK_FT	:=	-L$(LIBFT) -lft
LINK_MLX:=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework APPKit
LINKING	:=	$(LINK_MLX) $(LINK_FT)

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	$(COMPILE) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(MAKE) -C $(MLX_DIR)
	$(COMPILE) $(LINKING) $^ -o $@

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJ_DIR)

fclean:
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJ_DIR)
	$(RM) $(NAME)

re:
	@$(MAKE) fclean
	@$(MAKE) all

norm:
	@$(NORM) ./include
	@$(NORM) $(SRCS_DIR)

.PHONY: all clean fclean re norm