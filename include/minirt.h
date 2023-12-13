/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 03:41:23 by ktunchar          #+#    #+#             */
/*   Updated: 2023/12/13 23:09:09 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIN_WIDTH 900
# define WIN_HEIGHT 600
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>


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

typedef struct s_axis{
	t_vec	dir;
	t_vec	vert;
	t_vec	hori;
} t_axis;

typedef struct s_cam{
	int 	fov;
	float	ver_height;
	float	ver_width;
	t_pnt	pnt;
	t_vec	normal_vec;
	t_axis	axis;
	t_vec	ray_dir;
} t_cam;

typedef struct t_ray{
	t_pnt	pnt;
	t_vec	vec;
} t_ray;

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

typedef struct s_img{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
}t_img;


typedef struct s_data{
	t_light		**light;
	t_sphere	**sphere;
	t_plane		**plane;
	t_cylin		**cylin;
	t_cam		cam;
	t_amb		amb;
	void		*mlxp;
	void		*winp;
	void		*imgp;
} t_data;

typedef enum e_bool{
	False,
	True
}t_bool;

t_bool render(t_data *data, int width, int height);
int	get_color(int x, int y);


#endif