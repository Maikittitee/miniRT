/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2024/01/26 18:56:15 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ray	gen_ray(int x, int y, t_data *data)
{
	t_ray ray;

	ray.ori = data->cam.ori;
	ray.dir = 

	
}

void	init_camera(t_cam *cam)
{
	
	cam->axis.vert = (t_vec){0, 1.0f, 0};
	cam->axis.hori = vector_cross(cam->axis.vert, cam->ray_dir);
	cam->ver_width = 2* tan(cam->fov * PI / 360);
	cam->ver_height = WIN_HEIGHT/WIN_WIDTH * cam->ver_width;
	
	
}

t_bool render(t_data *data, t_img *img, char **buffer)
{
	// char *buffer;
	// t_img img;
	(void)data;
	t_color color;
	int	x;
	int y;

	y = 0;
	// init_camera(&data->cam)
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while  (x < WIN_WIDTH)
		{
			ray = gen_ray(x, y, data)
			color = per_pixel(x, y); // color = per_pixel(ray);
			// put_color_to_img(per_pixel(x, y),buffer, img, (t_vec){x, y, 0});
			my_put_to_img(*buffer, *img, (t_vec){x, y, 0}, color);
			x++;
		}
		y++;
	}
	return (True);
}



t_color	per_pixel(int x, int y)
{
	

}