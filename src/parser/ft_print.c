/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 09:03:28 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/07 16:32:32 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	ft_print_ambient(t_data *data)
{
	printf("Ambient\n");
	printf("Ambient ratio : %f\n", data->amb.ratio);
	printf("Color R : %u\n", data->amb.color.r);
	printf("Color G : %u\n", data->amb.color.g);
	printf("Color B : %u\n", data->amb.color.b);
	printf("Color A : %u\n", data->amb.color.a);
}
void	ft_print_cam(t_data *data)
{
	printf("normal vec I : %f\n", data->cam.normal_vec.i);
	printf("normal vec J : %f\n", data->cam.normal_vec.j);
	printf("normal vec K : %f\n", data->cam.normal_vec.k);
	printf("FOV : %d\n", data->cam.fov);
}
void	ft_print2d(char **str)
{
	int i;

	i = -1;
	while(str[++i])
		printf("line[%d] : %s\n",i , str[i]);
}

void	ft_printmain(t_data *data)
{
	ft_print_ambient(data);
	ft_print_cam(data);
}