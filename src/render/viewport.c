/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   viewport.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 23:23:13 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/21 21:20:02 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_axis calculate_axis(t_vec dir) // dir should be normed
{
	t_axis axis;
	t_vec	y_axis;
	
	y_axis = (t_vec){0, 1.0f, 0};
	axis.z = vector_scaler(-1.0f, dir);
	if (dir.y == -1 || dir.y == 1)
		y_axis = (t_vec){0, 0, 1.0f * dir.y}; // checked
	axis.x = vector_norm(vector_cross(y_axis, axis.z)); // checked
	axis.y = vector_norm(vector_cross(axis.z, axis.x)); // checked
	return (axis);
}

t_bool	init_viewport(t_viewport *viewport, t_cam *cam)
{
	t_vec first_pixel;
	t_vec viewport_u;
	t_vec viewport_v;
	float aspect_ratio;

	aspect_ratio = (float)WIN_HEIGHT/ (float)WIN_WIDTH;
	// printf("aspect ratio: %f\n", aspect_ratio);
	viewport->origin = vector_add(cam->origin, cam->direction);
	viewport->width = 2.0f * tan(cam->fov * 0.00872222);
	viewport->height = aspect_ratio * viewport->width;

	viewport->axis = calculate_axis(vector_norm(cam->direction)); // x is right , y is up, -z is direction


	viewport_u = vector_scaler(viewport->width, viewport->axis.x);
	viewport_v = vector_scaler(-1.0f * viewport->height, viewport->axis.y);

	viewport->width_vec = viewport_u;	
	viewport->height_vec = viewport_v;	
	viewport->step_x = vector_scaler((float)(1.0f/ WIN_WIDTH) , viewport_u);
	viewport->step_y = vector_scaler((float)(1.0f/ WIN_HEIGHT) , viewport_v);
	
	first_pixel = viewport->origin;
	first_pixel = vector_add(first_pixel, vector_scaler(-0.5f, viewport_u));
	first_pixel = vector_add(first_pixel, vector_scaler(-0.5f, viewport_v));
	
	// don't use axis
	// viewport->width_vec = vector_scaler(viewport->width, viewport->axis.x);
	// viewport->height_vec = vector_scaler(viewport->height, viewport->axis.y);
	// viewport->step_x = vector_scaler((float)(1 / (float)WIN_WIDTH) ,viewport->width_vec);
	// viewport->step_y = vector_scaler((float)(1 / (float)WIN_HEIGHT) ,viewport->height_vec);
	// first_pixel = vector_sub(viewport->origin, vector_scaler(0.5f, viewport->width_vec));
	// first_pixel = vector_sub(first_pixel, vector_scaler(0.5f, viewport->height_vec));
	viewport->upper_left_px = first_pixel;
	return (True);
}