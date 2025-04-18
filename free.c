/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:24:38 by schennal          #+#    #+#             */
/*   Updated: 2024/06/29 14:30:16 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

static void free_textures(t_data *data)
{
    mlx_destroy_image(data->window.mlx, data->no_img.img);
    mlx_destroy_image(data->window.mlx, data->so_img.img);
    mlx_destroy_image(data->window.mlx, data->we_img.img);
    mlx_destroy_image(data->window.mlx, data->ea_img.img);
    mlx_destroy_image(data->window.mlx, data->floor_img.img);
    mlx_destroy_image(data->window.mlx, data->gun.img);
}

void	free_memory(t_parse *parse, t_data *data)
{
	free_textures(data);
	if (parse->north_wall)
		free(parse->north_wall);
	if (parse->south_wall)
		free(parse->south_wall);
	if (parse->west_wall)
		free(parse->west_wall);
	if (parse->east_wall)
		free(parse->east_wall);
	if (parse->text)
		free_double_array(&parse->text);
	if (parse->map)
		free_double_array(&parse->map);
	(void)data;
}
