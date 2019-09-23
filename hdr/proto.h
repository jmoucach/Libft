/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:03:28 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/19 15:03:29 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

#include "Wolf3d.h"

/*
** INIT
*/

short	init(t_data *data);
void	create_renderer_and_texture(t_data *data);

/*
** Draw
*/

void setup_param(t_point pt_one, t_point pt_two, t_line_param *line_param);
Uint32 *drawline(t_point pt_one, t_point pt_two, Uint32 *pixels, int colour);

/*
** Main
*/

void	close_all(t_data *data, t_box **box);
int	create_box_list(t_box **box);

/*
** Draw Rect to SDL
*/

Uint32 *draw_rect_to_sdl(t_point pt_one, t_point pt_two, Uint32 *pixels, int colour);

/*
** Raycast
*/

Uint32	*cast_ray(t_box *box, Uint32 *pixels);
short	check_hit(t_point map, t_box *box);

#endif
