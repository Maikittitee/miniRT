/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:26:07 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/21 23:29:16 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	main()
{
	t_viewport viewport;
	t_data	data;
	t_cam	cam;
	t_light light;

	// initial camera 	
	cam.direction = (t_vec){0, 0, -1};
	cam.fov = 70;
	cam.origin = (t_vec){0, 0, 0};

	// initial viewport
	init_viewport(&viewport, &cam);
	data.cam = cam;
	data.viewport = viewport;

	// light
	light.ori = (t_vec){20, 20 , -20};
	light.ratio = 1;
	data.light = light;
	
	// obj
	data.nobj = 4;
	data.obj = malloc(sizeof(t_obj) * data.nobj);
	data.obj[0].type = SPHERE;
	data.obj[0].color = (t_color){255, 0, 0, 255};
	data.obj[0].ori = (t_vec){0, 0, -50};
	data.obj[0].d = 10;

	data.obj[1].type = SPHERE;
	data.obj[1].color = (t_color){0, 255, 0, 255};
	data.obj[1].ori = (t_vec){10, 0, -50};
	data.obj[1].d = 10;

	data.obj[2].type = SPHERE;
	data.obj[2].color = (t_color){0, 0, 255, 255};
	data.obj[2].ori = (t_vec){-10, 0, -50};
	data.obj[2].d = 10;

	data.obj[3].type = PLANE;
	data.obj[3].color = (t_color){100, 100, 100, 255};
	data.obj[3].ori = (t_vec){0, -20, -100};
	data.obj[3].normal_vec = (t_vec){0, 10, 1};
	
	data.amb.color = (t_color){255, 0, 0, 255};
	data.amb.ratio = 1;

	void *mlx;
	t_img img;
	char *buffer;

	mlx = mlx_init();
	data.winp = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "pmew");
    data.imgp = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	buffer = mlx_get_data_addr(data.imgp, &img.pixel_bits, &img.line_bytes, &img.endian);
	
	
	// rendering
	render(&data, &img, &buffer);
	mlx_put_image_to_window(mlx, data.winp, data.imgp, 0, 0);

	// loop
	mlx_hook(data.winp, 17, 0, close_win, &data);
	mlx_hook(data.winp, 2, 1, ft_exit, &data);
    mlx_loop(mlx);	
	free(data.obj);
}

