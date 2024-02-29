/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:54:25 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/29 23:13:19 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	ft_print2d(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		printf("sp2d[%d] : %s\n", i, str[i]);
}

void	ft_prt_cam(t_cam cam)
{
	printf(GRN"Camera\n"RESET);
	printf("Vec_origin[x] : %f\n", cam.origin.x);
	printf("Vec_origin[y] : %f\n", cam.origin.y);
	printf("Vec_origin[z] : %f\n\n", cam.origin.z);
	printf("Vec_norm[x] : %f\n", cam.direction.x);
	printf("Vec_norm[y] : %f\n", cam.direction.y);
	printf("Vec_norm[z] : %f\n\n", cam.direction.z);
	printf("FOV : %d\n", cam.fov);
}

void	ft_prt_amb(t_amb amb)
{
	printf(GRN"Ambient\n"RESET);
	printf("ratio : %f\n", amb.ratio);
	printf("clr[r] : %d\n", amb.color.r);
	printf("clr[g] : %d\n", amb.color.g);
	printf("clr[b] : %d\n", amb.color.b);
	printf("clr[a] : %d\n", amb.color.a);
}

void	ft_prt_light(t_light light)
{
	printf(GRN"Light\n"RESET);
	printf("Vec_ori[i] : %f\n", light.ori.x);
	printf("Vec_ori[j] : %f\n", light.ori.y);
	printf("Vec_ori[k] : %f\n\n", light.ori.z);
	printf("ratio : %f\n", light.ratio);
}
