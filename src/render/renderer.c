/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:40:14 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/02 21:28:23 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"


// void	init_camera(t_cam *cam)
// {
// 	cam->ori = (t_vec){0, 0, 0};
// 	cam->axis.dir = (t_vec){0, 0, -1};
// 	cam->fov = 70;
// 	cam->axis.vert = (t_vec){0, 1.0f, 0};
// 	cam->axis.hori = vector_cross(cam->axis.vert, cam->dir);
// 	cam->ver_width = 2 * tan(cam->fov * PI / 360);
// 	cam->ver_height = WIN_HEIGHT/WIN_WIDTH * cam->ver_width;
// 	cam->dir = cam->axis.dir;
// 	cam->dir = vector_sub(cam->normal_vec, vector_scaler(0.5, cam->axis.hori));
// 	cam->dir = vector_add(cam->dir, vector_scaler(0.5, cam->axis.vert));
	
	
// }

t_ray	gen_ray(int x, int y, t_data *data)
{
	t_vec dir;
	t_vec origin;
	t_vec target_px;
	
	// printf("cam origin >> \n");
	// print_vec(data->cam.origin);
	target_px = vector_add(data->viewport.upper_left_px, vector_scaler(x, data->viewport.step_x));
	target_px = vector_add(target_px, vector_scaler(y, data->viewport.step_y));
	// print_vec(target_px);
	origin = data->cam.origin;
	dir  = vector_sub(target_px, origin);
	// printf("ray origin in gen_ray\n");
	// print_vec(origin);
	// printf("----\n");
	// print_vec(origin);
	return (t_ray){origin, dir};
	
}

t_bool render(t_data *data, t_img *img, char **buffer)
{
	// char *buffer;
	// t_img img;
	t_ray ray;
	t_color color;
	// (void)ray;
	int	x;
	// (void) color;
	int y;
	// (void)buffer;
	// (void)data;
	// (void)img;
	y = 0;
	// init_camera(&data->cam)
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while  (x < WIN_WIDTH)
		{
			ray = gen_ray(x, y, data);
			color = per_pixel(ray, data->obj, data->light); // color = per_pixel(ray);
			my_put_to_img(*buffer, *img, (t_vec){x, y, 0}, color);
			x++;
		}
		y++;
	}
	return (True);
}



t_color	per_pixel(t_ray ray, t_obj *obj, t_light light)
{
	(void)obj;
	(void)ray;

	t_vec unit_dir;

	unit_dir = vector_norm(ray.dir); 
	// printf("ray origin in per_pixel\n");
	// print_vec(ray.ori);
	float a = 0.5f * (unit_dir.y + 1.0f); // use y as parameter 

	if (!hit_sphere(ray, obj[0]))
		return (t_color){(1 - 0.5 * a) * 255, (1 - 0.3 * a) * 255, 255, 255};
	float t = hit_sphere_t(ray, obj[0]);
	t_vec hitpoint = vector_add(ray.ori, vector_scaler(t, unit_dir));
	t_vec sp_normal_vec = vector_norm(vector_sub(hitpoint, obj[0].ori));
	
	t_vec hitpoint_to_light = vector_norm(vector_sub(light.ori, hitpoint));

	float dot_p = fmaxf(vector_dot(sp_normal_vec, hitpoint_to_light), 0.0f);

	printf("sphere normal vector\n");
	print_vec(sp_normal_vec);
	printf("hitpoint\n");
	print_vec(hitpoint);
	printf("hp to light\n");
	print_vec(hitpoint_to_light);
	printf("dot: %f\n", dot_p);
	return (t_color){255 * dot_p, 0, 0, 255};
	return (t_color){((float)((sp_normal_vec.x + 1) * 0.5f)) * 255, ((float)((sp_normal_vec.y + 1) * 0.5f)) * 255, ((float)((sp_normal_vec.z + 1) * 0.5f)) * 255, 255};
	
	
	// return (t_color){(1 - a) * 255, (1-a) * 255, (1-a) * 255, 255};
	
	
	// printf("%f %f %f\n", ray.dir.i, ray.dir.j, ray.dir.k);
	

}