/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/12/30 02:14:38 by ktunchar         ###   ########.fr       */
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
	
	float aspect_ratio = WIN_WIDTH/WIN_HEIGHT;
	
	i *= aspect_ratio;
	t_vec origin;
	origin.i = 0;
	origin.j = 0;
	origin.k = 4.000055555;
	
	t_vec direction;
	direction.i = i;
	direction.j = j;
	direction.k = -1;
	direction = vector_norm(direction);

	float a =  vector_dot(direction, direction);
	float b = 2 * vector_dot(origin, direction);
	float c = vector_dot(origin, origin) - 16;


	float discm; 
	discm = b * b - 4 * a * c;

	if (discm < 0)
		return ((t_color){0, 0, 0, 1});
	// return ((t_color){255, 0, 255, 1});

	float t1, t2;

	t1 = ((-1 * b) + discm) / 2 * a;
	t2 = ((-1 * b) - discm) / 2 * a;

	t_vec hit_point = c_vec(minf(t1, t2), direction);


	// go to light

	t_light light;

	light.ori =  (t_vec){-5, 5, 0};
	light.ratio = 1;
	
	t_vec hp_to_light, o_to_hp;

	o_to_hp = vector_norm(vector_sub(hit_point, (t_vec){0,0,0}));
	hp_to_light = vector_norm(vector_sub(light.ori, hit_point));

	float dot_p = vector_dot(o_to_hp, hp_to_light);
	
	printf("dot product result:%f\n", dot_p); 

	
	return ((t_color){dot_p * 255, 0, 0 , 1});

}