/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 15:21:00 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/21 16:23:05 by nkietwee         ###   ########.fr       */
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
	// printf("1111\n");
	ft_check_obj(file, data, &state);
	// printf("222\n");
	if (state == -1)
		return (-1);
	// printf("333\n");
	if (ft_check_acl(data->ps) == -1)
		return (-1);
	// printf("444\n");
	ft_checkformat(data, file, &state);
	// printf("555\n");
	// printf("---state : %d----\n", state);
	if (state == -1)
		return (-1);
	// printf("before malloc\n");
	printf("nobj : %d\n", data->nobj);
	data->obj = malloc(sizeof(t_obj) * data->nobj);
	if (!data->obj)
		return (0);
	// printf("before asafter assignsign\n");
	if (ft_assign(file, &state, data) == -1)
	{
		// printf("entry assign\n");
		free(data->obj);
		return (-1);
	}

	printf("after assign\n");
	// printf("Vec[i] : %f\n", data->obj[0].ori.i);
	if (state == -1)
	{
		free(data->obj);
		return (-1);
	}
	// printf("after after assign\n");
	// free(data->obj);
	return (0);
}
