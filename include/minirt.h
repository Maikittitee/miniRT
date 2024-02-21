/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 03:41:23 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/18 17:43:17 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIN_WIDTH 900
# define WIN_HEIGHT 600
# include "../lib/libft_gnl/libft.h"
# include "../lib/mlx/mlx.h"
# include "parser.h"
# include "color.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>


typedef struct s_color{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
} t_color;

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

typedef struct s_viewport{
	float width;
	float height;
	t_vec step_x;
	t_vec step_y;
	t_vec origin;
	t_axis axis;
	t_vec width_vec;
	t_vec height_vec;
	t_vec upper_left_px;
} t_viewport;

typedef struct s_cam{
	int 	fov;
	float	ver_height;
	float	ver_width;
	t_vec	ori;
	t_vec	normal_vec;
	t_axis	axis;
	t_vec	ray_dir;
} t_cam;

typedef struct t_ray{
	t_vec	ori;
	t_vec	dir;
} t_ray;

typedef struct s_light{
	float ratio;
	t_vec ori;
} t_light;

typedef struct s_sphere{
	t_color color;
	t_vec	ori;
	float	d;
} t_sphere;

typedef	struct s_plane{
	t_color color;
	t_vec	ori;
	t_vec	normal_vec;
} t_plane;

typedef struct s_cylin{
	t_color	color;
	t_vec	ori;
	t_vec	normal_vec;
	float	d;
	float	h;
}t_cylin;

typedef struct s_img{
	int	pixel_bits;
	int	line_bytes;
	int	endian;
}t_img;

typedef enum e_type{
	AMBIENT,
	CAMERA,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER
}t_type;

typedef struct s_obj{
	t_type type;
	t_color	color;
	t_vec	ori;
	t_vec	normal_vec;
	float	d;
	float	h;

} t_obj;

typedef struct s_parser
{
	int		fd;
	int		len;
	char	*line;
	char	**sp_line;
	int		cnt_a;
	int		cnt_c;
	int		cnt_l;
} t_parser;

typedef struct s_data{
	t_obj		*obj;
	t_viewport	viewport;
	t_light		light;
	t_cam		cam;
	t_amb		amb;
	void		*mlxp;
	void		*winp;
	void		*imgp;
	unsigned int nobj;

	t_parser ps;
} t_data;

typedef enum e_bool{
	False,
	True
}t_bool;

typedef enum e_error
{
	NOT_NBR_POINT,
	NOT_NBR_MINUS,
	NOT_NBR_POINT_MINUS,
} t_error;

t_bool render(t_data *data, t_img *img, char **buffer);

t_vec vector_add(t_vec a, t_vec b);
t_vec vector_sub(t_vec a, t_vec b);
float vector_dot(t_vec a, t_vec b);
t_vec vector_cross(t_vec a, t_vec b);
float vector_size(t_vec u);
t_vec vector_norm(t_vec u);
t_vec c_vec(float c, t_vec u);

t_color	per_pixel(int x, int y);
void	my_put_to_img(char *buffer, t_img img, t_vec pnt, t_color color);

#endif