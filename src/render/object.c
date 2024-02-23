/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 18:30:36 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/23 22:40:24 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

float activte_dot(float dot, int type)
{
	
	printf("dot: %f\n", dot);
	if (type == PLANE)
		return (dot);
	return (fmaxf(dot, 0.0f));
}

t_vec calculate_normal_vector(t_obj obj, t_vec hitpoint)
{
	t_vec center_to_hp;
	t_vec proj_vec;
	
	if (obj.type == SPHERE)
		return (vector_norm(vector_sub(hitpoint, obj.ori)));
	if (obj.type == PLANE)
		return (vector_norm(obj.normal_vec));
	if (obj.type == CYLIN)
	{
		printf("cylin\n");
		center_to_hp = vector_sub(hitpoint, obj.ori);
		proj_vec = vector_scaler(vector_dot(center_to_hp, obj.normal_vec), vector_norm(obj.normal_vec));
		return (vector_norm(vector_sub(center_to_hp, proj_vec)));
		
	}
	return ((t_vec){0, 0, 0});
	
}

float get_dot_product(t_obj obj, t_light light, t_hit hit, t_data data)
{
	// float no_light;
	
	t_vec obj_normal_vec = calculate_normal_vector(obj, hit.hitpoint);
	t_vec hitpoint_to_light = vector_norm(vector_sub(light.ori, hit.hitpoint)); // work witg all type of object
	
	float dot_p = vector_dot(obj_normal_vec, hitpoint_to_light);
	if (dot_p < 0.0f && obj.type == PLANE)
	{
		obj_normal_vec = vector_scaler(-1.0f, obj_normal_vec);
		dot_p = vector_dot(obj_normal_vec, hitpoint_to_light);
	}
	
	t_ray tolight_ray;
	tolight_ray.ori = hit.hitpoint;
	tolight_ray.dir = hitpoint_to_light;

	dot_p = activte_dot(dot_p, obj.type);
	(void)data;
	if (is_hit_object(tolight_ray, hit.index, data.obj, data))
		return (0.0f);
	
	
	return (dot_p);
}

float get_closet_t(float new_t, float old_t, int *target_index, int index)
{
	// printf("new_t: %f, old_t: %f\n", new_t, old_t);
	if (new_t < 0.0f)
	{
		// printf("this should go to bg\n");
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

t_bool is_hit_object(t_ray ray, unsigned int except, t_obj *obj, t_data data)
{
	unsigned int i;

	i = 0;
	while (i < data.nobj)
	{
		if (i != except && obj[i].type == SPHERE && hit_sphere(ray, obj[i]) > 0.0f)
			return (True);
		
		if (i != except && obj[i].type == PLANE && hit_plane(ray, obj[i]) > 0.0f)
			return (True);
			
		else if (i != except && obj[i].type == CYLIN && hit_cylinder(ray, obj[i]) > 0.0f)
			return (True);
		i++;
		// i++;	
	}
	return (False);
}

t_hit hit_object(t_ray ray, t_obj *obj, t_data data)
{
	unsigned int i;
	float	closet_t;
	int		target_index;
	t_hit hit;
	
	i = 0;
	closet_t = 9999999.0f;
	target_index = -1;
	while (i < data.nobj)
	{
		obj[i].normal_vec = vector_norm(obj[i].normal_vec);
		if (obj[i].type == SPHERE)
			closet_t = get_closet_t(hit_sphere(ray, obj[i]), closet_t, &target_index, i);
		else if (obj[i].type == PLANE)
			closet_t = get_closet_t(hit_plane(ray, obj[i]), closet_t, &target_index, i);
		else if (obj[i].type == CYLIN)
			closet_t = get_closet_t(hit_cylinder(ray, obj[i]), closet_t, &target_index, i);
		i++;	
	}
	if (target_index == -1 || closet_t < 0.0f) // not hit
	{
		hit.is_hit = False;
		hit.index = -1;
		hit.t = -1.0f;
	}
	else{
		hit.is_hit = True;
		hit.index = target_index;
		hit.t = closet_t;
	}
	return (hit);
	// t_vec unit_dir = vector_norm(ray.dir);
	// t_vec hitpoint = vector_add(ray.ori, vector_scaler(closet_t, unit_dir)); // work with all type of object
	
	// float dot_p = get_dot_product(obj[target_index], hitpoint, data.light, target_index);
	// t_color color = color_scaler(dot_p, obj[target_index].color);

	// get type of obj, index, t
	// check that hit point can be access by light ? obj.color * dot_p : 
}
