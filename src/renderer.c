/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/12/13 23:22:30 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	put_color_to_img(char **buffer, t_img *img, int x, int y)
{
	int color = get_color(x, y);
    int pixel = (y * img->line_bytes) + (x * 4);

	// buffer[pixel] = color;
	(*buffer)[pixel + 3] = (color >> 24); // alpha
	(*buffer)[pixel + 2] = (color >> 16) & 0xFF; //red
	(*buffer)[pixel + 1] = (color >> 8) & 0xFF; // green
	(*buffer)[pixel] = (color) & 0xFF; //blue
}
	

t_bool render(t_data *data)
{
	char *buffer;
	t_img img;
	int	x;
	int y;

	y = 0;
	buffer = mlx_get_data_addr(data->imgp, &img.pixel_bits, &img.line_bytes, &img.endian);
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while  (x < WIN_WIDTH)
		{
			put_color_to_img(&buffer, &img, x, y);
			x++;
		}
		y++;
	}
	return (True);
}

int	get_color(int x, int y)
{
	(void)x;
	(void)y;


	char r = x * 255.0 / WIN_WIDTH;
	char b= y * 255.0 / WIN_HEIGHT;
	// char g = (y) * 255.0 / sqrt(WIN_HEIGHT * WIN_HEIGHT + WIN_WIDTH * WIN_WIDTH);
	char g = 0x00;

	int color = (((char)r << 16) & (0xFF0000)) | (((char)g << 8) & (0x00FF00)) | (b & (0x0000FF));

	printf("%x\n", color);
	return (color);
	// return ((r << 16) | (g << 8) | (b));
	// return (0xABCDEF);	
	return (0xFF0000);
	
}