/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_what.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:09:26 by dsydelny          #+#    #+#             */
/*   Updated: 2023/10/20 23:59:37 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	is_floor(t_data *data, char *s)
{
	int		i;
	int		j;
	char	**ithinkdifferent;
	int number = 0;
	int count = 0;
	i = 2;
	j = 0;
	if (s[0] != 'F')
		return (-1);
	if (s[1] != ' ')
		return (-1);
	// 1 space or ???
	ithinkdifferent = ft_split(&s[i], ',');
	if (!ithinkdifferent)
		return (-1);
	while (ithinkdifferent[count])
	{
		number = ft_atoi(ithinkdifferent[count]);
		if (count == 0 && number >= 0 && number <= 255)
			data->f_r = number;
		else if (count == 1 && number >= 0 && number <= 255)
			data->f_g = number;
		else if (count == 2 && number >= 0 && number <= 255)
			data->f_b = number;
		else
			return (-1);
		count++;
	}
	free_dstr(ithinkdifferent);
	return (1);
}

int	is_ceiling(t_data *data, char *s)
{
	int		i;
	int		j;
	char	**ithinkdifferent;
	int number = 0;
	int count = 0;
	i = 2;
	j = 0;
	if (s[0] != 'C')
		return (-1);
	if (s[1] != ' ')
		return (-1);
	// 1 space or ???
	ithinkdifferent = ft_split(&s[i], ',');
	if (!ithinkdifferent)
		return (-1);
	while (ithinkdifferent[count])
	{
		number = ft_atoi(ithinkdifferent[count]);
		if (count == 0 && number >= 0 && number <= 255)
			data->c_r = number;
		else if (count == 1 && number >= 0 && number <= 255)
			data->c_g = number;
		else if (count == 2 && number >= 0 && number <= 255)
			data->c_b = number;
		else
			return (-1);
		count++;
	}
	free_dstr(ithinkdifferent);
	return (1);
}

// int	is_path(t_data *data, char *s)
// {
// 	int	i;

// 	i = 0;
// 	if (ft_strncmp(s, "NO ", 3))
// 	{
		
// 	}
// 	if (ft_strncmp(s, "SO ", 3))
// 	if (ft_strncmp(s, "EA ", 3))
// 	if (ft_strncmp(s, "WE ", 3))


	// if (ft_strncmp(char *path, ".xpm\0", 5))
	// 	return (ft_printf("Path has to end with .xpm!\n"), 1);
	
// }
