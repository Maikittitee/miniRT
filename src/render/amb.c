/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   amb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:28:04 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/20 17:29:56 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_color apply_ambient(t_color color, t_amb amb)
{
	t_color amb_col = color_scaler(amb.ratio, color);
	
	
}