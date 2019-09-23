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

void close_all(t_data *data, t_box **box)
{
	box_delete(box);
	SDL_DestroyRenderer(data->renderer);
	SDL_DestroyTexture(data->texture);
	SDL_DestroyWindow(data->window);
	SDL_Quit();
}

int create_box_list(t_box **box)
{
	t_point pt;
	int boxNumberWidth;
	int boxNumberHeight;
	t_box *new_box;
	int i;

	new_box = NULL;
	pt.y = 0;
	i = 0;
	boxNumberWidth = SCREEN_WIDTH / BOX_SIZE;
	boxNumberHeight = SCREEN_HEIGHT / BOX_SIZE;
	(*box) = box_new((t_point){0, 0}, BOX_SIZE, -1);
	printf("Initialization of boxes\n");
	while (pt.y < SCREEN_HEIGHT)
	{
		pt.x = 0;
		while (pt.x < SCREEN_WIDTH)
		{
			if (!( *box = box_add_back(*box, new_box, pt, i)))
				return 0;
			pt.x += BOX_SIZE;
			i++;
		}
		pt.y += BOX_SIZE;
	}
	return 1;
}

void check_box_list(t_box *box)
{
	int i;

	i =0;
	while (box)
	{
		printf("Box number %d : postion: x:%d, y:%d\n", i, box->position.x, box->position.y);

		i++;
		box = box->next;
	}
}

int main(int ac, char **av)
{
	t_data data;
	t_box *box;
	
	(void)ac;
	(void)av;
	data.renderer = NULL;
	data.texture = NULL;
	data.window = NULL;
	data.quit = 0;
	data.pixels = (Uint32 *)malloc(sizeof(Uint32) * SCREEN_WIDTH * SCREEN_HEIGHT);
	if (init(&data))
	{
		if (create_box_list(&box))
		{
		//	check_box_list(box);
			while (!data.quit)
			{
				while (SDL_PollEvent(&data.event))
				{
					if (data.event.type == SDL_QUIT)
						data.quit = 1;
					if (data.event.type == SDL_MOUSEBUTTONDOWN)
						if (data.event.button.button == SDL_BUTTON_LEFT)
							box_toggle_state((t_point){data.event.motion.x / BOX_SIZE,
													   data.event.motion.y / BOX_SIZE},
											 &box);
				}
				box_show_to_sdl(box, data.pixels);
				SDL_UpdateTexture(data.texture, NULL, data.pixels, SCREEN_WIDTH * sizeof(Uint32));
				SDL_RenderClear(data.renderer);
				SDL_RenderCopy(data.renderer, data.texture, NULL, NULL);
				SDL_RenderPresent(data.renderer);
			}
		}
		close_all(&data, &box);
	}
	else
	{
		ft_putstr_fd("Error in initialization!", 2);
	}
	return (1);
}
