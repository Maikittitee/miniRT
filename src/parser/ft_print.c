/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:03:28 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/15 13:40:45 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	ft_print_ambient(t_data *data)
{
	printf(GRN"Ambient\n"RESET);
	printf("Ambient ratio : %.2f\n", data->amb.ratio);
	printf("Color R : %u\n", data->amb.color.r);
	printf("Color G : %u\n", data->amb.color.g);
	printf("Color B : %u\n", data->amb.color.b);
	printf("Color A : %u\n", data->amb.color.a);
}
void	ft_print_cam(t_data *data)
{
	printf(GRN"Camera\n"RESET);
	printf("vec_ori[i] : %.2f\n", data->cam.ori.i);
	printf("vec_ori[j] : %.2f\n", data->cam.ori.j);
	printf("vec_ori[k] : %.2f\n", data->cam.ori.k);
	printf("vec_norm[i]  : %.2f\n", data->cam.normal_vec.i);
	printf("vec_norm[j]  : %.2f\n", data->cam.normal_vec.j);
	printf("vec_norm[k]  : %.2f\n", data->cam.normal_vec.k);
	printf("FOV : %d\n", data->cam.fov);
}
void	ft_print2d(char **str)
{
	int i;

	i = -1;
	while(str[++i])
		printf("line[%d] : %s\n",i , str[i]);
}

void ft_print_sphere(t_obj *sphere)
{

	printf(GRN"Sphere\n"RESET);
	printf("vec.i : %.2f\n", sphere->ori.i);
	printf("vec.j : %.2f\n", sphere->ori.j);
	printf("vec.k : %.2f\n", sphere->ori.k);
	printf("di : %.2f\n", sphere->d);
	printf("clr[r] : %u\n", sphere->color.r);
	printf("clr[g] : %u\n", sphere->color.g);
	printf("clr[b] : %u\n", sphere->color.b);
}
void ft_print_cyl(t_obj *cl)
{
	printf(GRN"Cylinder\n"RESET);
	printf("vec_coor[i] : %.2f\n", cl->ori.i);
	printf("vec_coor[j] : %.2f\n", cl->ori.j);
	printf("vec_coor[k] : %.2f\n", cl->ori.k);
	printf("vec_norm[i] : %.2f\n", cl->normal_vec.i);
	printf("vec_norm[j] : %.2f\n", cl->normal_vec.j);
	printf("vec_norm[k] : %.2f\n", cl->normal_vec.k);
	printf("di : %.2f\n", cl->d);
	printf("height : %.2f\n", cl->h);
	printf("clr[r] : %u\n", cl->color.r);
	printf("clr[g] : %u\n", cl->color.g);
	printf("clr[b] : %u\n", cl->color.b);

}

void	ft_print_pl(t_obj *pl)
{
	printf(GRN"plane\n"RESET);
	printf("vec_ori[i] : %.2f\n", pl->ori.i);
	printf("vec_ori[j] : %.2f\n", pl->ori.j);
	printf("vec_ori[k] : %.2f\n", pl->ori.k);
	printf("vec_norm[i] : %.2f\n", pl->normal_vec.i);
	printf("vec_norm[j] : %.2f\n", pl->normal_vec.j);
	printf("vec_norm[k] : %.2f\n", pl->normal_vec.k);
	printf("clr[r] : %u\n", pl->color.r);
	printf("clr[g] : %u\n", pl->color.g);
	printf("clr[b] : %u\n", pl->color.b);

}

void	ft_printmain(t_data *data)
{
	unsigned int	i;

	i = 0;
	// printf("start_print\n");
	ft_print_ambient(data);
	printf("\n");
	// printf("after print_amb\n");
	ft_print_cam(data);
	// printf("nnobj : %d\n", data->nobj);
	while(i < data->nobj)
	{
		printf("---------- %d -----------\n", i);
		if (data->obj[i].type == SPHERE)
			ft_print_sphere(&data->obj[i]);
		else if (data->obj[i].type == CYLINDER)
			ft_print_cyl(&data->obj[i]);
		else if (data->obj[i].type == PLANE)
			ft_print_pl(&data->obj[i]);
		printf("\n");
		i++;
	}
}