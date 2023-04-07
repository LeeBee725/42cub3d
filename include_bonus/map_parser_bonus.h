/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:42:29 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/07 16:52:32 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_BONUS_H
# define MAP_PARSER_BONUS_H

# include "libft.h"
# include "error_bonus.h"

# define SUCCESS 1
# define FAIL -1
# define MALLOC_FAIL -2

# define IMG_EXT ".xpm"
# define IMG_EXT_SIZE 5

# define INVALID_EAST "Invaild conf of EAST wall"
# define INVALID_WEST "Invaild conf of WEST wall"
# define INVALID_SOUTH "Invaild conf of SOUTH wall"
# define INVALID_NORTH "Invaild conf of NORTH wall"
# define INVALID_CEILING "Invaild conf of color of CEILING"
# define INVALID_FLOOR "Invaild conf of color of FLOOR"
# define INVALID_MAP "Invaild MAP"
# define INVALID_ELEM "Invalid Element"

# define VALUE_IS_NULL ": This value is NULL"
# define IMG_MUST_BE ": The texture file must be "
# define DOUBLE_KEYS ": The element is duplicated"
# define ELEM_INVALID ": The element is invalid"

# define COLOR_UNDEFINED ": Undefined character"
# define COLOR_WRONG_NUM_OF_COMMA ": Wrong number of comma"
# define COLOR_TOO_LONG ": String is too long"
# define COLOR_WEIRD_ZERO ": Weird zero"
# define COLOR_OUT_OF_RANGE ": Color value is out of range"
# define COLOR_WRONG_NUMBERS ": Number of value is wrong"

# define MAP_HAS_EMPTY_LINE ": There are empty lines in the map"
# define MAP_INVALID_CHAR ": The map has invalid character"
# define MAP_NOT_ONLY_ONE ": The map must have ONLY one player"
# define MAP_NOT_SURROUNDED_WALL ": The map must be closed/surrounded by walls"
# define MAP_NO_PLAYER ": There is no player"

typedef enum e_elem {
	EAST,
	WEST,
	SOUTH,
	NORTH,
	CEILING,
	FLOOR,
	MAP,
	ELEM_FAIL
}	t_elem;

typedef struct s_map_conf {
	char	*texture_path[4];
	char	*color_str[2];
	char	*err_msg;
	t_elem	err_elem;
	int		map_max_width;
	int		map_max_height;
	t_list	*raw_map;
}	t_map_conf;

//	map/map_elem.c
int		set_element(char *line, t_elem elem, t_map_conf *const conf);
t_elem	get_element_type(char *line);

//	map/map_error.c
int		set_err(t_map_conf *const d, const t_elem e, const char *msg);
int		set_err_with_res(t_map_conf *const d, const t_elem e, \
						const char *resource, const char *msg);
void	exit_invalid_elem(t_map_conf *const conf, void (*f)(const char *msg));
void	print_dynamic_err_msg(const char *msg);

//	map/map_parser.c
void	init_map_conf(t_map_conf *const conf);
void	set_map_conf(int fd, t_map_conf *const conf);
void	free_map_conf(t_map_conf *const conf);

//	map/map_rawmap.c
void	set_raw_map(int fd, char *const line, t_map_conf *const conf);

//	map/map_utils.c
int		is_space(const unsigned char c);
int		is_empty_line(char *line);
char	*ft_strrtrim(const char *str);

//	validate/validate_color.c
int		validate_color_str(t_map_conf *const map_conf);
int		validate_color(t_map_conf *const map_conf, const char *str, t_elem e);

//	validate/validate_img.c
int		validate_img_ext(t_map_conf *const conf);

//	validate/validate_map.c
int		validate_map_has_empty_line(t_map_conf *const conf);
int		validate_map_char(t_map_conf *const conf);
int		validate_map_one_player(t_map_conf *const conf);

#endif
