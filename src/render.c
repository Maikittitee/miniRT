/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:30:30 by ktunchar          #+#    #+#             */
/*   Updated: 2023/08/25 15:18:16 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	ray_shooter(t_cam cam)
{
	float vir_width;
	float vir_height;
	float aspect_ratio;
	float step;
	float i;
	float j;

	i = 0;
	j = 0;
	aspect_ratio = (float)WIN_WIDTH / (float)WIN_HEIGHT;

	vir_width = 2 * tan(cam.fov / 2) * (M_PI / 180);
	vir_height = vir_width / aspect_ratio;
	step = vir_width / WIN_WIDTH;

	while (i < vir_width)
	{
		while (j < vir_height)
		{
			
			printf("i = %f, j = %f\n", i, j);
			j += step;
		}
		i += step;
	}
}