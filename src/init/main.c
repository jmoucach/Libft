/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:14:06 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/30 18:25:42 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void close_all(t_data *data)
{
	SDL_FreeSurface(data->surface);
	data->surface = NULL;
	SDL_DestroyWindow(data->window);
	data->window = NULL;
	SDL_Quit();
}

int main(int ac, char **av)
{
	t_data data;
	t_player player;

	// double oldDirX;
	// double oldPlaneX;
	if (ac == 2)
	{
		set_values(&data, &player);
		if (init(&data))
		{
			if (new_map(&data, av[1]))
			{
				while (!data.quit)
				{
					// player.walkSpeed = 5;
					// player.rotSpeed = 1;
					while (SDL_PollEvent(&data.event))
					{
						if (data.event.type == SDL_QUIT)
							data.quit = 1;
						// if (data.event.type == SDL_MOUSEBUTTONDOWN)
						// if (data.event.button.button == SDL_BUTTON_LEFT)
						// 	box_toggle_state((t_point){data.event.motion.x / BOX_SIZE,
						// 							   data.event.motion.y / BOX_SIZE},
						// 					 &box);
						// if (data.event.type == SDL_KEYDOWN)
						// {
						// 	if (data.event.key.keysym.sym == SDLK_UP)
						// 	{
						// 		if (player.pos.x + player.dir.x * player.walkSpeed > 0 && player.pos.x + player.dir.x * player.walkSpeed < 40 && worldMap[(int)(player.pos.x + player.dir.x * player.walkSpeed)][(int)(player.pos.y)] == 0)
						// 			player.pos.x += player.dir.x * player.walkSpeed;
						// 		if (player.pos.y + player.dir.y * player.walkSpeed > 0 && player.pos.y + player.dir.y * player.walkSpeed < 30 && worldMap[(int)(player.pos.x)][(int)(player.pos.y + player.dir.y * player.walkSpeed)] == 0)
						// 			player.pos.y += player.dir.y * player.walkSpeed;
						// 		printf("pos:x:%f,  y:%f\n", player.pos.x, player.pos.y);
						// 	}
						// 	if (data.event.key.keysym.sym == SDLK_DOWN)
						// 	{
						// 		if (player.pos.x - player.dir.x * player.walkSpeed > 0 && player.pos.x - player.dir.x * player.walkSpeed < 40 && worldMap[(int)(player.pos.x - player.dir.x * player.walkSpeed)][(int)(player.pos.y)] == 0)
						// 			player.pos.x -= player.dir.x * player.walkSpeed;
						// 		if (player.pos.y - player.dir.y * player.walkSpeed > 0 && player.pos.y - player.dir.y * player.walkSpeed < 30 && worldMap[(int)(player.pos.x)][(int)(player.pos.y - player.dir.y * player.walkSpeed)] == 0)
						// 			player.pos.y -= player.dir.y * player.walkSpeed;
						// 		printf("pos:x:%f,  y:%f\n", player.pos.x, player.pos.y);
						// 	}
						// 	if (data.event.key.keysym.sym == SDLK_RIGHT)
						// 	{
						// 		oldDirX = player.dir.x;
						// 		player.dir.x = player.dir.x * cos(-player.rotSpeed) - player.dir.y * sin(-player.rotSpeed);
						// 		player.dir.y = oldDirX * sin(-player.rotSpeed) + player.dir.y * cos(-player.rotSpeed);
						// 		oldPlaneX = player.plane.x;
						// 		player.plane.x = player.plane.x * cos(-player.rotSpeed) - player.plane.y * sin(-player.rotSpeed);
						// 		player.plane.y = player.plane.x * sin(-player.rotSpeed) + player.plane.y * cos(-player.rotSpeed);
						// 		printf("dir:x:%f,  y:%f\nplane:x:%f, y:%f\n", player.dir.x, player.dir.y, player.plane.x, player.plane.y);
						// 	}
						// 	if (data.event.key.keysym.sym == SDLK_LEFT)
						// 	{
						// 		oldDirX = player.dir.x;
						// 		player.dir.x = player.dir.x * cos(player.rotSpeed) - player.dir.y * sin(player.rotSpeed);
						// 		player.dir.y = oldDirX * sin(player.rotSpeed) + player.dir.y * cos(player.rotSpeed);
						// 		oldPlaneX = player.plane.x;
						// 		player.plane.x = player.plane.x * cos(player.rotSpeed) - player.plane.y * sin(player.rotSpeed);
						// 		player.plane.y = player.plane.x * sin(player.rotSpeed) + player.plane.y * cos(player.rotSpeed);
						// 		printf("dir:x:%f,  y:%f\nplane:x:%f, y:%f\n", player.dir.x, player.dir.y, player.plane.x, player.plane.y);
						// 	}
					}
					SDL_UpdateWindowSurface(data.window);
				}
			}
			close_all(&data);
			// print_map(&data);
		}
		else
		{
			ft_putstr_fd("Error in initialization!", 2);
		}
	}
	return (1);
}
