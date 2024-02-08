/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:30:04 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/07 16:27:26 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	ft_doublefree(char **str)
{
	int	i;

	i = 0;
	if(!str)
		return;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_add_ambient(t_data *data, char **sp_line, int *mode)
{
	int		i;
	char	**sp;

	i = 1;
	printf(GRN"Hello ambient\n"RESET);
	while(sp_line[i])
	{
		if(sp_line[1])
			data->amb.ratio = ft_atof(sp_line[1]); // protect ratio [0.0 1.0]
		if (sp_line[2])
		{
			sp = ft_split(sp_line[2], ',');
			data->amb.color.r = ft_atousc(sp[0]);
			// printf("r : %d\n", data->amb.color.r);
			data->amb.color.g = ft_atousc(sp[1]);
			data->amb.color.b = ft_atousc(sp[2]);

			data->amb.color.a = 255;
			// protect r g b [0, 255]
			ft_doublefree(sp);
		}
		// protect i > 3
		return;
	}
	*mode = FOUND;
}

int	ft_add_camera(t_data *data, char **sp_line, int *mode)
{
	// ∗ x,y,z coordinates of the view point: -50.0,0,20
	// ∗ 3d normalized orientation vector. In range [-1,1] for each x,y,z axis:
	// 0.0,0.0,1.0
	// ∗ FOV : Horizontal field of view in degrees in range [0,180]: 70
	int	len;
	char **sp;

	len = ft_cnt2d(sp_line);
	if (len > 4)
		return(printf("Error file\n"));
	sp = ft_split(sp_line[2], ',');
	if (ft_cnt2d(sp) != 3)
		return(printf("Error file\n"));
	data->cam.normal_vec.i = ft_atof(sp[0]);
	data->cam.normal_vec.j = ft_atof(sp[1]);
	data->cam.normal_vec.k = ft_atof(sp[2]);
	data->cam.fov = ft_atoi(sp_line[3]);
	*mode = FOUND;
	return(0);
}

t_sphere	*ft_add_sphere(t_data *data, char **sp_line)
{
	char **sp_ori;
	char	**sp_clr;
	(void)data;
	t_sphere *sphere;

	sphere = malloc(sizeof(t_sphere));
	// ∗ R,G,B colors in range [0-255]: 10, 0, 255
	// ft_print2d(sp_line);
	if (ft_cnt2d(sp_line) != 4)
	{
		printf("Error file--\n");
		return(0);
	}
	sp_ori = ft_split(sp_line[1], ',');
	if (ft_cnt2d(sp_ori) != 3)
	{
		printf("Error file\n");
		return(0);
	}
	sphere->ori.i = ft_atof(sp_ori[0]);
	sphere->ori.j = ft_atof(sp_ori[1]);
	sphere->ori.k = ft_atof(sp_ori[2]);
	// printf("i : %f\n", sphere.ori.i);
	// printf("j : %f\n", sphere.ori.j);
	// printf("k : %f\n", sphere.ori.k);
	sp_clr = ft_split(sp_line[3], ',');
	// ft_print2d(sp_clr);
	// printf("sp_line 3 : %s\n", sp_line[3]);
	// printf("sp_clr : %s\n", sp_clr[0]);
	// printf("sp_clr : %s\n", sp_clr[1]);
	// printf("sp_clr : %s\n", sp_clr[2]);

	// sphere.color.r = 0;
	// printf("after prt color\n");
	sphere->d = ft_atof(sp_line[3]);
	// printf("di : %f\n", sphere.d);
	sphere->color.r = ft_atousc(sp_clr[0]);
	sphere->color.g = ft_atousc(sp_clr[1]);
	sphere->color.b = ft_atousc(sp_clr[2]);
	// printf("r : %d\n", sphere.color.r);
	// printf("g : %d\n", sphere.color.g);
	// printf("b : %d\n", sphere.color.b);

	// data->obj->obj = sphere;
	// assign value
	ft_doublefree(sp_clr);
	// ft_doublefree(sp);
	// ft_print2d(sp);
	return(0);
}

t_data	*ft_addvalue(char *file, t_data *data)
{
	char 	*line;
	char	**sp_line;
	int		fd;
	// int		mode;
	int		cnt_obj;

	// mode = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return(0);
	// printf("fd : %d\n", fd);
	cnt_obj = ft_cnt_obj(file);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		if(line[0] != '\n')
		{
			sp_line = ft_split(line, ' ');
			// ft_print2d(sp_line);
			// if (ft_strcmp(sp_line[0], "A") == 0)
			// 	ft_add_ambient(data, sp_line, &mode);
			// if (ft_strcmp(sp_line[0], "C") == 0)
			// 	ft_add_camera(data, sp_line, &mode);
			if(ft_checkobj(sp_line[0]) == FOUND)
				ft_assign_obj(cnt_obj, data, sp_line);
			// if (ft_strcmp(sp_line[0], "sp") == 0)
				// ft_add_sphere(data, sp_line, &mode);
			// if (ft_strcmp(sp_line[0], "pl") == 0)
			// if (ft_strcmp(sp_line[0], "cy") == 0)
			// ft_printmain(data);

			// check duplicate variable
			ft_doublefree(sp_line);
		}
		free(line);
	}
}


