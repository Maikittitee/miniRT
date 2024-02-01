/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:53:31 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/02 02:43:29 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_bool	hit_sphere(t_ray ray, t_obj sphere)
{
	t_vec oc;
	float a;
	float b;
	float c;
	float discriminant;
	// print_vec(ray.ori);
	oc = vector_sub(sphere.ori, ray.ori);
	a = vector_dot(ray.dir, ray.dir);
	b = 2.0f * vector_dot(oc, ray.dir);
	c = vector_dot(oc, oc) - (sphere.d * sphere.d * 0.25);

	discriminant = b * b - 4 * a * c;
    if (discriminant < 0)
		return (False);
	return (True);	
	
}

float hit_sphere_t(t_ray ray,t_obj sphere)
{
	t_vec oc;
	float a;
	float b;
	float c;
	float discriminant;
	
	// if (sphere.type != SPHERE)
	// 	return (-999.0f);
	// vec3 oc = r.origin() - center;

	// printf("sphere ori >> \n");	
	// print_vec(sphere.ori);
	// printf("ray ori >>\n");	
	// print_vec(ray.ori);
	oc = vector_sub(sphere.ori, ray.ori); // not sure;
	// printf("oc >>\n");	
	// print_vec(oc);
    // auto a = dot(r.direction(), r.direction());
    // auto b = 2.0 * dot(oc, r.direction());
    // auto c = dot(oc, oc) - radius*radius;

	a = vector_dot(ray.dir, ray.dir);
	b = 2.0f * vector_dot(oc, ray.dir);
	c = vector_dot(oc, oc) - (sphere.d * sphere.d * 0.25);

    // auto discriminant = b*b - 4*a*c;
	discriminant = b * b - 4 * a * c;
    // if (discriminant < 0)
	// 	return (-999.0f);
	// return (1);
	return ((-1 * b - sqrt(discriminant)) / (2.0f * a));

}


