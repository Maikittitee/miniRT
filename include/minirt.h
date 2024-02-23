/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 03:41:23 by ktunchar          #+#    #+#             */
/*   Updated: 2024/02/23 23:26:43 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define WIN_WIDTH 900
# define WIN_HEIGHT 600
# define ESC_KEY 53
# define PI 3.14159265358979
# define VERYSMALLNUMBER 0.001f 
# include "../lib/libft_gnl/libft.h"
# include "../lib/mlx/mlx.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

typedef enum e_bool{
	False,
	True
}t_bool;

typedef struct s_color{
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;
} t_color;

typedef struct s_vec{
	float	x;
	float	y;
	float	z;
} t_vec;

typedef struct s_amb{
	t_color	color;
	float	ratio;
} t_amb;

typedef struct s_axis{
	t_vec	x;
	t_vec	y;
	t_vec	z;
} t_axis;

typedef struct s_cam{
	t_vec	origin;
	// t_vec	normal_vec;
	t_vec	direction;
	int 	fov;
	
} t_cam;

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

typedef struct t_ray{
	t_vec	ori;
	t_vec	dir;
} t_ray;


 // --------------------------
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
	SPHERE,
	PLANE,
	CYLIN
}t_type;

typedef struct s_obj{
	t_type type;
	t_color	color;
	t_vec	ori;
	t_vec	normal_vec;
	float	d;
	float	h;
	
} t_obj;

typedef struct s_hit{
	t_bool is_hit;
	t_vec hitpoint;
	int index;
	float t;
	
}t_hit;

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
} t_data;


t_bool render(t_data *data, t_img *img, char **buffer);

t_vec vector_add(t_vec a, t_vec b);
t_vec vector_sub(t_vec a, t_vec b);
float vector_dot(t_vec a, t_vec b);
t_vec vector_cross(t_vec a, t_vec b);
float vector_size(t_vec u);
t_vec vector_norm(t_vec u);
t_vec vector_scaler(float c, t_vec u);
t_vec vector_div(t_vec u, t_vec v);
t_color	color_scaler(float c, t_color color);
t_color	color_add(t_color c1, t_color c2);
t_color color_mult(t_color a, t_color b);


t_bool	init_viewport(t_viewport *viewport, t_cam *cam);


t_color	per_pixel(t_ray ray, t_obj *obj, t_data data);
void	my_put_to_img(char *buffer, t_img img, t_vec pnt, t_color color);
t_color calculate_color(t_hit hit, t_ray ray, t_data data);

void	print_vec(t_vec u);

t_bool is_hit_object(t_ray ray, unsigned int except, t_obj *obj, t_data data);
t_hit	hit_object(t_ray ray, t_obj *obj, t_data data);
float	hit_sphere(t_ray ray, t_obj sphere);
float hit_plane(t_ray ray, t_obj plane);
float	hit_cylinder(t_ray ray, t_obj cylin);
float	hit_disk(t_ray ray, t_obj cylin);

float activte_dot(float dot, int type);
t_vec calculate_normal_vector(t_obj obj, t_vec hitpoint);
float get_dot_product(t_obj obj, t_light light, t_hit hit, t_data data);
t_color apply_ambient(t_color color, t_amb amb);


int	close_win(t_data data);
int	ft_exit(int keycode, t_data data);
#endif
