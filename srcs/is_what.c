/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_what.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:09:26 by dsydelny          #+#    #+#             */
/*   Updated: 2023/10/27 01:28:57 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

int	is_floor(t_data *data, char *s)
{
	int		i;
	char	**ithinkdifferent;
	int number = 0;
	int count = 0;
	
	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] != 'F')
		return (-1);
	i++;
	if (s[i] != ' ')
		return (-1);
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
	char	**ithinkdifferent;
	int number = 0;
	int count = 0;
	i = 0;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	if (s[i] != 'C')
		return (-1);
	i++;
	if (s[i] != ' ')
		return (-1);
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

int	valid_for_path(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '1' || s[i] == ' ' || s[i] == '\t')
			i++;;
	if (s[i] == '\n' || s[i] =='\0')
		return (0);
	while (s[i] && s[i] != '\n')
	{
		if (ft_isalpha(s[i]) || ft_isdigit(s[i]) || s[i] == '/' || s[i] == '.'|| s[i] == ' ' || s[i] == '\t')
			i++;
		else
			return (0);
	}
	if (s[i] == '\n' || s[i] =='\0')
		return (1);
	else
		return (0);
}


int	is_path(char *s)
{
	int i;
	int	no_spc;
	int	start;
	int	end;
	char	*tmp;
	
	i = 0;
	no_spc = ft_strlen(s) - 1;
	if (!valid_for_path(s))
		return (0);
	if (s[no_spc] == '\n')
	{
		s[no_spc] = '\0';
		no_spc--;
	}
	while (s[no_spc] == ' ' || s[no_spc] == '\t')
		no_spc--;
	end = no_spc;
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	tmp = malloc(sizeof(char) * (end + 1 - i));
	if (!tmp)
		return (0);
	start = 0;
	printf("end %d\n", end);
	printf("i %d\n", i);
	printf("len %d\n", ft_strlen(s) - 1);
	printf("no spc %d\n", no_spc);
	end -= i;
	while (i <= no_spc && start <= end)
	{
		tmp[start] = s[i];
		start++;
		i++;
	}
	tmp[start] = '\0';
	printf("now:[%s]\n", tmp);
	if (ft_strncmp(&tmp[ft_strlen(tmp) - 4], ".xpm\0", 5))
		return (0);
	start = 2;
	while (tmp[start] == ' ' || tmp[start] == '\t')
		start++;
	while (end >= start)
	{
		if (tmp[start] == ' ' || tmp[start] == '\t')
			return (0);
		start++;
	}
	if (tmp[start] == '\0')
		return (1);
	printf("[%s]\n", &tmp[start]);
	return (0);
}

char	*is_no(char *s)
{
	int		i;
	int		j;
	char	*path;
	
	i = 2;
	j = 0;
	path = malloc(sizeof(char *) * ft_strlen(s));
	if (!path)
		return NULL;
	if (s[0] != 'N')
		return (NULL);
	if (s[1] != 'O')
		return (NULL);
	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while (s[i] && (ft_isalpha(s[i]) || ft_isdigit(s[i]) || s[i] == '/' || s[i] == '.'))
	{
		path[j] = s[i];
		i++;
		j++;
	}
	if (s[i] != '\n')
		return NULL;
	path[j] = '\0';
	return (path);
}
// int	set_path(t_data *data, char *s)
// {
// 	char	*tmp;
	
// 	if (is_path(s))
// 	{
// 		tmp = is_no(s);
// 		data->no_path = ft_strdup(tmp);
// 		data->all_inside--;
// 	}
	// else if (is_path(s) && is_so(s) != NULL)
	// {
	// 	tmp = is_so(s);
	// 	data->so_path = ft_strdup(tmp);
	// 	data->all_inside--;
	// }
	// else if (is_path(s) && is_we(s) != NULL)
	// {
	// 	tmp = is_we(s);
	// 	data->we_path = ft_strdup(tmp);
	// 	data->all_inside--;
	// }
	// else if (is_path(s) && is_ea(s) != NULL)
	// {
	// 	tmp = is_ea(s);
	// 	data->ea_path = ft_strdup(tmp);
	// 	data->all_inside--;
	// }
// 	else
// 		return (0);
// 	return (1);
// }

