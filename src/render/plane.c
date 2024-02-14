/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:11:43 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/14 17:38:16 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float hit_plane(t_ray ray, t_obj plane)
{
	float denom = fabsf(vector_dot(vector_norm(plane.normal_vec), vector_norm(ray.dir))); // know that is a front or back of plane
	printf("denom: %f\n", denom);
	// float denom = vector_dot(vector_norm(plane.normal_vec), vector_norm(ray.dir)); // know that is a front or back of plane
	if (denom < VERYSMALLNUMBER)
		return (-1.0f); // no plane or back of plane
	return fabsf((vector_dot(vector_sub(plane.ori, ray.ori), vector_norm(plane.normal_vec))) / denom);	
}
