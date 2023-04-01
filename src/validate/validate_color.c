/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sryou <sryou@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:22:30 by junhelee          #+#    #+#             */
/*   Updated: 2023/04/01 14:44:28 by sryou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_parser.h"

int	_validate_color_str(t_map_conf *const conf, const char *str, const t_elem e)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != ',' && (str[i] < '0' || '9' < str[i]))
			return (set_err_with_res(conf, e, str, COLOR_UNDEFINED));
		if (str[i] == ',')
			++cnt;
		++i;
	}
	if (cnt != 2)
		return (set_err_with_res(conf, e, str, COLOR_WRONG_NUM_OF_COMMA));
	if (i > 11)
		return (set_err_with_res(conf, e, str, COLOR_TOO_LONG));
	return (SUCCESS);
}

int	validate_color_str(t_map_conf *const conf)
{
	t_elem	e;

	e = CEILING;
	while (e <= FLOOR)
	{
		if (!conf->color_str[e - CEILING])
			return (set_err(conf, e, VALUE_IS_NULL));
		if (_validate_color_str(conf, conf->color_str[e - CEILING], e) == FAIL)
			return (FAIL);
		++e;
	}
	return (SUCCESS);
}

static int	_validate_out_of_range(const int val, char **to_free)
{
	if (val < 0 || 255 < val)
	{
		free_2d(to_free);
		return (FAIL);
	}
	return (SUCCESS);
}

int	validate_color(t_map_conf *const conf, const char *str, const t_elem e)
{
	char	**splitted;
	int		i;

	splitted = ft_split(str, ',');
	if (!splitted)
		exit_invalid_elem(conf, &perror);
	i = 0;
	while (splitted[i])
	{
		if (splitted[i][0] == '0' && splitted[i][1] != '\0')
		{
			free_2d(splitted);
			return (set_err_with_res(conf, e, str, COLOR_WEIRD_ZERO));
		}
		if (_validate_out_of_range(ft_atoi(splitted[i]), splitted) == FAIL)
			return (set_err_with_res(conf, e, str, COLOR_OUT_OF_RANGE));
		++i;
	}
	free_2d(splitted);
	if (i != 3)
		return (set_err_with_res(conf, e, str, COLOR_WRONG_NUMBERS));
	return (SUCCESS);
}
