/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:19:42 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/03 14:20:13 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void cast_ray(t_data *data)
{
	// int x;
	// double wcenter;
	// t_point map;
	// t_d_point rayDir;
	// t_d_point sideDist;
	// t_d_point deltaDist;
	// t_d_point step;
	// int lineHeight;
	// int drawStart;
	// int drawEnd;
	// double wallDist;
	// int side;
	// int hit;

	// x = 0;
	// while (x < SCREEN_WIDTH)
	// {
	// 	wcenter = 2 * x / SCREEN_WIDTH - 1;
	// 	rayDir.x = data->player.dir.x + data->player.plane.x * wcenter;
	// 	rayDir.x = data->player.dir.y + data->player.plane.y * wcenter;
	// 	map.x = data->player.pos.x / 16;
	// 	map.y = data->player.pos.y / 16;
	// 	deltaDist.y  = ft_abs(1 / rayDir.y);
	// 	deltaDist.x = ft_abs(1 /rayDir.x);
	// hit = 0;
	// 	if (rayDir.x < 0)
	// 	{
	// 		step.x = -1;
	// 		sideDist.x = (data->player.pos.x/16 - map.x) * deltaDist.x;
	// 	}
	// 	else
	// 	{
	// 		step.x = 1;
	// 		sideDist.x = (map.x + 1 - data->player.pos.x/16) * deltaDist.x;
	// 	}
	// 	if (rayDir.y < 0)
	// 	{
	// 		step.y = -1;
	// 		sideDist.y = (data->player.pos.y /16- map.y) * deltaDist.y;
	// 	}
	// 	else
	// 	{
	// 		step.y = 1;
	// 		sideDist.y = (map.y + 1 - data->player.pos.y/16) * deltaDist.y;
	// 	}
	// 	while (!hit)
	// 	{
	// 		if (sideDist.x < sideDist.y)
	// 		{
	// 			sideDist.x += deltaDist.x;
	// 			map.x += step.x;
	// 			side = 0;
	// 		}
	// 		else
	// 		{
	// 			sideDist.y += deltaDist.y;
	// 			map.y += step.y;
	// 			side = 1;
	// 		}
	// 		if (data->map[map.y][map.x] > 0)
	// 		{
	// 			hit = 1;
	// 		}
	// 	}
	// 	if (side == 0)
	// 		wallDist = (map.x - data->player.pos.x/16 + (1/ step.x)/ 2) / rayDir.x;
	// 	else
	// 		wallDist = (map.y - data->player.pos.y/16 + (1/ step.y)/ 2) / rayDir.y;
	// 		lineHeight = SCREEN_HEIGHT / wallDist;
		
	// 	drawStart = -lineHeight / 2 + SCREEN_HEIGHT /2;
	// 	drawEnd = lineHeight / 2 + SCREEN_HEIGHT /2;
	// 	drawline((t_point){x, drawStart}, (t_point){x, drawEnd}, data, 0xff);
	// 	x++;
	// }
	(void)data;
	return;
}