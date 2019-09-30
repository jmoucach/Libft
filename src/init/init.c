/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:37:54 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/19 14:37:56 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void	set_values(t_data *data, t_player *player)
{
	player->pos.x = 5;
	player->pos.y = 5;
	player->dir.x = 1;
	player->dir.y = 0;
	player->plane.x = 0;
	player->plane.y = 0.66;
	data->surface = NULL;
	data->window = NULL;
	data->mapSize.x = 0;
	data->mapSize.y = 0;
	data->quit = 0;
}

short	init(t_data *data)
{
	short success;

	success = 1;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		ft_putstr_fd("Failed to initialize! Error:", 2);
		ft_putendl_fd(SDL_GetError(), 2);
		success = 0;
	}
	else
	{
		data->window = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (data->window != NULL)
		{
			data->surface = SDL_GetWindowSurface(data->window);
		}
		else
		{
			success = 0;
			ft_putstr_fd("Failed to create window! Error:", 2);
			ft_putendl_fd(SDL_GetError(), 2);
		}
	}
	return (success);
}
