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

void	create_renderer_and_texture(t_data *data)
{
	data->renderer = SDL_CreateRenderer(data->window, -1, 0);
	data->texture = SDL_CreateTexture(data->renderer,
		SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC,
		SCREEN_WIDTH, SCREEN_HEIGHT);
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
			create_renderer_and_texture(data);
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
