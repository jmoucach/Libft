/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:55:03 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/08 19:18:34 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void	show_player(t_data *data)
{
	Uint32 *pix;
	t_player player;

	player = data->player;
	pix = data->pixels;
	
	pix[(int)(player.pos.x * 16 + player.pos.y * 16 * SCREEN_WIDTH)] = 0xff0000;
	pix[(int)(player.pos.x* 16 + 1 + player.pos.y * 16* SCREEN_WIDTH)] = 0xff0000;
	pix[(int)(player.pos.x* 16 + (player.pos.y* 16+1) * SCREEN_WIDTH)] = 0xff0000;
	pix[(int)((player.pos.x* 16-1) + player.pos.y* 16 * SCREEN_WIDTH)] = 0xff0000;
	pix[(int)(player.pos.x * 16+ (player.pos.y* 16-1) * SCREEN_WIDTH)] = 0xff0000;
}
