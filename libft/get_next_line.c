/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junhelee <junhelee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:00:02 by junhelee          #+#    #+#             */
/*   Updated: 2022/10/10 11:14:24 by junhelee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*_slice_line(char **str)
{
	char	*line;
	char	*nl_pos;
	char	*temp;
	size_t	len;

	if (!*str)
		return (NULL);
	line = NULL;
	len = ft_strlen(*str);
	nl_pos = ft_strchr(*str, '\n');
	if (nl_pos)
	{
		line = ft_strndup(*str, nl_pos - *str + 1);
		temp = *str;
		*str = ft_strndup(nl_pos + 1, len - (nl_pos - *str + 1));
		free(temp);
		return (line);
	}
	line = ft_strndup(*str, ft_strlen(*str));
	if (!*line)
	{
		free(line);
		line = NULL;
	}
	return (line);
}

static void	_stack_buf(char **str, char *buf)
{
	char	*temp;

	if (!buf)
		return ;
	if (!*str)
	{
		*str = ft_strndup(buf, ft_strlen(buf));
	}
	else
	{
		temp = *str;
		*str = ft_strjoin(*str, buf);
		free(temp);
	}
}

static char	*_get_line(int fd, char **remain)
{
	char	*buf;
	int		size;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	size = read(fd, buf, BUFFER_SIZE);
	while (size > 0)
	{
		buf[size] = '\0';
		_stack_buf(remain, buf);
		if (ft_strchr(*remain, '\n'))
		{
			free(buf);
			return (_slice_line(remain));
		}
		size = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*remain;
	static int	prev_fd;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (fd != prev_fd)
	{
		free(remain);
		remain = NULL;
		prev_fd = fd;
	}
	if (ft_strchr(remain, '\n'))
		return (_slice_line(&remain));
	line = _get_line(fd, &remain);
	if (!line && remain)
	{
		line = _slice_line(&remain);
		free(remain);
		remain = NULL;
	}
	return (line);
}
