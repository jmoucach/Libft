/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_toggle_state.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:33:42 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/23 12:33:43 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void box_toggle_state(t_point pos, t_box **box)
{
	t_box *first;
	int i;

	i = 0;

	first = *box;
	while (*box != NULL && (*box)->id != pos.x + pos.y * (SCREEN_WIDTH / BOX_SIZE))
	{
		i++;
		*box = (*box)->next;
	}
	if (*box)
	{
		if ((*box)->exist == 1)
			(*box)->exist = 0;
		else
			(*box)->exist = 1;
	}
	*box = first;
}
