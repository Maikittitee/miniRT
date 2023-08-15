/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:58:58 by ktunchar          #+#    #+#             */
/*   Updated: 2023/08/15 16:12:52 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	my_put_to_img(char *buffer, t_img img, t_pnt pnt, t_color color)
{	
	int pixel = (pnt.y * img.line_bytes) + (pnt.x * 4);
			
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