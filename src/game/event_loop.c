/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:48:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/08 19:33:08 by jmoucach         ###   ########.fr       */
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
				if (data->event.key.keysym.sym == SDLK_UP) // forward movement with 'W' key
				{
					if (data->map[(int)data->player.pos.y][(int)(data->player.pos.x + data->player.dir.x * data->player.walkSpeed)].value == 0)
						data->player.pos.x += data->player.dir.x * data->player.walkSpeed;
					if (data->map[(int)(data->player.pos.y + data->player.dir.y * data->player.walkSpeed)][(int)data->player.pos.x].value == 0)
						data->player.pos.y += data->player.dir.y * data->player.walkSpeed;
					printf("PosX:%f, PosY:%f\n", data->player.pos.x, data->player.pos.y);
				}

				if (data->event.key.keysym.sym == SDLK_DOWN) // backward movement with 'S' key
				{
					if (data->map[(int)data->player.pos.y][(int)(data->player.pos.x - data->player.dir.x * data->player.walkSpeed)].value == 0)
						data->player.pos.x -= data->player.dir.x * data->player.walkSpeed;
					if (data->map[(int)(data->player.pos.y - data->player.dir.y * data->player.walkSpeed)][(int)data->player.pos.x].value == 0)
						data->player.pos.y -= data->player.dir.y * data->player.walkSpeed;
					printf("PosX:%f, PosY:%f\n", data->player.pos.x, data->player.pos.y);
				}

				if (data->event.key.keysym.sym == SDLK_RIGHT) // rotate to the right with 'D' key
				{
					double oldDirX = data->player.dir.x;
					data->player.dir.x = data->player.dir.x * cos(-data->player.rotSpeed) - data->player.dir.y * sin(-data->player.rotSpeed);
					data->player.dir.y = oldDirX * sin(-data->player.rotSpeed) + data->player.dir.y * cos(-data->player.rotSpeed);

					double oldPlaneX =data->player. plane.x;
					data->player.plane.x = data->player.plane.x * cos(-data->player.rotSpeed) - data->player.plane.y * sin(-data->player.rotSpeed);
					data->player.plane.y = oldPlaneX * sin(-data->player.rotSpeed) + data->player.plane.y * cos(-data->player.rotSpeed);
					printf("DirX:%f, DirY:%f\n", data->player.dir.x, data->player.dir.y);
				}

				if (data->event.key.keysym.sym == SDLK_LEFT) // rotate to the left with 'A' key
				{
					double oldDirX = data->player.dir.x;
					data->player.dir.x = data->player.dir.x * cos(data->player.rotSpeed) - data->player.dir.y * sin(data->player.rotSpeed);
					data->player.dir.y = oldDirX * sin(data->player.rotSpeed) + data->player.dir.y * cos(data->player.rotSpeed);

					double oldPlaneX =data->player.plane.x;
					data->player.plane.x = data->player.plane.x * cos(data->player.rotSpeed) - data->player.plane.y * sin(data->player.rotSpeed);
					data->player.plane.y = oldPlaneX * sin(data->player.rotSpeed) + data->player.plane.y * cos(data->player.rotSpeed);
					printf("DirX:%f, DirY:%f\n", data->player.dir.x, data->player.dir.y);
				}
			}
		}
		cast_ray(data);
		// draw_map_box(data);
		// show_player(data);
		SDL_UpdateTexture(data->texture, NULL, data->pixels, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(data->renderer);
		SDL_RenderCopy(data->renderer, data->texture, NULL, NULL);
		SDL_RenderPresent(data->renderer);
		ft_bzero(data->pixels, (SCREEN_WIDTH * SCREEN_HEIGHT + 1) * 4);
		time = SDL_GetTicks();
	}
}
