/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 16:27:49 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/19 16:27:50 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void	draw_to_pixel(t_data *data, int colour, t_point pt)
{
	unsigned char *pixels = data->surface->pixels;
	int blue;
	int green;
	int red;

	blue = 0;
	green = 1;
	red = 2;
	SDL_LockSurface(data->surface);
	pixels[4*(data->surface->w * pt.y +pt.x) + red] = colour >> 16 & 0xff;
	pixels[4*(data->surface->w * pt.y +pt.x) + green] = colour >> 8 & 0xff;
	pixels[4*(data->surface->w * pt.y +pt.x) + blue] = colour & 0xff;
	SDL_UnlockSurface(data->surface);
}

void setup_param(t_point pt_one, t_point pt_two, t_line_param *line_param)
{
	line_param->diff.x = ft_abs(pt_two.x - pt_one.x);
	line_param->diff.y = ft_abs(pt_two.y - pt_one.y);
	line_param->off = line_param->diff.x - line_param->diff.y;
	line_param->inc.x = (pt_one.x < pt_two.x ? 1 : -1);
	line_param->inc.y = (pt_one.y < pt_two.y ? 1 : -1);
}

void	drawline(t_point pt_one, t_point pt_two, t_data *data, int colour)
{
	t_point pt;
	t_line_param line_param;

	setup_param(pt_one, pt_two, &line_param);
	pt = pt_one;
	while (pt.x != pt_two.x || pt.y != pt_two.y)
	{
		draw_to_pixel(data, colour, pt);
		if ((line_param.error = line_param.off * 2) > -line_param.diff.y)
		{
			line_param.off -= line_param.diff.y;
			pt.x += line_param.inc.x;
		}
		if (line_param.error <= line_param.diff.x)
		{
			line_param.off += line_param.diff.x;
			pt.y += line_param.inc.y;
		}
	}
	draw_to_pixel(data, colour, pt);
}
