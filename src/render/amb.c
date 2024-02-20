/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:28:04 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/20 22:40:09 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color apply_ambient(t_color color, t_amb amb)
{
	// amb.color = color_scaler(amb.ratio, amb.color);
	// t_color amb_col = color_scaler(1.0f / 255.0f , amb.color);

	// color = color_scaler( 1.0f / 255.0f, color);

	float fux = 1.0f/255.0f;	
	float r = amb.color.r * color.r;
	float g = amb.color.g * color.g;
	float b = amb.color.b * color.b;

	color.r = r * fux;
	color.g = g * fux;
	color.b = b * fux;
	
	return (color);
	// return (obj_col_inv);
	// return (color_add(color, ));
}