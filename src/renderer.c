/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/12/19 17:12:35 by ktunchar         ###   ########.fr       */
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
	int i;
	int j;

	i = x - WIN_WIDTH / 2;
	j = y - WIN_HEIGHT / 2;
	
	// printf("%d %d\n", i, j);
	t_vec origin;
	origin.i = 0;
	origin.j = 0;
	origin.k = 2;
	
	t_vec direction;
	direction.i = i;
	direction.j = j;
	direction.k = -1;
	direction = vector_norm(direction);

	float a =  vector_dot(direction, direction);
	float b = 2 * vector_dot(origin, direction);
	float c = vector_dot(origin, origin) - 3.999555;

	// printf("%f %f %f\n", a,b,c);

	float discm; 

	discm = b * b - 4 * a * c;

	printf("(%d,%d) discm=%f\n", i, j, discm);
	if (discm >= 0)
		return (0xFF0000);
	return (0x000000);
	

	
	
	// int color = (((char)r << 16) & (0xFF0000)) | (((char)g << 8) & (0x00FF00)) | (b & (0x0000FF));

	// printf("%x\n", color);
	// return (color);
	
}