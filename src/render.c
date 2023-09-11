/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:30:30 by ktunchar          #+#    #+#             */
/*   Updated: 2023/09/11 18:33:54 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_ray gen_ray(int x, int y, t_cam cam)
{
	t_ray ray;

	ray.pnt = cam.pnt;
	ray.vec = cam.ray_dir;
	ray.vec = add(ray.vec, cmultiply(cam.axis.hori, (x / WIN_WIDTH)));
	ray.vec = sub(ray.vec, cmultiply(cam.axis.vert, (y / WIN_HEIGHT)));
	ray.vec = normalize(ray.vec);
	return (ray);
}

t_color hit_obj(t_ray ray, t_data *data)
{
	t_color color;
	(void)ray;
	(void)data;
	
	color.r = 255;
	color.g = 255;
	color.b = 0;

	return (color);
}


t_bool ray_tracer(t_data *data, char *buffer, t_img img)
{
	int x;
	int y;
	t_color color;
	t_ray	ray;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT)
		{
			ray = gen_ray(x, y, data->cam);
			color = hit_obj(ray, data);
			my_put_to_img(buffer, img, (t_pnt){x, y, 0}, color);
			y++;
		}
		x++;
	}
	return (True);
}
