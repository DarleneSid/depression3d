/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_borders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:57:31 by dsydelny          #+#    #+#             */
/*   Updated: 2023/10/22 00:32:58 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	zero_or_letter(char c)
{
	if (c == '0')
		return (1);
	else if (c == 'N')
		return (1);
	else if (c == 'S')
		return (1);
	else if (c == 'E')
		return (1);
	else if (c == 'W')
		return (1);
	else
		return (0);
}

void	len_map(t_data *data)
{
	int	i;
	int	j;
	
	i = 0;
	data->len_map = 0;
	while (data->work_map[i] && i < data->h_map)
	{
		j = 0;
		while (data->work_map[i][j] && data->work_map[i][j] != '\n')
			j++;
		if (j > data->len_map)
			data->len_map = j;
		i++;
	}
}

int	check_borders(t_data *data)
{
	int	x;
	int	y;
	
	x = 1;
	len_map(data);
	printf("%d\n", data->len_map);
	while (data->work_map[x] && x < data->len_map)
	{
		y = 1;
		while (data->work_map[x][y] && y < data->h_map)
		{
			if (zero_or_letter(data->work_map[x][y]) &&  data->work_map[x - 1][y] != ' ' &&
				data->work_map[x + 1][y] != ' ' && data->work_map[x - 1][y - 1] != ' ' && data->work_map[x][y - 1] != ' ' &&
				data->work_map[x + 1][y - 1] != ' ' && data->work_map[x - 1][y + 1] != ' ' && data->work_map[x][y + 1] != ' ' &&
				data->work_map[x + 1][y + 1] != ' ')
				y++;
			else if (data->work_map[x][y] == ' ' || data->work_map[x][y] == '1')
				y++;
			else
				return (printf("suka\n"), -1);
		}
		x++;
	}
	return (0);
}
