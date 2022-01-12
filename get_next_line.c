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

/*
	Function get_next_line will read a file and return a line read.
*/

int	get_next_line(const int fd, char **line)
{
	char		*temp;
	static char	buffer;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	
}
