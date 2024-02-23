/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:54:25 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/23 18:35:48 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	ft_prt_cy(t_obj *cy)
{
	printf(GRN"CYLINDER\n"RESET);
	printf("Vec_ori[i] : %f\n", cy->ori.i);
	printf("Vec_ori[j] : %f\n", cy->ori.j);
	printf("Vec_ori[k] : %f\n\n", cy->ori.k);
	printf("Vec_norm[i] : %f\n", cy->normal_vec.i);
	printf("Vec_norm[j] : %f\n", cy->normal_vec.j);
	printf("Vec_norm[k] : %f\n\n", cy->normal_vec.k);
	printf("di : %f\n", cy->d);
	printf("height : %f\n", cy->h);
	printf("clr[r] : %d\n", cy->color.r);
	printf("clr[g] : %d\n", cy->color.g);
	printf("clr[b] : %d\n", cy->color.b);
	printf("clr[a] : %d\n", cy->color.a);
}

void	ft_prt_pl(t_obj *pl)
{
	printf(GRN"PLANE\n"RESET);
	printf("Vec_ori[i] : %f\n", pl->ori.i);
	printf("Vec_ori[j] : %f\n", pl->ori.j);
	printf("Vec_ori[k] : %f\n\n", pl->ori.k);
	printf("Vec_norm[i] : %f\n", pl->normal_vec.i);
	printf("Vec_norm[j] : %f\n", pl->normal_vec.j);
	printf("Vec_norm[k] : %f\n\n", pl->normal_vec.k);
	printf("clr[r] : %d\n", pl->color.r);
	printf("clr[g] : %d\n", pl->color.g);
	printf("clr[b] : %d\n", pl->color.b);
	printf("clr[a] : %d\n", pl->color.a);
}

void	ft_prt_sp(t_obj *sp)
{
	printf(GRN"Sphere\n"RESET);
	printf("Vec_ori[i] : %f\n", sp->ori.i);
	printf("Vec_ori[j] : %f\n", sp->ori.j);
	printf("Vec_ori[k] : %f\n\n", sp->ori.k);
	printf("di : %f\n", sp->d);
	printf("clr[r] : %d\n", sp->color.r);
	printf("clr[g] : %d\n", sp->color.g);
	printf("clr[b] : %d\n", sp->color.b);
	printf("clr[a] : %d\n", sp->color.a);
}

void	ft_prt_obj(t_data *data)
{
	unsigned int	i;

	i = 0;
	while (i < data->nobj)
	{
		printf("----%d----\n", i);
		if (data->obj[i].type == SPHERE)
			ft_prt_sp(&data->obj[i]);
		else if (data->obj[i].type == CYLINDER)
			ft_prt_cy(&data->obj[i]);
		else if (data->obj[i].type == PLANE)
			ft_prt_pl(&data->obj[i]);
		i++;
	}
}
