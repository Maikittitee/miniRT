/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:50 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/17 21:38:19 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSER_H
# define PARSER_H

typedef struct s_data		t_data;

//ft_checkfile.c
int	ft_checkfile(t_data *data, char *file);
int	ft_strcmp(char *s1, char *s2);

// ft_cnt.c
int	ft_check_obj(char *file, t_data *data, int *state);
int	ft_check_cntobj(t_data *data);
int	ft_cnt2d(char **str);

//ft_print.c
void	ft_print(void);
void	ft_print2d(char **str);

// ft_free.c
void	ft_doublefree(char **str);

// ft_checkformat.c
int	ft_checkformat(t_data *data , char *file, int *state);
int	ft_check_amout_sp(char **sp, int nbr);

// ft_format_obj.c
int	ft_fmt_a(t_data *data);
int	ft_checkratio(char *str);
// int	ft_checkratio(char *str);

// ft_checkfmt_util.c
int	ft_check_notnbr_point(char *str);
int	ft_count_char(char *str, char c);
// int	ft_check_amount_sp(char **sp, int nbr);
int	ft_check_clr(char *str);
#endif