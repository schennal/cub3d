/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schennal <schennal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 17:23:39 by schennal          #+#    #+#             */
/*   Updated: 2024/06/07 23:38:02 by schennal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3D.h"

int main(int ac, char **av)
{
	t_data data;
	t_parse	parse;

	if (ac != 2)
	{
		printf("Usage: %s <map_file>\n", av[0]);
		printf("Wrong arguments");
		return (EXIT_FAILURE);		
	}
	if (!ft_parse(&parse, av[1])) 
		return (EXIT_FAILURE);
		
		data.parse = &parse;
		
		init(&data);
		
		let_the_game_begin(&data, &data.ray); //cast_rays
		
		setup_hooks(&data);
		//free(&data); // Free the memory allocated for data when done

		
		return (0);
}

int init(t_data *data)
{
		init_map(data);
		init_player(data);
		data->player.delta_x = cos(data->player.angle) * STEP_SIZE;
		data->player.delta_y = -sin(data->player.angle) * STEP_SIZE;
		init_keys(data);
		init_window(data);
		if(!init_texture(data->parse, data))
			return 0;
		//cast_rays(data, &data->ray);
		//setup_hooks(data);
		
		return (0);
}


void	free_memory(t_parse *parse, t_data *data)
{
	if (parse->no_text)
		free(parse->no_text);
	if (parse->so_text)
		free(parse->so_text);
	if (parse->we_text)
		free(parse->we_text);
	if (parse->ea_text)
		free(parse->ea_text);
	if (parse->text)
		free_double_array(&parse->text);
	if (parse->map)
		free_double_array(&parse->map);
	(void)data;
}
