/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:28:04 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/21 23:28:05 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// t_color color_sqrt(t_color a)
// {
// 	return (t_color){}
// }

t_color color_mult(t_color a, t_color b)
{
	return (t_color){a.r * b.r / 255, a.g * b.g / 255, a.b * b.b / 255, 255};
}

t_color color_add_w(t_color c1, t_color c2, float wa)
{
	float r = (wa * c1.r) + (1.0f - wa) * c2.r;
	float g = (wa * c1.g) + (1.0f - wa) * c2.g;
	float b = (wa * c1.b) + (1.0f - wa) * c2.b;

	return ((t_color){fmin(r, 255), fmin(g, 255), fmin(b, 255), 255});
}

t_color apply_ambient(t_color color, t_amb amb)
{
	amb.color = color_scaler(amb.ratio, amb.color);
	return (color_add(amb.color, color));	
	// return (color_add(abs_amb_color, color));


	// blend_color = color_scaler(0.5f , color_add(color, amb.color));
	// blend_color.r = sqrt(blend_color.r);
	// blend_color.r = sqrt(blend_color.g);
	// blend_color.r = sqrt(blend_color.b);
	// return (blend_color);
}