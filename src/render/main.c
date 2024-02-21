/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:26:07 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/21 17:18:20 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// void	mock_data(t_data *data)
// {
// 	t_sphere sphere;

// 	sphere.color = (t_color){255, 0, 255, 255};
// 	sphere.d = 4;
// 	sphere.ori = (t_vec){0, 0, 0};

// 	t_obj *obj;

// 	obj = malloc(sizeof(t_obj));
// 	obj->obj = &sphere;
// 	obj->type = SPHERE;
// 	obj->next = NULL;

// 	data->obj = obj;
// }

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

void	ft_initdata(t_data *data)
{
	data->ps.fd = 0;
	data->ps.len = 0;

	data->ps.cnt_a = 0;
	data->ps.cnt_c = 0;
	data->ps.cnt_l = 0;
}
int	main(int ac, char **av)
{
	t_data data;

	if (ac != 2)
		return(printf(RED"./miniRT [filename.rt]\n"RESET));
	ft_initdata(&data);
	// printf("ft_checkfile : %d\n", ft_checkfile(&data, av[1]));
	if (ft_checkfile(&data, av[1]) == -1)
		return (printf(RED"File Error\n"RESET));
	ft_prt_obj(&data);
	// free(data.obj);
}