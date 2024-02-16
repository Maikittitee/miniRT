/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:15:42 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/16 00:51:42 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSER_H
#define PARSER_H

typedef struct s_data		t_data;
typedef struct s_sphere		t_sphere;
typedef struct s_obj		t_obj;
typedef struct s_color		t_color;
typedef struct s_vec		t_vec;
typedef struct s_cam		t_cam;
typedef struct s_amb		t_amb;

// check file
int		ft_strcmp(char *str1, char *str2);
int	ft_checkfile(char *file, t_data *data);
int	ft_checkextension(char *file);

// assign value
// t_obj	*ft_assign_obj(t_data *data, char **sp_line);
// void	ft_assign_obj(t_data *data, char **sp_line);
void	ft_assign_obj(t_data *data, char **sp_line, int i, int *state);
int		ft_cnt_obj(char *file);
int		ft_checkobj(char *str);
t_data	*ft_main_addvalue(char *file, t_data *data);
void	ft_doublefree(char **str);

t_data		*ft_addvalue(char *file, t_data *data);
int			ft_add_camera(t_cam *cam, char **sp_line, int *mode);
void		ft_add_ambient(t_amb *amb, char **sp_line, int *mode);

t_obj	ft_sphere(char **sp_line, int *state);
t_color		ft_color(char *sp_line);
t_vec		ft_vector(char *sp_line);
t_vec		ft_vector_norm(char *sp_line);
void		ft_check_amount_2d(char **sp_tmp, int key);
void		ft_chk_rangefloat(float key, float start, float end);
void		ft_chk_rangeint(int key, int start, int end);

// cal
int				ft_atorgb(char *str);
float			ft_atof(char *str);
float			ft_power(char c, int round);
unsigned char	ft_atousc(char *str);
int				ft_cnt2d(char **str);


//print
void	ft_print2d(char **str);
void	ft_printmain(t_data *data);
void	ft_print_ambient(t_data *data);
// void	ft_printmain(t_obj *obj);
#endif