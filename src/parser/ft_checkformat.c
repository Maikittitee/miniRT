/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkformat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 18:21:45 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/17 21:28:41 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	ft_checkratio(char *str)
{
	//check not nbr
	if (ft_isdigit(str[0]) == 0)
		return(-1);
	if (ft_check_notnbr_point(str) == -1)
		return (-1);
	if (ft_count_char(str, '.') != 1)
		return (-1);
	return (0);
}



int	ft_check_formatobj(t_data *data)
{
	if (ft_strcmp(data->ps.sp_line[0], "A") == 0)
		return(ft_fmt_a(data));
	// printf("check format : %d\n", ft_fmt_a(data));
	// printf("exit format\n");
	// else if (ft_strcmp(data->ps.sp_line[0], "C") == 0)

	// else if (ft_strcmp(data->ps.sp_line[0], "L") == 0)
	// else if (ft_strcmp(data->ps.sp_line[0], "cy") == 0)

	// else if	(ft_strcmp(data->ps.sp_line[0], "pl") == 0)

	// else if	(ft_strcmp(data->ps.sp_line[0], "sp") == 0)

	return(0);
}

int	ft_checkformat(t_data *data ,char *file, int *state)
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
