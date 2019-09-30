/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 15:03:28 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/30 18:25:46 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

#include "Wolf3d.h"

/*
** INIT
*/

short	init(t_data *data);
void	set_values(t_data *data, t_player *player);

/*
** Draw
*/

void	draw_rect_to_sdl(t_point pt_one, t_point pt_two, t_data *data, int colour);
void setup_param(t_point pt_one, t_point pt_two, t_line_param *line_param);
void	drawline(t_point pt_one, t_point pt_two, t_data *data, int colour);

/*
** Main
*/

void	close_all(t_data *data);


/*
** New map
*/

char *join_strings(char *s1, char *s2);
short	count_lines_and_col(t_data *data, char *str);
// short	get_map_size(t_data *data, char *str);
short	new_map(t_data *data, char *title);

/*
** Fill map
*/

// void	print_map(t_data *data);
// char *read_again(char *title);
// short	fill_map(t_data *data, char *str);

/*
** Raycast
*/

void	cast_ray(int worldMap[30][40], t_data *data, t_player player);

#endif
