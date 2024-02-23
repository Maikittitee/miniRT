/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:54:25 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/23 18:35:14 by nkietwee         ###   ########.fr       */
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
	printf("Camera\n");
	printf("Vec_ori[i] : %f\n", cam.ori.i);
	printf("Vec_ori[j] : %f\n", cam.ori.j);
	printf("Vec_ori[k] : %f\n\n", cam.ori.k);
	printf("Vec_norm[i] : %f\n", cam.normal_vec.i);
	printf("Vec_norm[j] : %f\n", cam.normal_vec.j);
	printf("Vec_norm[k] : %f\n\n", cam.normal_vec.k);
	printf("FOV : %d\n", cam.fov);
}

void	ft_prt_amb(t_amb amb)
{
	printf("Ambient\n");
	printf("ratio : %f\n", amb.ratio);
	printf("clr[r] : %d\n", amb.color.r);
	printf("clr[g] : %d\n", amb.color.g);
	printf("clr[b] : %d\n", amb.color.b);
	printf("clr[a] : %d\n", amb.color.a);
}

void	ft_prt_light(t_light light)
{
	printf("Light\n");
	printf("Vec_ori[i] : %f\n", light.ori.i);
	printf("Vec_ori[j] : %f\n", light.ori.j);
	printf("Vec_ori[k] : %f\n\n", light.ori.k);
	printf("ratio : %f\n", light.ratio);
}
