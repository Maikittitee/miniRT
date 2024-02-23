/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:50 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/23 21:47:22 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

typedef struct s_data		t_data;
typedef struct s_vec		t_vec;
typedef struct s_amb		t_amb;
typedef struct s_cam		t_cam;
typedef struct s_light		t_light;
typedef struct s_obj		t_obj;
typedef struct s_parser		t_parser;
typedef struct s_color		t_color;

//ft_checkfile.c
int				ft_checkfile(t_data *data, char *file);
int				ft_strcmp(char *s1, char *s2);
int				ft_check_acl(t_parser ps);

// ft_cnt.c
int				ft_check_obj(char *file, t_data *data, int *state);
int				ft_check_cntobj(t_data *data);
int				ft_cnt2d(char **str);
int				ft_checkobj(char *str);

//ft_print.c
void			ft_print(void);
void			ft_print2d(char **str);
void			ft_prt_obj(t_data *data);

// ft_free.c
void			ft_doublefree(char **str);

// ft_checkformat.c
int				ft_checkformat(t_data *data, char *file, int *state);
int				ft_check_amout_sp(char **sp, int nbr);

// ft_format_obj.c
int				ft_fmt_a(t_data *data);
int				ft_fmt_c(t_data *data);
int				ft_fmt_l(t_data *data);
int				ft_fmt_cy(t_data *data);
int				ft_fmt_sp(t_data *data);
int				ft_fmt_pl(t_data *data);
int				ft_checkratio(char *str);

// ft_checkfmt_util.c
int				ft_not(char *str, int mode);
int				ft_not2(char *str, int mode);
int				ft_count_char(char *str, char c);
int				ft_notnbr(char *str);
int				ft_check_clr(char *str);
int				ft_check_vec(char *str);
int				ft_check_float(char *str);

// ft_assign_obj.c
int				ft_assign(char *file, int *state, t_data *data);
t_obj			ft_assign_cy(char **sp_line, int *state);
t_obj			ft_assign_pl(char **sp_line, int *state);
t_obj			ft_assign_sph(char **sp_line, int *state);

// ft_assign_obj_util.c
int				ft_assign_obj(t_data *data, int *i, int *state);
t_amb			ft_assign_amb(char **sp_line, int *state);
t_cam			ft_assign_cam(char **sp_line, int *state);
t_light			ft_assign_light(char **sp_line, int *state);

//ft_atof.c
float			ft_atof(char *str);

// ft_assign_util.c
t_color			ft_assign_clr(char *sp_line, int *state);
t_vec			ft_vector_coor(char *str, int *state);
t_vec			ft_vector_norm(char *str, int *state);

// ft_atorgb.c
unsigned char	ft_atorgb(char *str, int *state);
#endif