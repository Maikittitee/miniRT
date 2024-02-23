/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:29:01 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/23 20:17:42 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float	hit_cylinder(t_ray ray, t_obj cylin)
{
	t_vec r1;
	t_vec r2;
	t_vec hitpoint;
	float t;

	r2 = vector_add(cylin.ori, vector_scaler(cylin.h / 2, cylin.normal_vec));
	r1 = vector_sub(cylin.ori, vector_scaler(cylin.h / 2, cylin.normal_vec));
	
	// print_vec(r1);
	// print_vec(r2);

	float a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z ;
	float b = 2 * (ray.ori.x * ray.dir.x + ray.ori.z * ray.dir.z);
	float c = ray.ori.x * ray.ori.x + ray.ori.z * ray.ori.z -  (cylin.d * cylin.d * 0.25f * 0.25f);	
	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0f);
	t = ((-1 * b - sqrt(discriminant)) / 2 * a);
	hitpoint = vector_add(ray.ori, vector_scaler(t, ray.dir));
	if (hitpoint.y > r2.y || hitpoint.y < r1.y)
		return (-1.0f);
	return (t);

	
	
}

