/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2024/01/26 12:14:13 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_ray	gen_ray(int x, int y, t_data data)
{
	t_ray ray;

	ray.ori = data.cam.ori;
	ray.dir = vector_add(data.cam.fov, vec_scalar(data.cam.ver_height, (x / WIN_WIDTH)));
	ray.dir = vector_sub(ray.dir, vector_scalar(data.cam.ver_width, (y / WIN_HEIGHT)));
	
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
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while  (x < WIN_WIDTH)
		{
			// ray = gen_ray(x, y, data)
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