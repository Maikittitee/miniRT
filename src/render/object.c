/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:30:36 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/19 16:13:11 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float activte_dot(float dot, int type)
{
	if (type == PLANE)
		return (dot);
	return (fmaxf(dot, 0.0f));
}

t_vec calculate_normal_vector(t_obj obj, t_vec hitpoint)
{
	if (obj.type == SPHERE)
		return (vector_norm(vector_sub(hitpoint, obj.ori)));
	if (obj.type == PLANE)
		return (vector_norm(obj.normal_vec));
	return ((t_vec){0, 0, 0});
}

float get_dot_product(t_obj obj, t_vec hitpoint, t_light light)
{
	t_vec obj_normal_vec = calculate_normal_vector(obj, hitpoint);
	t_vec hitpoint_to_light = vector_norm(vector_sub(light.ori, hitpoint)); // work witg all type of object
	
	float dot_p = vector_dot(obj_normal_vec, hitpoint_to_light);
	if (dot_p < 0.0f && obj.type == PLANE)
	{
		obj_normal_vec = vector_scaler(-1.0f, obj_normal_vec);
		dot_p = vector_dot(obj_normal_vec, hitpoint_to_light);
	}
	return (activte_dot(dot_p, obj.type));
}

float get_closet_t(float new_t, float old_t, int *target_index, int index)
{
	printf("new_t: %f, old_t: %f\n", new_t, old_t);
	if (new_t < 0.0f)
	{
		printf("this should go to bg\n");
		return (old_t);
	}
	if (new_t > old_t)
	{
		if (*target_index == -1)
			*target_index = index;
		return (old_t);
	}
	*target_index = index;
	return (new_t);
	
}

t_color background_color(t_ray ray)
{
	t_vec unit_dir;

	unit_dir = vector_norm(ray.dir); 
	float a = 0.5f * (unit_dir.y + 1.0f); // use y as parameter 
	return (t_color){(1 - 0.5 * a) * 255, (1 - 0.3 * a) * 255, 255, 255};
}

t_color hit_object(t_ray ray, t_obj *obj, t_data data)
{
	unsigned int i;
	float	closet_t;
	int		target_index;
	

	i = 0;
	closet_t = 9999999.0f;
	target_index = -1;
	while (i < data.nobj)
	{
		if (obj[i].type == SPHERE)
			closet_t = get_closet_t(hit_sphere(ray, obj[i]), closet_t, &target_index, i);
		else if (obj[i].type == PLANE)
			closet_t = get_closet_t(hit_plane(ray, obj[i]), closet_t, &target_index, i);
		// else if (obj[i].type == CYLIN)
		// 	closet_t = get_closet_t(hit_cylinder(ray, obj[i]), closet_t, &target_index, i);
		i++;	
	}
	if (target_index == -1 || closet_t < 0.0f)
		return (background_color(ray));
	t_vec unit_dir = vector_norm(ray.dir);
	t_vec hitpoint = vector_add(ray.ori, vector_scaler(closet_t, unit_dir)); // work with all type of object
	
	float dot_p = get_dot_product(obj[target_index], hitpoint, data.light);
	return (color_scaler(dot_p, obj[target_index].color));
	
	
	// get type of obj, index, t
	// check that hit point can be access by light ? obj.color * dot_p : 
}
