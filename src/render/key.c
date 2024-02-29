/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:50:02 by ktunchar          #+#    #+#             */
/*   Updated: 2024/03/01 01:31:35 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	close_win(t_data data)
{
	(void)data;
	exit(0);
}

int	ft_exit(int keycode, t_data data)
{
	(void)data;
	if (keycode == ESC_KEY)
	{
		exit(0);
	}
	return (0);
}
