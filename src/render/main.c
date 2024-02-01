/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:26:07 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/02 02:46:56 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	main()
{
	t_viewport viewport;
	t_data	data;


	t_cam	cam;

	cam.direction = (t_vec){0, 1, 0};
	cam.fov = 70;
	cam.origin = (t_vec){0, 0, 0};

	init_viewport(&viewport, &cam);
	data.cam = cam;

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
	
	data.nobj = 1;
	data.obj = malloc(sizeof(t_obj) * data.nobj);
	data.obj[0].type = SPHERE;
	data.obj[0].color = (t_color){255, 0, 0, 255};
	data.obj[0].ori = (t_vec){0, 0, -10};
	data.obj[0].d = 15;
	
	// rendering
	render(&data, &img, &buffer);
	mlx_put_image_to_window(mlx, data.winp, data.imgp, 0, 0);

	print_vec(data.cam.origin);
	// loop
    mlx_loop(mlx);	
}

