/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:11:43 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/18 17:47:54 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float hit_plane(t_ray ray, t_obj plane)
{
	// check is ray dirrection (associate to ray origin) are possible to point to plane
	float denom = vector_dot(vector_norm(plane.normal_vec), vector_norm(ray.dir)); // know that is a front or back of plane
	// float denom = fabsf(vector_dot(vector_norm(plane.normal_vec), vector_norm(ray.dir))); // know that is a front or back of plane
	// printf("denom: %f\n", denom);
	if (fabsf(denom) < VERYSMALLNUMBER)
		return (-1.0f); // no plane or back of plane
	float t;
	t = vector_dot(vector_sub(plane.ori, ray.ori), vector_norm(plane.normal_vec)) / denom; 
	printf("calulated t: %f\n", t);
	if (t <= 0.0f)
	{
		printf("and it less than zero\n");
		return (-1.0f);
	}
	return (t);	
}
