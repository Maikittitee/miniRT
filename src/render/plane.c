/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 22:11:43 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/06 23:31:56 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float hit_plane(t_ray ray, t_obj plane)
{
	float denom = fabs(vector_dot(vector_norm(plane.normal_vec), vector_norm(ray.dir)));
	if (denom < VERYSMALLNUMBER)
		return (-1.0f);
	return ((fabsf(vector_dot(vector_sub(plane.ori, ray.ori), vector_norm(plane.normal_vec)))/denom));	
}