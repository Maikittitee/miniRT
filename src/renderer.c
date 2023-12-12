/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/12/07 18:21:29 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_bool render(void *img, int width, int height)
{
	// int	x;
	// int	y;
	
	int pixel_bits;
	int line_bytes;
	int endian;
	char *buffer = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);

	// x = 0;
	// y = 0;
	// while (y < height)
	// {
	// 	while (x < width)
	// 	{
	// 		buffer[x * 4 + y * line_bytes] = get_color(x, y);
	// 		x++;
	// 	}
	// 	y++;

	// }

// if (pixel_bits != 32)
//     color = mlx_get_color_value(mlx, color);

for(int y = 0; y < height; ++y)
for(int x = 0; x < width; ++x)
{
	int color = get_color(x, y);
    int pixel = (y * line_bytes) + (x * 4);

	// buffer[pixel] = color;
	buffer[pixel + 3] = (color >> 24); // alpha
	buffer[pixel + 2] = (color >> 16) & 0xFF; //red
	buffer[pixel + 1] = (color >> 8) & 0xFF; // green
	buffer[pixel] = (color) & 0xFF; //blue
}
	return (True);
}

int	get_color(int x, int y)
{
	(void)x;
	(void)y;



	char r = floor(x* 255.0);
	char g = floor(y * 255.0);
	char b = 0x00;

	int color = (((char)r << 16) & (0xFF0000)) | (((char)g << 8) & (0x00FF00)) | (b & (0x0000FF));

	printf("%x\n", color);
	return (color);
	// return ((r << 16) | (g << 8) | (b));
	// return (0xABCDEF);	
	return (0xFF0000);
	
}