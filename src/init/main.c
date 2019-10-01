/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:14:06 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/01 19:48:17 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void free_map(t_data *data)
{
	int i;

	i = data->mapSize.y;
	while (--i >= 0)
		free(data->map[i]);
	free(data->map);
}

void close_all(t_data *data)
{
	if (data->surface)
		SDL_FreeSurface(data->surface);
	if (data->window)
		SDL_DestroyWindow(data->window);
	SDL_Quit();
}

int main(int ac, char **av)
{
	t_data data;

	if (ac == 2)
	{
		set_values(&data);
		if (init(&data))
		{
			if (new_map(&data, av[1]))
			{
				while (!data.quit)
				{
					while (SDL_PollEvent(&data.event))
					{
						if (data.event.type == SDL_QUIT)
							data.quit = 1;
						if (data.event.type == SDL_KEYDOWN)
							if (data.event.key.keysym.sym == SDLK_ESCAPE)
								data.quit = 1;
					}
					// draw_map_box(&data);
					SDL_UpdateWindowSurface(data.window);
				}
				free_map(&data);
			}
			printf("Avant de free\n");
			close_all(&data);
		}
		else
		{
			ft_putstr_fd("Error in initialization!", 2);
		}
	}
	return (1);
}
