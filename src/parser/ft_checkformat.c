/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:21:45 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/19 01:34:22 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	ft_checkratio(char *str)
{
	int len_point;

	if (ft_isdigit(str[0]) == 0)
		return (-1);
	if (ft_not(str, NOT_NBR_POINT) == -1)
	{
		// printf("str : %s\n", str);
		// printf("3333\n");
		return (-1);
	}
	len_point = ft_count_char(str, '.');
	if (len_point == 0 || len_point == 1)
		return (0);
	else
		return (-1);
	return (0);
}

int	ft_check_formatobj(t_data *data)
{
	// printf("----\n");
	// printf("check format_a : %d\n", ft_fmt_a(data));
	// printf("check format_c : %d\n", ft_fmt_c(data));
	// printf("check format_l : %d\n", ft_fmt_l(data));
	// printf("check format_cy : %d\n", ft_fmt_cy(data));
	// printf("check format_sp : %d\n", ft_fmt_sp(data));
	// printf("check format_pl : %d\n", ft_fmt_pl(data));
	if (ft_strcmp(data->ps.sp_line[0], "A") == 0)
		return (ft_fmt_a(data));
	else if (ft_strcmp(data->ps.sp_line[0], "C") == 0)
		return (ft_fmt_c(data));
	else if (ft_strcmp(data->ps.sp_line[0], "L") == 0)
		return (ft_fmt_l(data));
	else if (ft_strcmp(data->ps.sp_line[0], "cy") == 0)
		return (ft_fmt_cy(data));
	else if (ft_strcmp(data->ps.sp_line[0], "sp") == 0)
		return (ft_fmt_sp(data));
	else if (ft_strcmp(data->ps.sp_line[0], "pl") == 0)
		return (ft_fmt_pl(data));
	return(0);
}

int	ft_checkformat(t_data *data, char *file, int *state)
{
	data->ps.fd = open(file, O_RDONLY);
	if (data->ps.fd == -1)
		return (0);
	while (1)
	{
		data->ps.line = get_next_line(data->ps.fd);
		if (!data->ps.line)
		{
			close(data->ps.fd);
			return (0);
		}
		if (data->ps.line[0] != '\n')
		{
			data->ps.sp_line = ft_split(data->ps.line, ' ');
			if (ft_check_formatobj(data) == -1)
				*state = -1;
			// printf("ft_check format obj : %d\n", ft_check_formatobj(data));
			ft_doublefree(data->ps.sp_line);
		}
		free(data->ps.line);
	}
	return (0);
}
