/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:46:10 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/20 23:02:34 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int ft_checkobj(char *str)
{
	if (ft_strcmp(str, "cy") == 0 || ft_strcmp(str, "sp") == 0
	|| ft_strcmp(str, "pl") == 0)
		return (1);
	return (0);
}

int	ft_check_cntobj(t_data *data)
{
	if ((ft_strcmp(data->ps.sp_line[0], "cy") == 0) || \
		(ft_strcmp(data->ps.sp_line[0], "pl") == 0) || \
		(ft_strcmp(data->ps.sp_line[0], "sp") == 0))
		data->nobj++;
	else if (ft_strcmp(data->ps.sp_line[0], "A") == 0)
		data->ps.cnt_a++;
	else if (ft_strcmp(data->ps.sp_line[0], "C") == 0)
		data->ps.cnt_c++;
	else if (ft_strcmp(data->ps.sp_line[0], "L") == 0)
		data->ps.cnt_l++;
	else
		return (-1);
	return (0);
}

int	ft_check_obj(char *file, t_data *data, int *state)
{
	data->ps.fd = open(file, O_RDONLY);
	if (data->ps.fd == -1)
		return (-1);
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
			if (ft_check_cntobj(data) == -1)
				*state = -1;
			ft_doublefree(data->ps.sp_line);
		}
		free(data->ps.line);
	}
}

int	ft_cnt2d(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

// int	ft_cnt_sp(char **str)

