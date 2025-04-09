/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:40:54 by schennal          #+#    #+#             */
/*   Updated: 2024/06/29 13:40:54 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;

	if (nmemb >= 65535 && size >= 65535)
		return (NULL);
	result = malloc(nmemb * size);
	if (!result)
		return (0);
	ft_bzero(result, (nmemb * size));
	return (result);
}
