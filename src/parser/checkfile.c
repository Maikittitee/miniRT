/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:12:57 by nkietwee          #+#    #+#             */
/*   Updated: 2024/01/24 15:48:56 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int		ft_strcmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while(str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}
char	*ft_strchr(const char *s, int c)
{
	char	alpha;

	alpha = (char)c;
	while (*s)
	{
		if (*s == alpha)
			return ((char *)(s));
		s++;
	}
	if (!c)
		return ((char *)s);
	return (0);
}
int		ft_checkextension(char *str)
{
	char	*find;
	int		cmp;

	find = ft_strchr(str, '.');
	cmp = ft_strcmp(find, ".rt");
	// printf("cmp : %d\n", cmp);
	if (cmp != 0)
		return(-1);
	return (0);
}
int	ft_checkfile(char *file, t_data *data)
{
	if (ft_checkextension(file) == -1)
		return(-1);
	ft_addvalue(file, data);
	return (0);
}

// int	main(int ac, char **av)
// {
// 	if (ac != 2)
// 		return (printf("input : ./miniRT file.rt\n"));
// 	if (ft_checkfile(av[1]) == -1)
// 	{
// 		printf("file errror\n");
// 		return (0);
// 	}
// }