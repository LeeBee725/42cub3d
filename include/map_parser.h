/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:42:29 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/18 18:20:59 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_PARSER_H
# define MAP_PARSER_H

# include "libft.h"

# define TRUE 1
# define FALSE 0

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
	const char	*texture_path[4];
	const char	*str_color_ceiling;
	const char	*str_color_floor;
	int			map_width;
	int			map_height;
	char		**map;
}	t_map_data;

int		is_space(const unsigned char c);
void	init_map_data(t_map_data *const data);
void	set_map_data(int fd, t_map_data *const data);

// TODO: remove
void	print_map_data(t_map_data data);

void	set_element(char *line, t_elem elem, t_map_data *const data);

#endif
