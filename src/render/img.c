/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 01:28:07 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/29 17:27:26 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	my_put_to_img(char *buffer, t_img img, t_vec pnt, t_color color)
{
	int	pixel;

	pixel = (pnt.y * img.line_bytes) + (pnt.x * 4);
	if (img.endian == 1)
	{
		buffer[pixel + 0] = (1);
		buffer[pixel + 1] = (color.r) & 0xFF;
		buffer[pixel + 2] = (color.g) & 0xFF;
		buffer[pixel + 3] = (color.b) & 0xFF;
	}
	else if (img.endian == 0)
	{
		buffer[pixel + 0] = (color.b) & 0xFF;
		buffer[pixel + 1] = (color.g) & 0xFF;
		buffer[pixel + 2] = (color.r) & 0xFF;
		buffer[pixel + 3] = (1);
	}
}
