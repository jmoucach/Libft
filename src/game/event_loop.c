/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 17:48:43 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/03 14:18:14 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void game_loop(t_data *data)
{
	// double time;
	// double deltaTime;
	// double oldDirX;
	// double oldPlaneX;

	while (!data->quit)
	{
		// cast_ray(data);
		// deltaTime = SDL_GetTicks() - time;
		while (SDL_PollEvent(&data->event))
		{
			if (data->event.type == SDL_QUIT)
				data->quit = 1;
			if (data->event.type == SDL_KEYDOWN)
			{
				if (data->event.key.keysym.sym == SDLK_ESCAPE)
					data->quit = 1;
				// if (data->event.key.keysym.sym == SDLK_UP)
				// {
				// 	if (data->map[(int)(data->player.pos.x / 16 + data->player.dir.x * data->player.walkSpeed)][(int)data->player.pos.y / 16] == 0)
				// 		data->player.pos.x += data->player.dir.x * data->player.walkSpeed * 16;
				// 	if (data->map[(int)data->player.pos.x / 16][(int)(data->player.pos.y / 16 + data->player.dir.y * data->player.walkSpeed)] == 0)
				// 		data->player.pos.y += data->player.dir.y * data->player.walkSpeed * 16;
				// 	printf("pos:x:%f, y:%f\n", data->player.pos.x, data->player.pos.y);
				// }
				// if (data->event.key.keysym.sym == SDLK_DOWN)
				// {
				// 	if (data->map[(int)(data->player.pos.x / 16 - data->player.dir.x * data->player.walkSpeed)][(int)data->player.pos.y / 16] == 0)
				// 		data->player.pos.x -= data->player.dir.x * data->player.walkSpeed * 16;
				// 	if (data->map[(int)data->player.pos.x / 16][(int)(data->player.pos.y / 16 - data->player.dir.y * data->player.walkSpeed)] == 0)
				// 		data->player.pos.y -= data->player.dir.y * data->player.walkSpeed * 16;
				// 	printf("pos:x:%f, y:%f\n", data->player.pos.x, data->player.pos.y);
				// }
				// if (data->event.key.keysym.sym == SDLK_RIGHT)
				// {
				// 	oldDirX = data->player.dir.x;
				// 	data->player.dir.x = data->player.dir.x * cos(-data->player.rotSpeed) - data->player.dir.y * sin(-data->player.rotSpeed);
				// 	data->player.dir.y = oldDirX * sin(-data->player.rotSpeed) + data->player.dir.y * cos(-data->player.rotSpeed);
				// 	oldPlaneX = data->player.plane.x;
				// 	data->player.plane.x = data->player.plane.x * cos(-data->player.rotSpeed) - data->player.plane.y * sin(-data->player.rotSpeed);
				// 	data->player.plane.y = oldPlaneX * sin(-data->player.rotSpeed) + data->player.plane.y * cos(-data->player.rotSpeed);
				// }
				// if (data->event.key.keysym.sym == SDLK_LEFT)
				// {
				// 	oldDirX = data->player.dir.x;
				// 	data->player.dir.x = data->player.dir.x * cos(data->player.rotSpeed) - data->player.dir.y * sin(data->player.rotSpeed);
				// 	data->player.dir.y = oldDirX * sin(data->player.rotSpeed) + data->player.dir.y * cos(data->player.rotSpeed);
				// 	oldPlaneX = data->player.plane.x;
				// 	data->player.plane.x = data->player.plane.x * cos(data->player.rotSpeed) - data->player.plane.y * sin(data->player.rotSpeed);
				// 	data->player.plane.y = oldPlaneX * sin(data->player.rotSpeed) + data->player.plane.y * cos(data->player.rotSpeed);
				// }
			}
		}
		draw_map_box(data);
		show_player(data);
		SDL_UpdateTexture(data->texture, NULL, data->pixels, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(data->renderer);
		SDL_RenderCopy(data->renderer, data->texture, NULL, NULL);
		SDL_RenderPresent(data->renderer);
		ft_bzero(data->pixels, (SCREEN_WIDTH * SCREEN_HEIGHT + 1) * 4);
		// time = SDL_GetTicks();
	}
}
