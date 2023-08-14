/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 22:23:20 by ktunchar          #+#    #+#             */
/*   Updated: 2023/08/14 22:36:30 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_data *init_data(char *filename)
{
	t_data *data;
	(void)filename;

	data = malloc(sizeof(t_data));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "ktunchar's MiniRT");
	data->img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	// read file;
	return (data);

}