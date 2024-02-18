/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:50:02 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/19 01:01:52 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	close_win(t_data data)
{
	(void)data;
	// free(data.obj);
	// mlx_destroy_image(data.mlxp, data.imgp);
	// mlx_destroy_window(data.mlxp, data.winp);
	exit(0);
}

int	ft_exit(int keycode, t_data data)
{
	if (keycode == ESC_KEY)
	{
		free(data.obj);
		// mlx_destroy_image(data.mlxp, data.imgp);
		// mlx_destroy_window(data.mlxp, data.winp);
		exit(0);
	}
	return (0);
}