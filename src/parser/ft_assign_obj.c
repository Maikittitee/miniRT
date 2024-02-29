/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_obj.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 01:08:21 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/29 23:05:15 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_obj	ft_assign_cy(char **sp_line, int *state)
{
	t_obj	cy;

	cy.type = CYLIN;
	cy.ori = ft_vector_coor(sp_line[1], state);
	if (*state == -1)
		return (cy);
	cy.normal_vec = ft_vector_norm(sp_line[2], state);
	if (*state == -1)
		return (cy);
	cy.d = ft_atof(sp_line[3]);
	cy.h = ft_atof(sp_line[4]);
	if (cy.d < 0 || cy.h < 0)
	{
		*state = -1;
		return (cy);
	}
	cy.color = ft_assign_clr(sp_line[5], state);
	if (*state == -1)
		return (cy);
	return (cy);
}

t_obj	ft_assign_pl(char **sp_line, int *state)
{
	t_obj	pl;

	pl.type = PLANE;
	pl.ori = ft_vector_coor(sp_line[1], state);
	if (*state == -1)
		return (pl);
	pl.normal_vec = ft_vector_norm(sp_line[2], state);
	if (*state == -1)
		return (pl);
	pl.color = ft_assign_clr(sp_line[3], state);
	return (pl);
}

t_obj	ft_assign_sph(char **sp_line, int *state)
{
	t_obj	sph;

	sph.type = SPHERE;
	sph.ori = ft_vector_coor(sp_line[1], state);
	if (*state == -1)
		return (sph);
	sph.d = ft_atof(sp_line[2]);
	if (sph.d < 0)
	{
		*state = -1;
		return (sph);
	}
	sph.color = ft_assign_clr(sp_line[3], state);
	return (sph);
}

int	ft_assign_obj(t_data *data, int *i, int *state)
{
	if (ft_strcmp(data->ps.sp_line[0], "A") == 0)
		data->amb = ft_assign_amb(data->ps.sp_line, state);
	else if (ft_strcmp(data->ps.sp_line[0], "C") == 0)
		data->cam = ft_assign_cam(data->ps.sp_line, state);
	else if (ft_strcmp(data->ps.sp_line[0], "L") == 0)
		data->light = ft_assign_light(data->ps.sp_line, state);
	else if (ft_checkobj(data->ps.sp_line[0]) == 1)
	{
		if (ft_strcmp(data->ps.sp_line[0], "sp") == 0)
			data->obj[*i] = ft_assign_sph(data->ps.sp_line, state);
		else if (ft_strcmp(data->ps.sp_line[0], "pl") == 0)
			data->obj[*i] = ft_assign_pl(data->ps.sp_line, state);
		else if (ft_strcmp(data->ps.sp_line[0], "cy") == 0)
			data->obj[*i] = ft_assign_cy(data->ps.sp_line, state);
		(*i)++;
	}
	if (*state == -1)
		return (-1);
	return (0);
}

int	ft_assign(char *file, int *state, t_data *data)
{
	int	i;

	i = 0;
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
			ft_assign_obj(data, &i, state);
			if (*state == -1)
				*state = -1;
			ft_doublefree(data->ps.sp_line);
		}
		free (data->ps.line);
	}
	return (0);
}
