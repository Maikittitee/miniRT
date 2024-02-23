/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 16:29:01 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/23 22:38:15 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// t_vec rotateX(t_vec before, float theta)
// {
// 	t_vec after;

// 	after.x = before.x;
// 	after.y = 
float ft_pow2(float a)
{
	return (a*a);
}
	
// t_bool out_of_range(float a)
// {
	
// }	
// }

float	hit_cylinder(t_ray ray, t_obj cylin)
{
	// t_vec r1;
	// t_vec r2;
	// t_vec hitpoint;
	float t;
	cylin.normal_vec = vector_norm(cylin.normal_vec);
	// t_vec tmp;
	
	
	// r2 = vector_add(cylin.ori, vector_scaler(cylin.h / 2, cylin.normal_vec));
	// r1 = vector_sub(cylin.ori, vector_scaler(cylin.h / 2, cylin.normal_vec));
	// if (r2.x < r1.x)
	// {
	// 	tmp = r1;
	// 	r1 = r2;
	// 	r2 = tmp;
	// }
	t_vec oc = vector_sub(ray.ori, cylin.ori);
	// float a = ray.dir.x * ray.dir.x + ray.dir.z * ray.dir.z ;
	// float b = 2 * (ray.ori.x * ray.dir.x + ray.ori.z * ray.dir.z);
	// float c = ray.ori.x * ray.ori.x + ray.ori.z * ray.ori.z -  (cylin.d * cylin.d * 0.25f);	
	float a = vector_dot(ray.dir, ray.dir) - ft_pow2(vector_dot(ray.dir, cylin.normal_vec));
	float b = 2 * (vector_dot(ray.dir, oc) - vector_dot(ray.dir, cylin.normal_vec) * vector_dot(oc, cylin.normal_vec));
	float c = vector_dot(oc, oc) - ft_pow2(vector_dot(oc, cylin.normal_vec)) - ft_pow2(cylin.d / 2);
	float discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1.0f);
	printf("discriminant: %f\n", discriminant);
	t = ((-1 * b - sqrt(discriminant)) / 2 * a);
	// printf("t:%f\n", t);
	// hitpoint = vector_add(ray.ori, vector_scaler(t, ray.dir));
	// if (hitpoint.x > r2.x || hitpoint.x < r1.x)
	// 	return (-1.0f);
	float m = vector_dot(ray.dir, cylin.normal_vec) * t + vector_dot(oc, cylin.normal_vec);
	if (fabsf(m) > cylin.h / 2)
		return (-1.0f);
	return (t);

	
	
}

