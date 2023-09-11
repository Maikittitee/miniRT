/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 03:55:15 by ktunchar          #+#    #+#             */
/*   Updated: 2023/09/11 18:38:34 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	mock_data(t_data *data)
{
	data->amb.color = (t_color){255, 255, 255};
	data->amb.ratio = 0.2;
	data->cam.pnt = (t_pnt){0,0,0};
	data->cam.fov = 70;
	data->cam.normal_vec = (t_vec){1, 0, 0};
	data->light = malloc(sizeof(t_light *) * 2);
	data->light[0] = malloc(sizeof(t_light));
	data->light[0]->pnt = (t_pnt){20, 20, 0};
	data->light[0]->ratio = 0.5;
	data->light[1] = NULL;
	data->sphere = malloc(sizeof(t_sphere *) * 2);
	data->sphere[0] = malloc(sizeof(t_sphere));
	data->sphere[0]->color = (t_color){255, 255, 0};
	data->sphere[0]->pnt = (t_pnt){20, 0, 0};
	data->sphere[0]->d = 5;
	
}


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
	mock_data(data);
	init_camera(&(data->cam));
	buffer = mlx_get_data_addr(data->img, &(img.pixel_bits), &(img.line_bytes), &(img.endian));
	ray_tracer(data, buffer, img);

	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_hook(data->win, 2, 1, ft_exit, data);
	mlx_loop(data->mlx);
}