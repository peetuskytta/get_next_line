/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 14:30:33 by pskytta           #+#    #+#             */
/*   Updated: 2022/01/10 14:30:57 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define FD_SIZE 4096
# define BUFF_SIZE 32

# include "libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

int	get_next_line(const int fd, char **line);

#endif
