/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 03:41:23 by ktunchar          #+#    #+#             */
/*   Updated: 2023/08/14 02:48:56 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_color{
	unsigned char r;
	unsigned char g;
	unsigned char b;
} t_color;

typedef struct s_pnt{
	float	x;
	float	y;
	float	z;
} t_pnt;

typedef struct s_vec{
	float	i;
	float	j;
	float	k;
} t_vec;

typedef struct s_amb{
	float	ratio;
	t_color	color;
} t_amb;

typedef struct s_cam{
	int 	fov;
	t_pnt	pnt;
	t_vec	normal_vec;		
} t_cam;

typedef struct s_light{
	float ratio;
	t_pnt pnt;
} t_light;

typedef struct s_sphere{
	t_color color;
	t_pnt	pnt;
	float	d;	
} t_sphere;

typedef	struct s_plane{
	t_color color;
	t_pnt	pnt;
	t_vec	normal_vec;
} t_plane;

typedef struct s_cylin{
	t_color	color;
	t_pnt	pnt;
	t_vec	normal_vec;
	float	d;
	float	h;
}t_cylin;

typedef struct s_data{
	t_light		**light;
	t_sphere	**sphere;
	t_plane		**plane;
	t_cylin		**cylin;
	t_cam		cam;
	t_amb		amb;
} t_data;

#endif