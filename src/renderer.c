/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2023/12/30 04:52:32 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"


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
	
	// float aspect_ratio = WIN_WIDTH/WIN_HEIGHT;
	
	// i *= aspect_ratio;
	t_vec origin;
	origin.i = 0;
	origin.j = 0;
	origin.k = -100.000055555;
	// origin = vector_norm(origin);
	
	t_vec direction;
	direction.i = i;
	direction.j = j;
	direction.k = 1;
	direction = vector_norm(direction);

	float a =  vector_dot(direction, direction);
	float b = 2 * vector_dot(origin, direction);
	float c = vector_dot(origin, origin) - 10000;


	float discm; 
	discm = b * b - 4 * a * c;

	if (discm < 0)
		return ((t_color){0, 0, 0, 1});
	// return ((t_color){255, 0, 255, 1});
	// printf("%d\n", (unsigned char)(-0.5 * 255));
	// return ((t_color){-0.5 * 255, 0, 0, 255});
	float t1, t2;

	t1 = ((-1 * b) + sqrt(discm)) / (2 * a);
	t2 = ((-1 * b) - sqrt(discm)) / (2 * a);

	t_vec hit_point = vector_add(origin, c_vec(fminf(t1, t2), direction));


	// go to light

	t_light light;

	light.ori =  (t_vec){-100, -100, -100};
	light.ratio = 1;
	
	t_vec hp_to_light, o_to_hp;

	o_to_hp = vector_norm(vector_sub(hit_point, (t_vec){0,0,0}));
	hp_to_light = vector_norm(vector_sub(light.ori, hit_point));

	float dot_p;
	// dot_p = fmaxf(vector_dot(o_to_hp, hp_to_light), 0.0f);
	dot_p = vector_dot(o_to_hp, hp_to_light);
	if (dot_p < 0)
		return ((t_color){0, 0, 0, 255});
	
	printf("(%d, %d)dot product result:%f, color:%f\n",x, y, dot_p, dot_p * 255.0f); 

	
	return ((t_color){(dot_p) * 255, 0, 0 , 255});

}