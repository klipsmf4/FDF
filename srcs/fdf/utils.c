/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klever <klever@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/05 00:28:34 by klever            #+#    #+#             */
/*   Updated: 2021/09/06 14:07:01 by klever           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	create_windows(t_fdf **fdf)
{
	if ((*fdf)->map->y > 34)
		(*fdf)->map->zoom = 1;
	(*fdf)->cam->dir_x = (int)(*fdf)->data->winx / 2
		- ((*fdf)->map->x * (*fdf)->map->zoom);
	(*fdf)->cam->dir_y = (int)((*fdf)->data->winy / 2);
	(*fdf)->data->mlx = mlx_init();
	(*fdf)->data->win = mlx_new_window((*fdf)->data->mlx,
			(*fdf)->data->winx, (*fdf)->data->winy, "FdF");
	(*fdf)->data->img = mlx_new_image((*fdf)->data->mlx,
			(*fdf)->data->winx, (*fdf)->data->winy);
	(*fdf)->data->addr = mlx_get_data_addr((*fdf)->data->img,
			&(*fdf)->data->bits_per_pixel,
			&(*fdf)->data->line_lenght, &(*fdf)->data->endian);
}

int	str_hexa_to_int(char *str)
{
	int	num;
	int	i;

	i = 0;
	if (!str)
		return (0xffffff);
	while (str[i] && i < 7)
	{
		if (str[i] == ' ')
			return (num);
		if (str[i] >= '0' && str[i] <= '9')
			num = num * 16 + str[i] - '0';
		if (str[i] >= 'a' && str[i] <= 'f')
			num = num * 16 + str[i] - 'a' + 10;
		if (str[i] >= 'A' && str[i] <= 'F')
			num = num * 16 + str[i] - 'A' + 10;
		i++;
	}
	return (num);
}

int	word_count(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	p_error(char *s)
{
	ft_putstr_fd("\x1b[31mError\n", 1);
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
	exit(0);
}
