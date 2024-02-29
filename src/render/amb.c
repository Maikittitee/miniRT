/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:28:04 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/29 17:14:48 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color	color_mult(t_color a, t_color b)
{
	return ((t_color){a.r * b.r / 255, a.g * b.g / 255, a.b * b.b / 255, 255});
}

t_color	color_add_w(t_color c1, t_color c2, float wa)
{
	float	r;
	float	g;
	float	b;

	r = (wa * c1.r) + (1.0f - wa) * c2.r;
	g = (wa * c1.g) + (1.0f - wa) * c2.g;
	b = (wa * c1.b) + (1.0f - wa) * c2.b;
	return ((t_color){fmin(r, 255), fmin(g, 255), fmin(b, 255), 255});
}

t_color	apply_ambient(t_color color, t_amb amb)
{
	amb.color = color_scaler(amb.ratio, amb.color);
	return (color_add(color, amb.color));
}
