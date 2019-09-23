/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_add_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 12:02:52 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/23 12:03:50 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

t_box *box_add_back(t_box *box, t_box *new_box, t_point pt, int id)
{
	t_box *first;

	if (box)
	{
	first = box;
	while ((box)->next != NULL)
		box = (box)->next;
	if (!(new_box = box_new((t_point){pt.x, pt.y}, BOX_SIZE, id)))
				return NULL;
	new_box->next = NULL;
	(box)->next = new_box;
	return first;
	}
	else
	{
		if (!(new_box = box_new((t_point){pt.x, pt.y}, BOX_SIZE, id)))
				return NULL;
		return new_box;
	}
	
}
