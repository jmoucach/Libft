/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 14:19:39 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/19 14:19:40 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "Wolf3d.h"

typedef	struct		s_data
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	SDL_Event		event;
	Uint32			*pixels;
	short			quit;
}					t_data;

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef	struct		s_line_param
{
	t_point			diff;
	t_point			inc;
	int				error;
	int				off;
}					t_line_param;

typedef	struct		s_box
{
	t_point			position;
	int				id;
	short			length;
	short			exist;
	struct	s_box	*next;
}					t_box;

typedef	struct		s_player
{
	t_point position;
	t_point direction;
	double	planeX;
	double	planeY;
}					t_player;

#endif
