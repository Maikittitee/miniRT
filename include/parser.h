/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 16:55:50 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/17 17:00:56 by nkietwee         ###   ########.fr       */
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

//ft_print.c
void	ft_print(void);
void	ft_print2d(char **str);

// ft_free.c
void	ft_doublefree(char **str);
#endif