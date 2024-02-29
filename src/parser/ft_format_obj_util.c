/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_obj_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 20:23:02 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/29 22:54:26 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	ft_fmt_l(t_data *data)
{
	if (ft_cnt2d(data->ps.sp_line) != 3)
		return (-1);
	if (ft_check_float(data->ps.sp_line[1]) == -1)
		return (-1);
	if (ft_checkratio(data->ps.sp_line[2]) == -1)
		return (-1);
	return (0);
}

int	ft_fmt_c(t_data *data)
{
	if (ft_cnt2d(data->ps.sp_line) != 4)
		return (-1);
	if (ft_check_float(data->ps.sp_line[1]) == -1)
		return (-1);
	if (ft_check_float(data->ps.sp_line[2]) == -1)
		return (-1);
	if (ft_notnbr(data->ps.sp_line[3]) == -1)
		return (-1);
	return (0);
}

int	ft_fmt_a(t_data *data)
{
	if (ft_cnt2d(data->ps.sp_line) != 3)
		return (-1);
	if (ft_checkratio(data->ps.sp_line[1]) == -1)
		return (-1);
	if (ft_check_clr(data->ps.sp_line[2]) == -1)
		return (-1);
	return (0);
}
