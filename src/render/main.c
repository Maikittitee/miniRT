/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:26:07 by ktunchar          #+#    #+#             */
/*   Updated: 2024/03/05 18:17:01 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

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
	t_data		data;
	t_viewport	viewport;
	void		*mlx;
	t_img		img;
	char		*buffer;

	if (ac != 2)
		return (printf(RED"./miniRT [filename.rt]\n"RESET));
	ft_initdata(&data);
	if (ft_checkfile(&data, av[1]) == -1)
		return (printf(RED"Error\nFile\n"RESET));
	init_viewport(&viewport, &(data.cam));
	data.viewport = viewport;
	ft_prt_obj(&data);
	mlx = mlx_init();
	data.winp = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "pmew");
	data.imgp = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
	buffer = mlx_get_data_addr(data.imgp, &img.pixel_bits, \
	&img.line_bytes, &img.endian);
	printf("Rendering...\n");
	render(&data, &img, &buffer);
	mlx_put_image_to_window(mlx, data.winp, data.imgp, 0, 0);
	mlx_hook(data.winp, 17, 0, close_win, &data);
	mlx_hook(data.winp, 2, 1, ft_exit, &data);
	mlx_loop(mlx);
}
