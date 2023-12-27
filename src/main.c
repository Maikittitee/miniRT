/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:26:07 by ktunchar          #+#    #+#             */
/*   Updated: 2023/12/28 01:32:57 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int main()
{
    void *mlx;
    t_data data;
	t_img img;
	char *buffer;
    
	mlx = mlx_init();
	data.winp = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "pmew");
    data.imgp = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT); 


	// initial data
	buffer = mlx_get_data_addr(data.imgp, &img.pixel_bits, &img.line_bytes, &img.endian);

	// passing object

	// rendering 
	render(&data, &img, &buffer);
	mlx_put_image_to_window(mlx, data.winp, data.imgp, 0, 0);

	// loop	
    mlx_loop(mlx);
}
