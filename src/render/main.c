/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:26:07 by ktunchar          #+#    #+#             */
/*   Updated: 2024/01/29 14:07:17 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	mock_data(t_data *data)
{
	t_sphere sphere;

	sphere.color = (t_color){255, 0, 255, 255};
	sphere.d = 4;
	sphere.ori = (t_vec){0, 0, 0};

	t_obj *obj;

	obj = malloc(sizeof(t_obj));
	obj->obj = &sphere;
	obj->type = SPHERE;
	obj->next = NULL;

	data->obj = obj;
}

int	main()
{
	t_viewport viewport;

	t_cam	cam;

	cam.direction = (t_vec){0, 1, 0};
	cam.fov = 70;
	cam.origin = (t_vec){0, 0, 0};

	init_viewport(&viewport, &cam);

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
	printf("x y z\n");
	print_vec(viewport.axis.x);
	print_vec(viewport.axis.y);
	print_vec(viewport.axis.z);
	
	
	
}


// int main()
// {
//     void *mlx;
//     t_data data;
// 	t_img img;
// 	char *buffer;

// 	mlx = mlx_init();
// 	data.winp = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "pmew");
//     data.imgp = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);


// 	// initial data
// 	buffer = mlx_get_data_addr(data.imgp, &img.pixel_bits, &img.line_bytes, &img.endian);
// 	mock_data(&data);
// 	// passing object

// 	printf("Type of obj: %d\n",(data.obj)->type);

// 	// rendering
// 	render(&data, &img, &buffer);
// 	mlx_put_image_to_window(mlx, data.winp, data.imgp, 0, 0);

// 	// loop
//     mlx_loop(mlx);
// }
