/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 14:51:49 by jmoucach          #+#    #+#             */
/*   Updated: 2019/10/01 15:23:51 by jmoucach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../hdr/Wolf3d.h"

void print_map(t_data data)
{
	int i;
	int j;

	i = 0;
	while (i < data.mapSize.y)
	{
		j = 0;
		while (j < data.mapSize.x)
		{
			printf("%d, ", data.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

short parse_map(char *str)
{
	int i;

	i = 0;

	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ',')
		{
			ft_putendl_fd("Invalid map data", 2);
			return (0);
		}
		i++;
	}
	return (1);
}

short fill_map(t_data *data, char *str)
{
	int i;

	if (!parse_map(str))
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '0' || str[i] == '1')
		{
			data->map[(i / 2) / data->mapSize.x][(i / 2) % data->mapSize.x] = str[i] - '0';
		}
		i++;
	}
	return (1);
}
