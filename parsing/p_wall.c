/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_wall.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 13:40:10 by schennal          #+#    #+#             */
/*   Updated: 2024/06/29 13:40:12 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

static int	st_idx(char **map, int j)
{
	int	i;

	i = 0;
	while (map[j][i])
	{
		if (map[j][i] != '1')
			i++;
		else
			return (i);
	}
	return (i);
}

static int	check_walls_1(t_parse *parse, char **map, int i, int j)
{
	if (j - 1 >= 0 && j - 1 < parse->ip_map.height)
	{
		if ((i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j - 1])) \
			&& (map[j - 1][i - 1] == '0') && (map[j - 1][i] != '1'))
			return (print_err(NULL, WALL_ERR, FAILURE), FAILURE);
		if ((i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j - 1])) \
			&& (map[j - 1][i + 1] == '0') && (map[j][i + 1] != '1'))
			return (print_err(NULL, WALL_ERR, FAILURE), FAILURE);
		if ((i >= 0 && i < (int)ft_strlen(map[j - 1])) \
			&& (map[j - 1][i] == '0'))
			return (print_err(NULL, WALL_ERR, FAILURE), FAILURE);
	}
	if ((i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j])) \
		&& (map[j][i - 1] == '0'))
		return (print_err(NULL, WALL_ERR, FAILURE), FAILURE);
	if ((i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j])) \
		&& (map[j][i + 1] == '0'))
		return (print_err(NULL, WALL_ERR, FAILURE), FAILURE);
	return (SUCCESS);
}

static int	check_walls_2(t_parse *parse, char **map, int i, int j)
{
	if (j + 1 >= 0 && j + 1 < parse->ip_map.height)
	{
		if ((i - 1 >= 0 && i - 1 < (int)ft_strlen(map[j + 1])) \
			&& (map[j + 1][i - 1] == '0') && (map[j + 1][i] != '1'))
			return (print_err(NULL, WALL_ERR, FAILURE), FAILURE);
		if ((i + 1 >= 0 && i + 1 < (int)ft_strlen(map[j + 1])) \
			&& (map[j + 1][i + 1] == '0') && (map[j][i + 1] != '1'))
			return (print_err(NULL, WALL_ERR, FAILURE), FAILURE);
		if ((i >= 0 && i < (int)ft_strlen(map[j + 1])) \
			&& (map[j + 1][i] == '0'))
			return (print_err(NULL, WALL_ERR, FAILURE), FAILURE);
	}
	return (SUCCESS);
}

static int	check_walls_3(t_parse *p, char **map, int i, int j)
{
	if ((j - 1 >= 0 && j - 1 < p->ip_map.height) && \
		(j + 1 >= 0 && j + 1 < p->ip_map.height))
	{
		if ((i - 1 >= 0 && i < (int)ft_strlen(map[j - 1])) && \
			(map[j - 1][i + 1] == '0'))
			return (print_err(NULL, WALL_ERR, FAILURE), FAILURE);
		if ((i >= 0 && i < (int)ft_strlen(map[j + 1])) && \
			(map[j + 1][i + 1] == '0'))
			return (print_err(NULL, WALL_ERR, FAILURE), FAILURE);
	}
	return (SUCCESS);
}

int	check_walls(t_parse *p, int j, int i)
{
	if (p->map[j][i] == ' ' && ((j + 1 < p->ip_map.height && \
	((st_idx(p->map, j + 1) > i || j == 0 || j == p->ip_map.height - 1 ||
		st_idx(p->map, j + 1) < i) && !check_front(p->map, j, i)))))
	{
		if (check_walls_1(p, p->map, i, j) == FAILURE)
			return (FAILURE);
		if (check_walls_2(p, p->map, i, j) == FAILURE)
			return (FAILURE);
	}
	else if (p->map[j][i] == ' ' && (j == p->ip_map.height - 1 || j == 0))
	{
		if (check_walls_1(p, p->map, i, j) == FAILURE)
			return (FAILURE);
		if (check_walls_2(p, p->map, i, j) == FAILURE)
			return (FAILURE);
	}
	else if (i == (int)ft_strlen(p->map[j]) - 1)
	{
		if (check_walls_3(p, p->map, i, j) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
