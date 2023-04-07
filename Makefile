# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/17 13:17:08 by junhelee          #+#    #+#              #
#    Updated: 2023/04/07 15:44:57 by junhelee         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	cub3D

SRCS_DIR:=	./src
SRCS	:=	$(addsuffix .c,	cub3d hook error\
							config/config config/conf_free config/conf_image config/conf_color config/conf_map config/conf_cmap\
							map/map_parser map/map_elem map/map_utils map/map_error\
							validate/validate_img validate/validate_color validate/validate_map validate/validate_wall\
							play/calculate play/move play/ray\
							draw/draw_2d draw/draw_3d draw/render draw/image)

BONUS_SRCS_DIR:=	./src_bonus
BONUS_SRCS	:=	$(addsuffix _bonus.c,	cub3d hook error\
							config/config config/conf_free config/conf_image config/conf_color config/conf_map config/conf_cmap\
							map/map_parser map/map_elem map/map_utils map/map_error\
							validate/validate_img validate/validate_color validate/validate_map validate/validate_wall\
							play/calculate play/move play/ray\
							draw/draw_2d draw/draw_3d draw/render draw/image)

CC		:=	cc
CFLAGS	:=	-Wall -Wextra -Werror
COMPILE	:=	$(CC) $(CFLAGS)

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
O_DIRS	:=	$(OBJ_DIR) $(addprefix $(OBJ_DIR)/, config map validate play draw)
OBJS	:=	$(patsubst %,$(OBJ_DIR)/%,$(SRCS:%.c=%.o))

BONUS_OBJS:=	$(patsubst %,$(OBJ_DIR)/%,$(BONUS_SRCS:%.c=%.o))

LINK_FT	:=	-L$(LIBFT) -lft
ifeq ($(UNAME_S), Darwin)
LINK_MLX:=	-L$(MLX_DIR) -lmlx -framework OpenGL -framework APPKit
else
LINK_MLX:=	-L$(MLX_DIR) -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz
endif
LINKING	:=	$(LINK_MLX) $(LINK_FT)

all: $(NAME)

$(OBJ_DIR)/%.o : $(SRCS_DIR)/%.c
	@$(MKDIR) $(O_DIRS)
	$(COMPILE) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o : $(BONUS_SRCS_DIR)/%.c
	@$(MKDIR) $(O_DIRS)
	$(COMPILE) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT) bonus
	@$(MAKE) -C $(MLX_DIR)
	$(COMPILE) $^ $(LINKING) -o $@

$(NAME)_bonus: $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT) bonus
	@$(MAKE) -C $(MLX_DIR)
	$(COMPILE) $^ $(LINKING) -o $@

bonus: $(NAME)_bonus

clean:
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(BONUS_OBJS)

fclean: 
	@$(MAKE) -C $(LIBFT) fclean
	@$(MAKE) -C $(MLX_DIR) clean
	$(RM) $(OBJS)
	$(RM) $(NAME)
	$(RM) $(BONUS_OBJS)
	$(RM) $(NAME)_bonus

re:
	@$(MAKE) fclean
	@$(MAKE) all

norm:
	@$(NORM) ./include
	@$(NORM) $(SRCS_DIR)
	@$(NORM) $(BONUS_SRCS_DIR)

.PHONY: all clean fclean re norm bonus
