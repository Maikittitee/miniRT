/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:11:43 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/29 17:38:56 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float	hit_plane(t_ray ray, t_obj plane)
{
	float	denom;
	float	t;

	denom = vector_dot(vector_norm(plane.normal_vec), vector_norm(ray.dir));
	if (fabsf(denom) < VERYSMALLNUMBER)
		return (-1.0f);
	t = vector_dot(vector_sub(plane.ori, ray.ori), vector_norm(plane.normal_vec)) / denom; 
	if (t <= 0.0f)
		return (-1.0f);
	return (t);
}
