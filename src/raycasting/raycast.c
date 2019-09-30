/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:19:42 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/23 18:19:43 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"



short	check_hit(t_point map, t_box *box)
{
	while (box != NULL)
	{
		if (box->id == ceil((double)(map.x/BOX_SIZE)) + ceil((double)(map.y / BOX_SIZE)) * (SCREEN_WIDTH / BOX_SIZE) && box->exist)
		{
		// printf("map.x:%d, map.y:%d, box id:%d\n", map.x, map.y, box->id);
			// SDL_Delay(20000);
			return 1;
		}
		box = box->next;
	}
	return (0);
}

void	cast_ray(int worldMap[30][40], t_data *data, t_player player)
{
	int x;

	double cameraX;

	double rayDirX;
	double rayDirY;

	t_point map;

	double sideDistX;
	double sideDistY;

	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	t_point step;
	int hit;
	int side;

	int lineHeight;

	int drawStart;
	int drawEnd;

	int colour;


	colour = 255;
	x = 0;
	while (x < SCREEN_WIDTH)
	{
		cameraX = 2 * x / (SCREEN_WIDTH) - 1;
		rayDirX = player.dir.x + player.plane.x * cameraX;
		rayDirY = player.dir.y + player.plane.y * cameraX;

		map.x = player.pos.x;
		map.y = player.pos.y;

		deltaDistX = ft_abs(1 / rayDirX);
		deltaDistY = ft_abs(1 / rayDirY);
		if (rayDirX < 0)
		{
			step.x = -1;
			sideDistX = (player.pos.x - map.x) * deltaDistX;
		}
		 else
		{
			step.x = 1;
			sideDistX = (map.x + 1.0 - player.pos.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			step.y = -1;
			sideDistY = (player.pos.y - map.y) * deltaDistY;
		}
		else
		{
			step.y = 1;
			sideDistY = (map.y + 1.0 - player.pos.y) * deltaDistY;
		}
		hit = 0;
		while (hit == 0)
		{
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				map.x += step.x;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				map.y += step.y;
				side = 1;
			}
			// if (check_hit(map, box) > 0)
			// printf("map.x:%d y:%d\n", map.x, map.y);
			if (map.x >= 0 && map.y >= 0 && worldMap[map.x][map.y] > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (map.x - player.pos.x + (1-step.x)/2) / rayDirX;
		else	
			perpWallDist = (map.x - player.pos.y + (1 - step.y)/2) / rayDirY;
		// printf("perpWallDist:%f, mapX:%d\n", perpWallDist, map.x);
		lineHeight = (SCREEN_HEIGHT / perpWallDist);
		if (lineHeight < 0)
			lineHeight = 0;
		drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;
		if (side == 1)
			colour /= 2;
			 printf("x:%d drawStart:%d, drawEnd:%d, lineHeight:%d\n", x, drawStart, drawEnd, lineHeight);
		drawline((t_point){x, drawStart}, (t_point){x, drawEnd}, data, colour);

		x++;
	}
}
