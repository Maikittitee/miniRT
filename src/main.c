/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:26:07 by ktunchar          #+#    #+#             */
/*   Updated: 2023/12/07 16:44:45 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int main()
{
    void *mlx = mlx_init();
    void *win = mlx_new_window(mlx, WIN_WIDTH, WIN_HEIGHT, "Tutorial Window - Create Image");

    void *image = mlx_new_image(mlx, WIN_WIDTH, WIN_HEIGHT);
    
	printf("hello\n");

	render(image, WIN_WIDTH, WIN_HEIGHT);
    // The following code goes here

	mlx_put_image_to_window(mlx, win, image, 0, 0);

    mlx_loop(mlx);
}
