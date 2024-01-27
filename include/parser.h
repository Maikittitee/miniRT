/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:15:42 by nkietwee          #+#    #+#             */
/*   Updated: 2024/01/26 13:01:10 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PARSER_H
#define PARSER_H

typedef struct s_data		t_data;
// check file
int		ft_strcmp(char *str1, char *str2);
int	ft_checkfile(char *file, t_data *data);
int	ft_checkextension(char *file);

// assign value
t_data	*ft_addvalue(char *file, t_data *data);
int		ft_add_camera(t_data *data, char **sp_line, int *mode);


// cal
float	ft_atof(char *str);
float	ft_power(float nbr, int pow);
unsigned char	ft_atousc(char *str);
int	ft_cnt2d(char **str);


//print
void	ft_print2d(char **str);
void	ft_printmain(t_data *data);
void	ft_print_ambient(t_data *data);
#endif