/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 00:41:21 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/20 17:58:04 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color	color_scaler(float c, t_color color)
{
	return ((t_color){color.r * c, color.g * c, color.b * c, color.a}) ;
}

t_color	color_add(t_color c1, t_color c2)
{
	int r = c1.r + c2.r;
	int g = c1.g + c2.g;
	int b = c1.b + c2.b;

	return ((t_color){fmin(r, 255), fmin(g, 255), fmin(b, 255), 255});
}

t_color calculate_color(t_hit hit, t_ray ray, t_data data)
{
	ray.dir = vector_norm(ray.dir);

	float dot = get_dot_product(data.obj[hit.index], data.light, hit, data);
	return (color_scaler(dot * data.light.ratio, data.obj[hit.index].color));
	
}