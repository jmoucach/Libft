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

typedef	struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef	struct 		s_d_point
{
	double			x;
	double			y;
}					t_d_point;

typedef	struct		s_line_param
{
	t_point			diff;
	t_point			inc;
	int				error;
	int				off;
}					t_line_param;

typedef	struct		s_player
{
	t_d_point		pos;
	t_d_point		dir;
	t_d_point		plane;
	double			walkSpeed;
	double			rotSpeed;
}					t_player;

typedef	struct		s_data
{
	SDL_Window		*window;
	SDL_Surface		*surface;
	SDL_Event		event;
	int				**map;
	t_point			mapSize;
	int				box_length;
	short			quit;
}					t_data;

#endif
