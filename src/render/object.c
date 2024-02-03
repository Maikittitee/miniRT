/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:30:36 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/03 19:41:56 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"


float get_closet_t(float new_t, float old_t, int index, int &target_index);
{
	if (new_t < 0.0f)
		return (old_t);
	return (fminf(new_t, old_t));
}

t_color hit_object(t_ray ray, t_obj *obj, t_data data);
{
	int	i;
	float	closet_t;
	int	target_index;

	closet_t = 0;

	i = 0;
	while (i < data.nobj)
	{
		if (obj[i].type == SPHERE)
			closet_t = get_closet_t(hit_sphere(ray, obj[i]), closet_t);
		else if (obj[i].type == PLANE)
			closet_t = get_closet_t(hit_plane(ray, obj[i]), closet_t);
		else if (obj[i].type == CYLIN)
			closet_t = get_closet_t(hit_cylinder(ray, obj[i]), closet_t);
		i++;	
	}
	// get type of obj, index, t
	// check that hit point can be access by light ? obj.color * dot_p : 
}