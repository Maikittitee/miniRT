/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_obj_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:08:21 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/23 21:15:07 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_light	ft_assign_light(char **sp_line, int *state)
{
	t_light	light;

	light.ori = ft_vector_coor(sp_line[1], state);
	if (*state == -1)
		return (light);
	light.ratio = ft_atof(sp_line[2]);
	if (light.ratio < 0 || light.ratio > 1.0)
	{
		*state = -1;
		return (light);
	}
	return (light);
}

t_cam	ft_assign_cam(char **sp_line, int *state)
{
	t_cam	cam;

	cam.ori = ft_vector_coor(sp_line[1], state);
	if (*state == -1)
		return (cam);
	cam.normal_vec = ft_vector_norm(sp_line[2], state);
	if (*state == -1)
		return (cam);
	cam.fov = ft_atof(sp_line[3]);
	if (cam.fov < 0 || cam.fov > 180)
		*state = -1;
	return (cam);
}

t_amb	ft_assign_amb(char **sp_line, int *state)
{
	t_amb	a;

	a.ratio = ft_atof(sp_line[1]);
	if (a.ratio > 1)
	{
		*state = -1;
		return (a);
	}
	a.color = ft_assign_clr(sp_line[2], state);
	return (a);
}

