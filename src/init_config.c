/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_config.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 15:48:18 by junhelee          #+#    #+#             */
/*   Updated: 2023/03/18 18:21:13 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	_ft_strcmp(const char *str1, const char *str2)
{
	size_t			i;
	unsigned char	*b1;
	unsigned char	*b2;

	b1 = (unsigned char *)str1;
	b2 = (unsigned char *)str2;
	i = 0;
	while (b1[i] && b2[i])
	{
		if (b1[i] != b2[i] || b1[i] == 0 || b2[i] == 0)
			return (b1[i] - b2[i]);
		++i;
	}
	return (0);
}

static void	_check_extension(const char *const file_name)
{
	const char	*point_pos;
	int			fail;

	point_pos = file_name + ft_strlen(file_name) - 4;
	fail = _ft_strcmp(point_pos, ".cub");
	if (fail)
		exit(print_err(NAT_MATCH_EXTENSION));
}

void	init_config(char *const file_name, t_config *const data)
{
	int			fd;
	t_map_data	map_data;

	init_map_data(&map_data);
	_check_extension(file_name);
	fd = open(file_name, O_RDONLY);
	if (fd == FAIL_FD)
		exit(print_sys_err(SYS_FILE_OPEN_FAIL));
	set_map_data(fd, &map_data);
	(void)data;
	close(fd);
}
