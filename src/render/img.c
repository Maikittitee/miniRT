/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 01:28:07 by ktunchar          #+#    #+#             */
/*   Updated: 2024/01/15 16:00:44 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	my_put_to_img(char *buffer, t_img img, t_vec pnt, t_color color)
{
	int pixel = (pnt.j * img.line_bytes) + (pnt.i * 4);
	// printf("color: %d %d %d\n", color.r, color.g, color.b);
	if (img.endian == 1)        // Most significant (Alpha) byte first
	{
		buffer[pixel + 0] = (1);
		buffer[pixel + 1] = (color.r) & 0xFF;
		buffer[pixel + 2] = (color.g) & 0xFF;
		buffer[pixel + 3] = (color.b) & 0xFF;
	}
	else if (img.endian == 0)   // Least significant (Blue) byte first
	{
		buffer[pixel + 0] = (color.b) & 0xFF;
		buffer[pixel + 1] = (color.g) & 0xFF;
		buffer[pixel + 2] = (color.r) & 0xFF;
		buffer[pixel + 3] = (1);
	}
}