/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:23:02 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/17 21:45:37 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	ft_fmt_a(t_data *data)
{
	(void)data;
	// printf("format_a\n");

	// ft_print2d(data->ps.sp_line);
	if (ft_cnt2d(data->ps.sp_line) != 3)
		return (-1);
	if (ft_checkratio(data->ps.sp_line[1]) == -1)
		return (-1);
	if (ft_check_clr(data->ps.sp_line[2]) == -1)
		return (-1);
	return(0);
}