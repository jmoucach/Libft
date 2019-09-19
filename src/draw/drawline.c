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

void setup_param(t_point pt_one, t_point pt_two, t_line_param *line_param)
{
	line_param->diff.x = ft_abs(pt_two.x - pt_one.x);
	line_param->diff.y = ft_abs(pt_two.y - pt_one.y);
	line_param->off = line_param->diff.x - line_param->diff.y;
	line_param->inc.x = (pt_one.x < pt_two.x ? 1 : -1);
	line_param->inc.y = (pt_one.y < pt_two.y ? 1 : -1);
}

Uint32 *drawline(t_point pt_one, t_point pt_two, Uint32 *pixels)
{
	t_point pt;
	t_line_param line_param;

	pt = pt_one;
	while (pt.x != pt_two.x || pt.y != pt_two.y)
	{
		pixels[pt.x + pt.y * SCREEN_WIDTH] = 255;
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
	pixels[pt.x + pt.y * SCREEN_WIDTH] = 255;
	return (pixels);
}
