/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:42:29 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/22 17:04:03 by junhelee         ###   ########.fr       */
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
	char	*texture_path[4];
	char	*str_color_ceiling;
	char	*str_color_floor;
	int		map_max_width;
	int		map_max_height;
	t_list	*raw_map;
}	t_map_data;

int		is_space(const unsigned char c);
int		is_empty_line(char *line);

void	init_map_data(t_map_data *const data);
void	set_map_data(int fd, t_map_data *const data);
void	free_map_data(t_map_data *const data);

// TODO: remove
void	print_map_data(t_map_data data);

void	set_element(char *line, t_elem elem, t_map_data *const data);
t_elem	get_element_type(char *line);

#endif
