/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 03:41:23 by ktunchar          #+#    #+#             */
/*   Updated: 2023/09/07 23:19:19 by ktunchar         ###   ########.fr       */
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
	void		*mlx;
	void		*win;
	void		*img;
} t_data;

typedef enum e_bool{
	False,
	True
}t_bool;

// init and readfile
t_data *init_data(char *filename);


// event handling
int     close_win(t_data *data);
int     ft_exit(int keycode, t_data *data);
void	my_put_to_img(char *buffer, t_img img, t_pnt pnt, t_color color);


//vector
float   dot_product(t_vec u, t_vec v);
t_vec cross_product(t_vec u, t_vec v);
t_vec sub(t_vec u, t_vec v);
t_vec cmultiply(t_vec u, float c);
float vec_size(t_vec u);
t_vec normalize(t_vec u);

#endif