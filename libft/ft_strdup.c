/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pskytta <pskytta@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 15:09:14 by pskytta           #+#    #+#             */
/*   Updated: 2021/12/16 16:33:25 by pskytta          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dup;
	size_t	length;

	length = ft_strlen(s1);
	dup = (char *)malloc(length + 1);
	ft_memset(dup, '\0', length);
	if (dup == NULL)
		return ((char *) NULL);
	ft_strcpy(dup, s1);
	return (dup);
}
