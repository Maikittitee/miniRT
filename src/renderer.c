/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/12/28 03:48:28 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"


float minf(float a, float b)
{
	if (a < b)
		return (a);
	return (b);
}

t_bool render(t_data *data, t_img *img, char **buffer)
{
	// char *buffer;
	// t_img img;
	(void)data;
	t_color color;
	int	x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while  (x < WIN_WIDTH)
		{
			// printf("%d %d\n", x, y);
			color = per_pixel(x, y);
			// put_color_to_img(per_pixel(x, y),buffer, img, (t_vec){x, y, 0});
			my_put_to_img(*buffer, *img, (t_vec){x, y, 0}, color);
			x++;
		}
		y++;
	}
	return (True);
}

t_color colorf(float n)
{
	t_color ret;

	ret.a = (unsigned char)n << 24 & 0xFF;
	ret.b = (unsigned char)n << 16 & 0xFF;
	ret.g = (unsigned char)n << 8 & 0xFF;
	ret.r = (unsigned char)n & 0xFF;

	return (ret);
	
}

t_color	per_pixel(int x, int y)
{
	int i;
	int j;

	i = x - WIN_WIDTH / 2;
	j = y - WIN_HEIGHT / 2;

	// is hit object

	// cal t

	// cal min t

	// get color from float
	
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

	// printf("(%d,%d) discm=%f\n", i, j, discm);

	if (discm < 0)
		return ((t_color){0, 0, 0, 0});

	float t1, t2;

	t1 = ((-1 * b) + discm) / 2 * a;
	t2 = ((-1 * b) - discm) / 2 * a;
	

	float t_min = minf(t1, t2);

	printf("%f\n", t_min);

	// t_color color = (t_color){t_min * 255, 0, 0, 0};
	return (colorf(t_min));
	

	
	
	// int color = (((char)r << 16) & (0xFF0000)) | (((char)g << 8) & (0x00FF00)) | (b & (0x0000FF));

	// printf("%x\n", color);
	
}