/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:51:29 by schennal          #+#    #+#             */
/*   Updated: 2024/06/29 13:51:29 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	char	*start_str;
	char	*end_str;

	if (!s1)
		return (0);
	start_str = (char *)s1;
	end_str = start_str + ft_strlen(s1);
	while (*start_str != 0 && ft_strchr(set, *start_str))
		start_str++;
	while ((start_str < end_str) && ft_strchr(set, *(end_str - 1)))
		end_str--;
	result = ft_substr(start_str, 0, end_str - start_str);
	return (result);
}
