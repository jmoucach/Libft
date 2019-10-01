/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:48:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/01 18:18:16 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void game_loop(t_data *data)
{
	// while (!data->quit)
	// {
		while (SDL_PollEvent(&data->event))
		{
			if (data->event.type == SDL_QUIT)
				data->quit = 1;
			if (data->event.type == SDL_KEYDOWN)
			{
				if (data->event.key.keysym.sym == SDLK_ESCAPE)
					data->quit = 1;
			// 	else if (data->event.key.keysym.sym == SDLK_UP)
			// 	{
			// 		//Handle up arrow
			// 	}
			// 	else if (data->event.key.keysym.sym == SDLK_DOWN)
			// 	{
			// 		//Handle down arrow
			// 	}
			// 	else if (data->event.key.keysym.sym == SDLK_RIGHT)
			// 	{
			// 		//Handle right arrow
			// 	}
			// 	 else if (data->event.key.keysym.sym == SDLK_LEFT)
			// 	{
			// 		// Handle left arrow
			// 	}
			}
		}
		// cast_ray(&data);
	// 	if (!data->quit)
	// 	{
	// 		draw_map_box(data);
	// 		SDL_UpdateWindowSurface(data->window);
	// 	}
	// }
}
