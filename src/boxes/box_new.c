/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   box_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 11:49:36 by jmoucach          #+#    #+#             */
/*   Updated: 2019/09/23 11:49:37 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

t_box	*box_new(t_point position, short length, int id)
{
	t_box	*box;

	if (!(box = (t_box*)malloc(sizeof(t_box))))
	{
		return (NULL);
	}
	else
	{
		box->position = position;
		box->length = length;
		box->exist = 0;
		box->id = id;
		box->next = NULL;
	}
	return (box);
}
