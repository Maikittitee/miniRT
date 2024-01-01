/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2024/01/01 20:47:54 by ktunchar         ###   ########.fr       */
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
	t_vec camara;
	camara.i = 0;
	// camara.j = 0;
	// camara.k = -10.0004555555;
	camara.j = -20;
	camara.k = -10.0004555555;
	
	t_vec direction;
	direction.i = i;
	direction.j = j;
	direction.k = 1;
	direction = vector_norm(direction);

	float a =  vector_dot(direction, direction);
	float b = 2 * vector_dot(camara, direction);
	// float c = vector_dot(camara, camara) - 100;
	float c = vector_dot(camara, camara) - 81;


	// printf("direction <%f %f %f>\n", direction.i, direction.j, direction.k);
	// usleep(100000);
	// return (t_color){255, 0, 255, 255};
	float discm; 
	discm = (b * b) - (4 * a * c);

	if (discm < 0)
		return ((t_color){0, 0, 0, 255});
	
	
	float t2;
	t2 = ((-1 * b) - sqrt(discm)) / (2 * a);

	t_vec hit_point = vector_add(camara, c_vec(t2, direction));
	
	printf("hp (%f, %f, %f)\n", hit_point.i, hit_point.j, hit_point.k);
	// t_light light;
	// light.ori =  (t_vec){-50, -50, -50};
	// light.ratio = 1;
	
	// t_vec hp_to_light, normal;
	// t_vec circle_origin;

	// circle_origin.i = 0;
	// circle_origin.j = 0;
	// circle_origin.k = 0;
	// normal = vector_norm(vector_sub(circle_origin, hit_point));
	// hp_to_light = vector_norm(vector_sub(hit_point, light.ori));

	// float dot_p;
	// // dot_p = fmaxf(vector_dot(o_to_hp, hp_to_light), 0.0f);
	// dot_p = fmaxf(vector_dot(normal, hp_to_light), 0.0f);
	// // if (dot_p < 0)
	// // 	return ((t_color){0, 0, 0, 255});
	
	// printf("hp(%f, %f, %f) normal vector<%f %f %f> ray_to_light<%f %f %f>:::%f\n", hit_point.i, hit_point.j, hit_point.k, normal.i, normal.j, normal.k, hp_to_light.i, hp_to_light.j, hp_to_light.k, dot_p);
	// // printf("(%d, %d)dot product result:%f, color:%f\n",x, y, dot_p, dot_p * 255.0f); 

	
	return ((t_color){255, 0, 0, 255});
	// return ((t_color){(dot_p) * 255, 0, 0 , 255});

}