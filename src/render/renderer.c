/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/03 21:10:07 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"


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
			color = per_pixel(ray, data->obj, data->light); // color = per_pixel(ray);
			my_put_to_img(*buffer, *img, (t_vec){x, y, 0}, color);
			x++;
		}
		y++;
	}
	return (True);
}



t_color	per_pixel(t_ray ray, t_obj *obj, t_light light)
{
	(void)obj;
	(void)ray;

	t_vec unit_dir;

	unit_dir = vector_norm(ray.dir); 
	float a = 0.5f * (unit_dir.y + 1.0f); // use y as parameter 

	float t = hit_sphere_t(ray, obj[0]);
	if (t < 0.0f);
		return (t_color){(1 - 0.5 * a) * 255, (1 - 0.3 * a) * 255, 255, 255};
	t_vec hitpoint = vector_add(ray.ori, vector_scaler(t, unit_dir));
	t_vec sp_normal_vec = vector_norm(vector_sub(hitpoint, obj[0].ori));
	
	t_vec hitpoint_to_light = vector_norm(vector_sub(light.ori, hitpoint));

	float dot_p = fmaxf(vector_dot(sp_normal_vec, hitpoint_to_light), 0.0f);

	(void)dot_p;
	// return (t_color){255 * dot_p, 0 * dot_p, 0 * dot_p, 255};
	return (color_scaler(dot_p, obj[0].color));
	// return (t_color){(sp_normal_vec.x + 1) * 0.5 * 255, (sp_normal_vec.y + 1) * 0.5 * 255, (sp_normal_vec.z + 1) * 0.5 * 255, 255};
	
	// return (t_color){(1 - a) * 255, (1-a) * 255, (1-a) * 255, 255};
	
	
	// printf("%f %f %f\n", ray.dir.i, ray.dir.j, ray.dir.k);
	

}