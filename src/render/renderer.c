/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/22 01:43:50 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color background_color(t_ray ray)
{
	t_vec unit_dir;

	unit_dir = vector_norm(ray.dir); 
	float a = 0.5f * (unit_dir.y + 1.0f); // use y as parameter 
	return (t_color){(1 - 0.5 * a) * 255, (1 - 0.3 * a) * 255, 255, 255};
}

t_ray	gen_ray(int x, int y, t_data *data)
{
	t_vec dir;
	t_vec origin;
	t_vec target_px;
	
	target_px = vector_add(data->viewport.upper_left_px, vector_scaler(x, data->viewport.step_x));
	target_px = vector_add(target_px, vector_scaler(y, data->viewport.step_y));
	origin = data->cam.origin;
	dir  = vector_sub(target_px, origin);
	return (t_ray){origin, dir};
	
}

t_bool render(t_data *data, t_img *img, char **buffer)
{
	t_ray ray;
	t_color color;
	int	x;
	int y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while  (x < WIN_WIDTH)
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
	t_hit hit = hit_object(ray, obj, data);

	if (!hit.is_hit)
		return (background_color(ray));
	
	t_vec unit_dir = vector_norm(ray.dir);
	hit.hitpoint = vector_add(ray.ori, vector_scaler(hit.t, unit_dir)); // work with all type of object
		
	t_color color = calculate_color(hit, ray, data);
	color = apply_ambient(color, data.amb);
	return (color);
	// return (color_add(color_mult(shade_color, amb_color), amb_color));
}