/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:48:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/09 15:23:36 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void game_loop(t_data *data)
{
	double time;
	double deltaTime;

	time = SDL_GetTicks();
	while (!data->quit)
	{
		deltaTime = SDL_GetTicks() - time;

		while (SDL_PollEvent(&data->event))
		{
			if (data->event.type == SDL_QUIT)
				data->quit = 1;
			if (data->event.type == SDL_KEYDOWN)
			{
				if (data->event.key.keysym.sym == SDLK_ESCAPE)
					data->quit = 1;
				if (data->event.key.keysym.sym == SDLK_UP)
				{
					if (data->map[data->player.pos.y - 1][data->player.pos.x].value == 0)
					{
						data->player.pos.y -= 1;
						data->player.screen_pos.y -= data->box_length;
					}
				}

				if (data->event.key.keysym.sym == SDLK_DOWN)
				{
					if (data->map[data->player.pos.y +1][data->player.pos.x].value == 0)
					{
						data->player.pos.y += 1;
						data->player.screen_pos.y += data->box_length;
					}
				}

				if (data->event.key.keysym.sym == SDLK_RIGHT)
				{
					if (data->map[data->player.pos.y][data->player.pos.x + 1].value == 0)
					{
						data->player.pos.x += 1;
						data->player.screen_pos.x += data->box_length;
					}
				}

				if (data->event.key.keysym.sym == SDLK_LEFT)
				{
					if (data->map[data->player.pos.y][data->player.pos.x - 1].value == 0)
					{
						data->player.screen_pos.x -= data->box_length;
						data->player.pos.x -= 1;
					}
				}
				if (data->event.key.keysym.sym == SDLK_a)// rotate to the left with 'A' key
				{
					data->player.angle -= M_PI / 180;
					if (data->player.angle < 0)
						data->player.angle = M_PI * 2 - 1;
				}
				if (data->event.key.keysym.sym == SDLK_d) // rotate to the left with 'A' key
				{
					data->player.angle += M_PI / 180;
					if (data->player.angle > M_PI * 2 - 1)
						data->player.angle = 0;
				}
			}
		}
		// cast_ray(data);
		draw_map_box(data);
		show_player(data);
		SDL_UpdateTexture(data->texture, NULL, data->pixels, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(data->renderer);
		SDL_RenderCopy(data->renderer, data->texture, NULL, NULL);
		SDL_RenderPresent(data->renderer);
		ft_bzero(data->pixels, (SCREEN_WIDTH * SCREEN_HEIGHT + 1) * 4);
		time = SDL_GetTicks();
	}
}
