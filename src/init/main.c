/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:14:06 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/19 14:14:09 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void close_all(t_data *data)
{
	SDL_DestroyRenderer(data->renderer);
	SDL_DestroyTexture(data->texture);
	SDL_DestroyWindow(data->window);
	SDL_Quit();
}

int main(int ac, char **av)
{
	t_data data;

	(void)ac;
	(void)av;
	data.quit = 0;
	data.pixels = (Uint32 *)malloc(sizeof(Uint32) * SCREEN_WIDTH * SCREEN_HEIGHT);
	if (init(&data))
	{
		while (!data.quit)
		{
			while (SDL_PollEvent(&data.event))
			{
				if (data.event.type == SDL_QUIT)
					data.quit = 1;
				if (data.event.type == SDL_MOUSEBUTTONDOWN)
					if (data.event.button.button == SDL_BUTTON_LEFT)
						data.pixels = drawline((t_point){100, 100}, (t_point){400, 400}, data.pixels);
			}
			SDL_UpdateTexture(data.texture, NULL, data.pixels, SCREEN_WIDTH * sizeof(Uint32));
			SDL_RenderClear(data.renderer);
			SDL_RenderCopy(data.renderer, data.texture, NULL, NULL);
			SDL_RenderPresent(data.renderer);
		}
		close_all(&data);
	}
	else
	{
		ft_putstr_fd("Error in initialization!", 2);
	}
	return (1);
}
