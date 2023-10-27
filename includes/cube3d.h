/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsydelny <dsydelny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:36:40 by pferreir          #+#    #+#             */
/*   Updated: 2023/10/27 23:27:57 by dsydelny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <X11/X.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct t_data
{
	int		pos;
	int		f_r;
	int		f_g;
	int		f_b;
	int		c_r;
	int		c_g;
	int		c_b;
	int		h_map;
	int		cnt_1;
	int		height;
	int		len_map;
	int		len_path;
	int		no_here;
	int		so_here;
	int		we_here;
	int		ea_here;
	int		c_here;
	int		f_here;
	char	*tmp_path;
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	char	**map;
	char	**data;
	char	**work_map;
}			t_data;

/*		IS_WHAT		*/
int			is_floor(t_data *data, char *s);
int			is_ceiling(t_data *data, char *s);
int			set_path(t_data *data);
int			is_path(t_data *data, char *s);

int			check_valid_char(char *s);
int			parsing(t_data *data, char *file);
void		free_dstr(char **dstr);
int			check_borders(t_data *data);
void		init_whos_here(t_data *data);

int	check_first_column(t_data *data);
int	check_last_column(t_data *data);
int	check_last_row(t_data *data);

#endif
