/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:26:07 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/07 00:15:16 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	main()
{
	t_viewport viewport;
	t_data	data;
	t_cam	cam;
	t_light light;

	cam.direction = (t_vec){0, 0, -1};
	cam.fov = 70;
	cam.origin = (t_vec){0, 0, 0};

	init_viewport(&viewport, &cam);
	data.cam = cam;


	light.ori = (t_vec){-20, 20, -10};
	light.ratio = 1;
	
	data.nobj = 6;
	data.obj = malloc(sizeof(t_obj) * data.nobj);
	data.obj[0].type = SPHERE;
	data.obj[0].color = (t_color){255, 255, 255, 255};
	data.obj[0].ori = (t_vec){0, 0, -50};
	data.obj[0].d = 10;
	

	data.obj[1].type = PLANE;
	data.obj[1].color = (t_color){255, 0, 0, 255};
	data.obj[1].ori = (t_vec){-20, 0, -100};
	data.obj[1].normal_vec = (t_vec){1, 0, 1};
	
	data.obj[2].type = PLANE;
	data.obj[2].color = (t_color){0, 255, 0, 255};
	data.obj[2].ori = (t_vec){20, 0, -100};
	data.obj[2].normal_vec = (t_vec){-1, 0, 1};
	
	data.obj[3].type = PLANE;
	data.obj[3].color = (t_color){0, 0, 255, 255};
	data.obj[3].ori = (t_vec){0, 0, -100};
	data.obj[3].normal_vec = (t_vec){0, -1, 1};

	data.obj[4].type = PLANE;
	data.obj[4].color = (t_color){255, 0, 255, 255};
	data.obj[4].ori = (t_vec){0, 0, -100};
	data.obj[4].normal_vec = (t_vec){0, 1, 1};


	data.obj[5].type = PLANE;
	data.obj[5].color = (t_color){0, 255, 255, 255};
	data.obj[5].ori = (t_vec){0, 0, -80};
	data.obj[5].normal_vec = (t_vec){0, 0, -10};
	
	data.light = light;
	print_vec(cam.origin);
	printf("virtual viewport: %fx%f\n", viewport.height, viewport.width);
	printf("origin\n");
	print_vec(viewport.origin);
	printf("width vec / height vec\n");
	print_vec(viewport.width_vec);
	print_vec(viewport.height_vec);
	printf("step x,y\n");
	print_vec(viewport.step_x);
	print_vec(viewport.step_y);
	printf("first pixel\n");
	print_vec(viewport.upper_left_px);
	// printf("x y z\n");
	// print_vec(viewport.axis.x);
	// print_vec(viewport.axis.y);
	// print_vec(viewport.axis.z);
	print_vec(cam.origin);

	data.viewport = viewport; // check : can assign 


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

	print_vec(data.cam.origin);
	// loop
    mlx_loop(mlx);	
	free(data.obj);
}

