/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:42:29 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/29 23:30:00 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include "libft.h"
# include "error.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 1
# define FAIL -1
# define MALLOC_FAIL -2

# define IMG_EXT ".xpm"
# define IMG_EXT_SIZE 5

# define INVALID_EAST "Invaild data of EAST wall"
# define INVALID_WEST "Invaild data of WEST wall"
# define INVALID_SOUTH "Invaild data of SOUTH wall"
# define INVALID_NORTH "Invaild data of NORTH wall"
# define INVALID_CEILING "Invaild data of color of CEILING"
# define INVALID_FLOOR "Invaild data of color of FLOOR"
# define INVALID_MAP "Invaild MAP"

# define VALUE_IS_NULL ": This value is NULL"
# define IMG_MUST_BE ": The texture file must be "

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

typedef enum e_elem {
	EAST,
	WEST,
	SOUTH,
	NORTH,
	CEILING,
	FLOOR,
	MAP
}	t_elem;

typedef struct s_map_data {
	char	*texture_path[4];
	char	*color_str[2];
	char	*err_msg;
	t_elem	err_elem;
	int		map_max_width;
	int		map_max_height;
	t_list	*raw_map;
}	t_map_data;

void	init_map_data(t_map_data *const data);
void	set_map_data(int fd, t_map_data *const data);
void	free_map_data(t_map_data *const data);

// TODO: remove
void	print_map_data(t_map_data data);

//	map_elem.c
void	set_element(char *line, t_elem elem, t_map_data *const data);
t_elem	get_element_type(char *line);
void	set_raw_map(int fd, char *const line, t_map_data *const data);

//	map_error.c
int		set_err(t_map_data *const d, const t_elem e, const char *msg);
int		set_err_with_res(t_map_data *const d, const t_elem e, \
						const char *resource, const char *msg);
void	exit_invalid_elem(t_map_data *const data, void (*f)(const char *msg));
void	print_dynamic_err_msg(const char *msg);

//	map_utils.c
int		is_space(const unsigned char c);
int		is_empty_line(char *line);
void	free_2d(char **arr);
char	*ft_strrtrim(const char *str);

//	validate_color.c
int		validate_color_str(t_map_data *const data);
int		validate_color(t_map_data *const data, const char *str, const t_elem e);

//	validate_img.c
int		validate_img_ext(t_map_data *const data);

//	validate_map.c
int		validate_map_has_empty_line(t_map_data *const data);
int		validate_map_char(t_map_data *const data);
int		validate_map_only_one_player(t_map_data *const data);

#endif
