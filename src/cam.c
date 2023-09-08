/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 22:58:19 by ktunchar          #+#    #+#             */
/*   Updated: 2023/09/08 11:12:52 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_bool init_camera(t_cam *cam)
{
	t_vec x_axis;

	x_axis = (t_vec){1.0f, 0, 0};
	cam->ver_width = 2 * tan(cam->fov/2);
	cam->ver_height = WIN_HEIGHT / WIN_WIDTH * cam->ver_width;
	
	cam->axis.dir = normalize(cam->normal_vec);
	if (cam->axis.dir.i == 1 || cam->axis.dir.i == -1)
		x_axis = (t_vec){0, 0, -1.0f * cam->axis.dir.i};
	cam->axis.vert = normalize(cross_product(cam->axis.dir, x_axis));
	cam->axis.hori = normalize(cross_product(cam->axis.vert, cam->axis.hori));
	

	
	cam->ray_dir = cam->axis.dir;
	cam->ray_dir = add(cam->ray_dir, cmultiply(cam->axis.vert, 0.5 * cam->ver_height));
	cam->ray_dir = sub(cam->ray_dir, cmultiply(cam->axis.hori, 0.5 * cam->ver_width));
	
	
}