/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 15:25:28 by pskytta           #+#    #+#             */
/*   Updated: 2022/01/25 18:39:15 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	line_return(int ret, char **str, char **line)
{
	size_t	nl_position;
	char	*temp;

	if (ret == 0 && *str == NULL)
		return (0);
	nl_position = (size_t)(ft_strchr(*str, '\n') - *str);
	if (ft_strchr(*str, '\n'))
	{
		*line = ft_strsub(*str, 0, nl_position);
		temp = ft_strdup(&((*str)[nl_position + 1]));
		ft_strdel(str);
		*str = temp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
	}
	else
	{
		*line = ft_strdup(*str);
		ft_strdel(str);
	}
	return (1);
}

static int	buff_handler(int fd, char **str, char **buff)
{
	int		ret;
	char	*temp;

	ret = read(fd, *buff, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	while (ret > 0)
	{
		(*buff)[ret] = '\0';
		if (*str == NULL)
			*str = ft_strdup(*buff);
		else
		{
			temp = ft_strjoin(*str, *buff);
			ft_strdel(str);
			*str = temp;
		}
		if (ft_strchr(*str, '\n'))
			break ;
		ret = read(fd, *buff, BUFF_SIZE);
	}
	ft_strdel(buff);
	return (ret);
}

int	get_next_line(const int fd, char **line)
{
	static char		*string[FD_SIZE];
	char			*buff;
	int				ret;

	buff = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (buff == NULL)
		return (0);
	if (fd < 0 || line == NULL || BUFF_SIZE < 0 || fd > FD_SIZE)
		return (-1);
	ret = buff_handler(fd, &string[fd], &buff);
	if (ret < 0)
		return (-1);
	return (line_return(ret, &string[fd], line));
}
