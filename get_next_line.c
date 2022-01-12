/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:25:28 by pskytta           #+#    #+#             */
/*   Updated: 2022/01/10 14:24:59 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

static int	join_line(char **line, char **str)
{
	size_t	length;
	char	*temp;

	length = 0;
	while ((*str)[length] != '\n' && (*str)[length] != '\0')
		length++;
	if ((*str)[length] == '\n')
	{
		*line = ft_strsub(*str, 0, length);
		temp = ft_strdup(&((*str)[length + 1]));
		free(*str);
		*str = temp;
		if ((*str)[0] == '\0')
		{
			ft_strdel(str);
		}
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	check_ret_value(int fd, char **line, int ret, char **str)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && str[fd] == NULL)
	{
		return (0);
		printf("EOF reached\n");
	}
	else
		return (join_line(line, &str[fd]));
}

int	get_next_line(const int fd, char **line)
{
	static char		*str[FD_SIZE];
	char			*temp;
	char			buffer[BUFF_SIZE + 1];
	int				ret;
	
	if (fd < 0 || line == NULL)
		return (-1);
	ret = read(fd, buffer, BUFF_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (str[fd] == NULL)
			str[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(str[fd], buffer);
			free(str[fd]);
			str[fd] = temp;
		}
		if (ft_strchr(str[fd], '\n'))
			break ;
		ret = read(fd, &buffer, BUFF_SIZE);
	}
	return (check_ret_value(fd, line, ret, str));
}