# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:17:08 by junhelee          #+#    #+#              #
#    Updated: 2023/03/22 19:30:33 by junhelee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	cub3D

SRCS_DIR:=	./src
SRCS	:=	cub3d.c error.c init_config.c map_parser.c map_elem.c map_utils.c map_validate.c

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
COMPILE	:=	$(CC) -g $(CFLAGS)

RM		:= rm -rf
NORM	:= norminette
MKDIR	:= mkdir -p

LIBFT	:=	./libft
UNAME_S	:=	$(shell uname -s)
ifeq ($(UNAME_S), Darwin)
MLX_DIR	:=	./mlx
INCLUDES:=	-I./include -I$(LIBFT) -I$(MLX_DIR)
else
MLX_DIR	:=	./mlx_linux
INCLUDES:=	-I./include -I$(LIBFT) -I$(MLX_DIR) -O3
endif

OBJ_DIR	:=	./object
OBJS	:=	$(patsubst %,$(OBJ_DIR)/%,$(SRCS:%.c=%.o))

LINK_FT	:=	-L$(LIBFT) -lft
ifeq ($(UNAME_S), Darwin)
LINK_MLX:=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework APPKit
else
LINK_MLX:=	-L$(MLX_DIR) -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz
endif
LINKING	:=	$(LINK_MLX) $(LINK_FT)

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
	@$(MKDIR) $(OBJ_DIR)
	$(COMPILE) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT) bonus
	@$(MAKE) -C $(MLX_DIR)
	$(COMPILE) $^ $(LINKING) -o $@

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
