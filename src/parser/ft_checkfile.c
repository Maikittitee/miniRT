/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:21:00 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/17 21:28:22 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] && s2[i]) && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_check_extension(char *file)
{
	char	*str;

	if (!file)
		return (0);
	str = ft_strchr(file, '.');
	if (ft_strcmp(str, ".rt") == 0)
		return (0);
	return (-1);
}

int	ft_check_acl(t_parser ps)
{
	if (ps.cnt_a == 1 && ps.cnt_c == 1 && ps.cnt_l == 1)
		return (0);
	else
		return (-1);
}

int	ft_checkfile(t_data *data, char *file)
{
	int	state;

	state = 0;
	if (ft_check_extension(file) == -1)
		return (-1);
	ft_check_obj(file, data, &state);
	if (state == -1)
		return (-1);
	if (ft_check_acl(data->ps) == -1)
		return (-1);
	// printf("cnt_a : %d\n", data->ps.cnt_a);
	// printf("cnt_c : %d\n", data->ps.cnt_c);
	// printf("cnt_l : %d\n", data->ps.cnt_l);
	// printf("nobj %u\n", data->nobj) ;
	// printf("check format : %d\n", ft_checkformat(data, file, &state));
	ft_checkformat(data, file, &state);
	if (state == -1)
		return (-1);

	// data->obj = malloc(sizeof(t_obj) * data->nobj);
	// if (!data->obj)
	// 	return(0);
	return(0);
}
