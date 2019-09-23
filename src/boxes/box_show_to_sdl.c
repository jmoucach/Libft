/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_show_to_sdl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:04:48 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/23 12:04:49 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

Uint32 *box_show_to_sdl(t_box *box, Uint32 *pixels)
{
	Uint32 *pix;

	pix = pixels;
	while (box)
	{
		if (box->exist)
			pix = draw_rect_to_sdl(box->position, (t_point)
				{box->position.x + box->length - 1, box->position.y + box->length - 1},
				pix, 255);
		else
			pix = draw_rect_to_sdl(box->position, (t_point)
				{box->position.x + box->length - 1, box->position.y + box->length - 1},
				pix, 0);	
		box = box->next;
	}
	return (pix);
}
