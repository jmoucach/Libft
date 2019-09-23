/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rect_to_sdl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:16:31 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/23 11:16:34 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

Uint32 *draw_rect_to_sdl(t_point pt_one, t_point pt_two,
						 Uint32 *pixels, int colour)
{
	Uint32 *pix;
	t_point start_point;
	t_point end_point;

	start_point.x = (pt_one.x < pt_two.x ? pt_one.x : pt_two.x);
	start_point.y = (pt_one.y < pt_two.y ? pt_one.y : pt_two.y);
	end_point.x = (pt_one.x > pt_two.x ? pt_one.x : pt_two.x);
	end_point.y = (pt_one.y > pt_two.y ? pt_one.y : pt_two.y);
	pix = pixels;
	while (start_point.y++ < end_point.y)
	{
		pix = drawline(start_point, (t_point){end_point.x - 1, start_point.y},
					   pix, colour);
	}

	return (pix);
}
