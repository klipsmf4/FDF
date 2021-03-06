/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarahon <kbarahon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 19:50:17 by klever            #+#    #+#             */
/*   Updated: 2021/09/06 18:50:29 by kbarahon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

static int	key_esc(int key, t_fdf **fdf)
{
	if (key == ESC)
	{
		write(1, "\n\x1b[36m[you have pressed the esc key!]\n", 38);
		mlx_clear_window((*fdf)->data->mlx, (*fdf)->data->win);
		mlx_destroy_window((*fdf)->data->mlx, (*fdf)->data->win);
		exit(0);
	}
	return (1);
}

static void	loop_fdf(t_fdf **fdf)
{
	draw(fdf);
	mlx_put_image_to_window((*fdf)->data->mlx,
		(*fdf)->data->win, (*fdf)->data->img, 0, 0);
	mlx_hook((*fdf)->data->win, 2, (1L << 0), key_esc, fdf);
	mlx_hook((*fdf)->data->win, 17, (17L << 0), ft_exit, fdf);
	 mlx_loop((*fdf)->data->mlx);
}

int	main(int argc, char *argv[])
{
	t_keycode	keycode;
	t_fdf		*fdf;
	t_map		map;
	t_data		data;
	t_cam		cam;

	if (argc != 2)
		p_error("Usage : ./test_maps/fdf <filename>");
	fdf = (t_fdf *)malloc(sizeof(t_fdf));
	if (!fdf)
		p_error("Fail malloc");
	fdf->map = &map;
	fdf->cam = &cam;
	fdf->cam->keycode = &keycode;
	fdf->data = &data;
	fdf->data->winx = 2048;
	fdf->data->winy = 1080;
	set_var(&fdf);
	fill_check(&fdf, argv[1]);
	create_windows(&fdf);
	loop_fdf(&fdf);
	return (0);
}
