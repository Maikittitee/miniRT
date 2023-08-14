/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 03:55:15 by ktunchar          #+#    #+#             */
/*   Updated: 2023/08/14 23:03:35 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	main(int ac, char **av)
{
	t_data *data;
	t_img img;
	int	x;
	int y;
	char *buffer;
	
	
	// protect ac av;
	if (ac != 2)
		return (1);
	data = init_data(*av);
	buffer = mlx_get_data_addr(data->img, &(img.pixel_bits), &(img.line_bytes), &(img.endian));

	int color = 0xABCDEF;

	y = 0;
	while (y < 360)
	{
		x = 0;
		while (x < 640)
		{
			int pixel = (y * img.line_bytes) + (x * 4);
			
			if (img.endian == 1)        // Most significant (Alpha) byte first
			{
				buffer[pixel + 0] = (color >> 24);
				buffer[pixel + 1] = (color >> 16) & 0xFF;
				buffer[pixel + 2] = (color >> 8) & 0xFF;
				buffer[pixel + 3] = (color) & 0xFF;
			}
			else if (img.endian == 0)   // Least significant (Blue) byte first
			{
				buffer[pixel + 0] = (color) & 0xFF;
				buffer[pixel + 1] = (color >> 8) & 0xFF;
				buffer[pixel + 2] = (color >> 16) & 0xFF;
				buffer[pixel + 3] = (color >> 24);
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_hook(data->win, 17, 0, close_win, data);
	mlx_hook(data->win, 2, 1, ft_exit, data);
	mlx_loop(data->mlx);
}