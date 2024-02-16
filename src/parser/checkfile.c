/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:12:57 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/16 16:11:34 by nkietwee         ###   ########.fr       */
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

int		ft_checkextension(char *str)
{
	char	*find;
	int		cmp;

	find = ft_strchr(str, '.'); // strchr or strrchr
	cmp = ft_strcmp(find, ".rt");
	// printf("cmp : %d\n", cmp);
	if (cmp != 0)
		return(-1);
	return (0);
}
int	ft_check_closefd(int fd, int cnt_a, int cnt_c, int cnt_l)
{
	close(fd);
	if (cnt_a == 1 && cnt_c == 1 && cnt_l == 1)
		return(0);
	return(1);
}
int ft_check_acl(char *file, int *state)
{
	int		fd;
	char	*line;
	char	**sp_line;
	int		cnt_a;
	int		cnt_c;
	int		cnt_l;

	cnt_a = 0;
	cnt_c = 0;
	cnt_l = 0;
	fd = open(file , O_RDONLY);
	*state = 1;
	if (fd == -1)
		return(0);
	while(1)
	{
		line = get_next_line(fd);
		if(!line)
		{
			// *state = ft_check_closefd(fd, cnt_a, cnt_c, cnt_l);
			close(fd);
			if (cnt_a == 1 && cnt_c == 1 && cnt_l == 1)
				return(0);
			return(-1);
		}
		if (line[0] != '\n')
		{
			sp_line = ft_split(line, ' ');
			// ft_cnt_acl(sp_line[0], &mode);
			if (ft_strcmp(sp_line[0], "A") == 0)
				cnt_a = cnt_a + 1;
			else if (ft_strcmp(sp_line[0], "C") == 0)
				cnt_c = cnt_c + 1;
			else if (ft_strcmp(sp_line[0], "L") == 0)
				cnt_l = cnt_l + 1;
			else if (ft_checkobj(sp_line[0]) == FOUND)
				continue;
			else
				return(-1);
			ft_doublefree(sp_line);
		}
		free(line);
	}
	return(0);
}
int	ft_checkfile(char *file, t_data *data)
{
	int state;

	state = 0;
	if (ft_checkextension(file) == -1)
		return(-1);
	if (ft_check_acl(file, &state) == -1)
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