/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:55:03 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/03 12:03:56 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void	show_player(t_data *data)
{
	Uint32 *pix;
	t_player player;

	player = data->player;
	pix = data->pixels;
	
	pix[(int)(player.pos.x + player.pos.y * SCREEN_WIDTH)] = 0xff0000;
	pix[(int)(player.pos.x + 1 + player.pos.y * SCREEN_WIDTH)] = 0xff0000;
	pix[(int)(player.pos.x + (player.pos.y+1) * SCREEN_WIDTH)] = 0xff0000;
	pix[(int)(player.pos.x-1 + player.pos.y * SCREEN_WIDTH)] = 0xff0000;
	pix[(int)(player.pos.x + (player.pos.y-1) * SCREEN_WIDTH)] = 0xff0000;
}
