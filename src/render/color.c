/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:41:21 by ktunchar          #+#    #+#             */
/*   Updated: 2024/03/01 01:33:48 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color	color_scaler(float c, t_color color)
{
	return ((t_color){color.r * c, color.g * c, color.b * c, color.a});
}

t_color	color_add(t_color c1, t_color c2)
{
	float	r;
	float	g;
	float	b;

	r = 0.5f * c1.r + 0.5f * c2.r;
	g = 0.5f * c1.g + 0.5f * c2.g;
	b = 0.5f * c1.b + 0.5f * c2.b;
	return ((t_color){fmin(r, 255), fmin(g, 255), fmin(b, 255), 255});
}

t_color	calculate_color(t_hit hit, t_ray ray, t_data data)
{
	t_dot	d;
	t_vec	hitpoint_to_light;
	t_ray	tolight_ray;

	ray.dir = vector_norm(ray.dir);
	d = get_dot_product(data.obj[hit.index], hit, data, ray);
	hitpoint_to_light = vector_norm(vector_sub(data.light.ori, hit.hitpoint));
	d.dot = activte_dot(d.dot, data.obj[hit.index].type, d.disk);
	tolight_ray.ori = hit.hitpoint;
	tolight_ray.dir = hitpoint_to_light;
	if (is_hit_object(tolight_ray, hit.index, data.obj, data))
		d.dot = 0.0f;
	return (color_scaler(d.dot * data.light.ratio, data.obj[hit.index].color));
}
