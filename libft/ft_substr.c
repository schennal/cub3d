/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:51:42 by schennal          #+#    #+#             */
/*   Updated: 2024/06/29 13:51:42 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;

	if (!s)
		return (0);
	i = start;
	while (s[i] != '\0' && (i - start) < len)
		i++;
	substring = (char *)malloc((i + 1 - start) * sizeof(char));
	if (!substring)
		return (0);
	i = 0;
	while (s[start] != '\0' && start < ft_strlen(s) && i < len)
	{
		substring[i++] = s[start++];
	}
	substring[i] = '\0';
	return (substring);
}
