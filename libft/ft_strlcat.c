/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:50:04 by schennal          #+#    #+#             */
/*   Updated: 2024/06/29 13:50:04 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dest_len;
	size_t	src_len;

	index = 0;
	src_len = ft_strlen(src);
	if (!dst && size == 0)
		return (src_len);
	dest_len = ft_strlen(dst);
	if (size <= dest_len)
		return (size + src_len);
	while (src[index] != '\0' && ((dest_len + 1) < size))
	{
		dst[dest_len] = src[index];
		index++;
		dest_len++;
	}
	dst[dest_len] = '\0';
	return (dest_len + ft_strlen(&src[index]));
}
