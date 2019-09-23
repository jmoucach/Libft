/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:00:42 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/23 12:00:43 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BOX_H
# define BOX_H

# include "Wolf3d.h"

# define BOX_SIZE 32

t_box	*box_new(t_point position, short length, int id);
t_box *box_add_back(t_box *box, t_box *new_box, t_point pt, int id);
void box_delete(t_box **box);
void	box_toggle_state(t_point pos, t_box **box);
Uint32 *box_show_to_sdl(t_box *box, Uint32 *pixels);

#endif
