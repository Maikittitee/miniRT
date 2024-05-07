/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:54:25 by nkietwee          #+#    #+#             */
/*   Updated: 2024/05/08 01:46:29 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	ft_prt_cy(t_obj *cy)
{
	printf(GRN"CYLINDER\n"RESET);
	printf("Vec_ori[x] : %f\n", cy->ori.x);
	printf("Vec_ori[y] : %f\n", cy->ori.y);
	printf("Vec_ori[z] : %f\n\n", cy->ori.z);
	printf("Vec_norm[x] : %f\n", cy->normal_vec.x);
	printf("Vec_norm[y] : %f\n", cy->normal_vec.y);
	printf("Vec_norm[z] : %f\n\n", cy->normal_vec.z);
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
	printf("Vec_ori[x] : %f\n", pl->ori.x);
	printf("Vec_ori[y] : %f\n", pl->ori.y);
	printf("Vec_ori[z] : %f\n\n", pl->ori.z);
	printf("Vec_norm[x] : %f\n", pl->normal_vec.x);
	printf("Vec_norm[y] : %f\n", pl->normal_vec.y);
	printf("Vec_norm[z] : %f\n\n", pl->normal_vec.z);
	printf("clr[r] : %d\n", pl->color.r);
	printf("clr[g] : %d\n", pl->color.g);
	printf("clr[b] : %d\n", pl->color.b);
	printf("clr[a] : %d\n", pl->color.a);
}

void	ft_prt_sp(t_obj *sp)
{
	printf(GRN"Sphere\n"RESET);
	printf("Vec_ori[x] : %f\n", sp->ori.x);
	printf("Vec_ori[y] : %f\n", sp->ori.y);
	printf("Vec_ori[z] : %f\n\n", sp->ori.z);
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
	ft_prt_amb(data->amb);
	ft_prt_cam(data->cam);
	ft_prt_light(data->light);
	while (i < data->nobj)
	{
		printf("%d\n", i);
		if (data->obj[i].type == SPHERE)
			ft_prt_sp(&data->obj[i]);
		else if (data->obj[i].type == CYLIN)
			ft_prt_cy(&data->obj[i]);
		else if (data->obj[i].type == PLANE)
			ft_prt_pl(&data->obj[i]);
		i++;
	}
}
