/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 22:55:52 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/23 21:14:50 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

t_vec	ft_vector_norm(char *str, int *state)
{
	t_vec	norm;
	char	**sp_norm;

	sp_norm = ft_split(str, ',');
	norm.i = 0;
	norm.j = 0;
	norm.k = 0;
	if (ft_cnt2d(sp_norm) != 3)
	{
		*state = -1;
		ft_doublefree(sp_norm);
		return (norm);
	}
	norm.i = ft_atof(sp_norm[0]);
	norm.j = ft_atof(sp_norm[1]);
	norm.k = ft_atof(sp_norm[2]);
	if ((norm.i < -1 || norm.i > 1) || (norm.j < -1 || norm.j > 1) \
	|| (norm.k < -1 || norm.k > 1))
	{
		*state = -1;
		ft_doublefree(sp_norm);
		return (norm);
	}
	ft_doublefree(sp_norm);
	return (norm);
}

t_vec	ft_vector_coor(char *str, int *state)
{
	t_vec	vec;
	char	**sp_vec;

	sp_vec = ft_split(str, ',');
	// ft_print2d(sp_vec);
	vec.i = 0;
	vec.j = 0;
	vec.k = 0;
	if (ft_cnt2d(sp_vec) != 3)
	{
		*state = -1;
		ft_doublefree(sp_vec);
		return (vec);
	}
	vec.i = ft_atof(sp_vec[0]);
	vec.j = ft_atof(sp_vec[1]);
	vec.k = ft_atof(sp_vec[2]);
	ft_doublefree(sp_vec);
	return (vec);
}

t_color	ft_assign_clr(char *sp_line, int *state)
{
	char	**sp_clr;
	t_color	clr;
	t_state	st;

	sp_clr = ft_split(sp_line, ',');
	clr.r = 0;
	clr.g = 0;
	clr.b = 0;
	if (ft_cnt2d(sp_clr) != 3)
	{
		*state = -1;
		return (clr);
	}
	clr.r = ft_atorgb(sp_clr[0], &st.state_r);
	clr.g = ft_atorgb(sp_clr[1], &st.state_g);
	clr.b = ft_atorgb(sp_clr[2], &st.state_b);
	clr.a = 255;
	if (st.state_r == -1 || st.state_g == -1 || st.state_b == -1)
	{
		*state = -1;
		ft_doublefree(sp_clr);
		return (clr);
	}
	ft_doublefree(sp_clr);
	return (clr);
}
