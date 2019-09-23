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
		if (box->id == (map.x  - map.x % BOX_SIZE) + (map.y - map.y % BOX_SIZE) * (SCREEN_WIDTH / BOX_SIZE) && box->exist)
			return 1;
		box = box->next;
	}
	return (0);
}

Uint32	*cast_ray(t_box *box, Uint32 *pixels)
{
	Uint32 *pix;

	pix = pixels;
	t_player player;

	player.posX = 50;
	player.posY = 50;
	player.dirX = -1;
	player.dirY = 0;
	player.planeX = 0;
	player.planeY = 0.66;

	// double time;
	// double old_time;

	int x;
	// int y;

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
		rayDirX = player.dirX + player.planeX * cameraX;
		rayDirY = player.dirY + player.planeY * cameraX;

		map.x = player.posX;
		map.y = player.posY;

		deltaDistX = ft_abs(1 / rayDirX);
		deltaDistY = ft_abs(1 / rayDirY);
		if (rayDirX < 0)
		{
			step.x = -1;
			sideDistX = (player.posX - map.x) * deltaDistX;
		}
		 else
		{
			step.x = 1;
			sideDistX = (map.x + 1.0 - player.posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			step.y = -1;
			sideDistY = (player.posY - map.y) * deltaDistY;
		}
		else
		{
			step.y = 1;
			sideDistY = (map.y + 1.0 - player.posY) * deltaDistY;
		}

		while (hit == 0)
		{
			printf("no hit\n");
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
			if (check_hit(map, box) > 0)
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (map.x - player.posX + (1-step.x)/2) / rayDirX;
		else	
			perpWallDist = (map.x - player.posY + (1 - step.y)/2) / rayDirY;
		lineHeight = (SCREEN_HEIGHT / perpWallDist);
		drawStart = -lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawStart < 0)
			drawStart = 0;
		drawEnd = lineHeight / 2 + SCREEN_HEIGHT / 2;
		if (drawEnd >= SCREEN_HEIGHT)
			drawEnd = SCREEN_HEIGHT - 1;
		if (side == 1)
			colour /= 2;
		pix = drawline((t_point){x, drawStart}, (t_point){x, drawEnd}, pix, colour);
		x++;
	}
	return (pix);
}
