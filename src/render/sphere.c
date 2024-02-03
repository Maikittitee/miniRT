/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 21:53:31 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/03 18:17:37 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"


float hit_sphere(t_ray ray,t_obj sphere)
{
	t_vec oc;
	float a;
	float h;
	float c;
	float discriminant;

	if (sphere.type != SPHERE)
		return (-1.0f);	
	oc = vector_sub(ray.ori, sphere.ori); // not sure;
	a = vector_dot(ray.dir, ray.dir);
	h = vector_dot(oc, ray.dir);
	c = vector_dot(oc, oc) - (sphere.d * sphere.d * 0.25);

	discriminant = h * h - a * c;
	if (discriminant < 0)
		return (-1.0f);
	return ((-1 * h - sqrt(discriminant)) / a);

}


