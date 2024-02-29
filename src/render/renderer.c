/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2024/03/01 01:00:50 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color	background_color(t_ray ray)
{
	t_vec	unit_dir;
	float	a;

	unit_dir = vector_norm(ray.dir);
	a = 0.5f * (unit_dir.y + 1.0f);
	return ((t_color){(1 - 0.5 * a) * 255, (1 - 0.3 * a) * 255, 255, 255});
}

t_ray	gen_ray(int x, int y, t_data *data)
{
	t_vec	dir;
	t_vec	origin;
	t_vec	target_px;

	target_px = vector_add(data->viewport.upper_left_px, \
	vector_scaler(x, data->viewport.step_x));
	target_px = vector_add(target_px, vector_scaler(y, data->viewport.step_y));
	origin = data->cam.origin;
	dir = vector_sub(target_px, origin);
	return ((t_ray){origin, dir});
}

t_bool	render(t_data *data, t_img *img, char **buffer)
{
	t_ray	ray;
	t_color	color;
	int		x;
	int		y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			ray = gen_ray(x, y, data);
			color = per_pixel(ray, data->obj, *data);
			my_put_to_img(*buffer, *img, (t_vec){x, y, 0}, color);
			x++;
		}
		y++;
	}
	return (True);
}

t_color	per_pixel(t_ray ray, t_obj *obj, t_data data)
{
	t_hit	hit;
	t_vec	unit_dir;
	t_color	color;

	hit = hit_object(ray, obj, data);
	if (!hit.is_hit)
		return (background_color(ray));
	unit_dir = vector_norm(ray.dir);
	// printf("ray.ori %f %f %f\n", ray.ori.x, ray.ori.y, ray.ori.z);
	// printf("unit %f %f %f\n", unit_dir.x, unit_dir.y, unit_dir.z);
	// printf("t: %f\n", hit.t);
	hit.hitpoint = vector_add(ray.ori, vector_scaler(hit.t, unit_dir));
	// printf("first hp %f %f %f\n", hit.hitpoint.x, hit.hitpoint.y, hit.hitpoint.z);
	color = calculate_color(hit, ray, data);
	// color = apply_ambient(color, data.amb);
	return (color);
}
