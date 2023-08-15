/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 03:55:15 by ktunchar          #+#    #+#             */
/*   Updated: 2023/08/15 16:16:23 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int ac, char **av)
{
	t_data *data;
	t_img img;
	char *buffer;
	// int x;
	// int y;
	
	
	// protect ac av;
	if (ac != 2)
		return (1);
	data = init_data(*av);
	buffer = mlx_get_data_addr(data->img, &(img.pixel_bits), &(img.line_bytes), &(img.endian));
	my_put_to_img(buffer, img, (t_pnt){100, 100, 100}, (t_color){255, 0, 0});
	my_put_to_img(buffer, img, (t_pnt){200, 100, 100}, (t_color){255, 0, 0});
	my_put_to_img(buffer, img, (t_pnt){100, 200, 100}, (t_color){255, 0, 0});
	my_put_to_img(buffer, img, (t_pnt){200, 200, 100}, (t_color){255, 0, 0});

	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_hook(data->win, 2, 1, ft_exit, data);
	mlx_loop(data->mlx);
}