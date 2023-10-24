/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking_borders.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 17:57:31 by dsydelny          #+#    #+#             */
/*   Updated: 2023/10/25 00:17:40 by dsydelny         ###   ########.fr       */
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

int	nospc(char c)
{
	if (c != ' ' && c != '\n' && c != '\t')
		return (1);
	return (0);
}

int	check_borders(t_data *data)
{
	int	x;
	int	y;
	int	len;
	int	height;
	
	x = 1;
	len_map(data);
	len = data->len_map - 1;
	height = data->h_map - 1;
	while (data->work_map[x] && x < height)
	{
		y = 1;
		while (data->work_map[x][y] && y < len)
		{
			if (data->work_map[x][y] == ' ' || data->work_map[x][y] == '1' || data->work_map[x][y] == '\n')
				y++;
			else if (x > zero_or_letter(data->work_map[x][y]) &&  nospc(data->work_map[x - 1][y]) && nospc(data->work_map[x + 1][y]) &&
				nospc(data->work_map[x][y - 1]) && nospc(data->work_map[x][y + 1]))
				y++;
			else
				return (printf("suka\n"), -1);
		}
		x++;
	}
	return (0);
}


// check first column, last row, last colum
//handle spaces after xpm
//floodfill???
//islands on map??
// floor ceill - can be spaces between r g b??
