/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:42:47 by schennal          #+#    #+#             */
/*   Updated: 2024/06/29 13:42:47 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num_len(long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int			len;
	char		*str;
	const char	*digits = "0123456789";

	len = 1;
	if (n != 0)
		len = ft_num_len(n);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	str[len--] = '\0';
	if (n == 0)
		str[0] = '0';
	if (n < 0)
		str[0] = '-';
	while (n)
	{
		if (n > 0)
			str[len--] = digits[n % 10];
		else
			str[len--] = digits[n % 10 * -1];
		n /= 10;
	}
	return (str);
}
