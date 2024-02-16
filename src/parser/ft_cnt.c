/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:54 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/16 13:25:36 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

int ft_checkobj(char *str)
{
	if (ft_strcmp(str, "cy") == 0 || ft_strcmp(str, "sp") == 0
	|| ft_strcmp(str, "pl") == 0)
		return(FOUND);
	return(NOT_FOUND);

}

int ft_cnt_obj(char *file)
{
	int		fd;
	char	*line;
	char	**sp_line;
	int		cnt;

	fd = open(file , O_RDONLY);
	if (fd == -1)
		return(0);
	cnt = 0;
	while(1)
	{
		line = get_next_line(fd);
		if(!line) // fixed cnt = 0 (It mean malloc don't have obj)
		{
			close(fd);
			return(cnt);
		}
		if (line[0] != '\n')
		{
			sp_line = ft_split(line, ' ');
			if (ft_strcmp(sp_line[0], "cy") == 0 || ft_strcmp(sp_line[0], "sp") == 0 || ft_strcmp(sp_line[0], "pl") == 0)
				cnt = cnt + 1;
			else if ((ft_strcmp(sp_line[0], "A") == 0) || (ft_strcmp(sp_line[0], "C") == 0)
			|| (ft_strcmp(sp_line[0], "L") == 0 ))
				continue ;
			else
				printf("Error file_cnt_obj\n");
			ft_doublefree(sp_line);
		}
		free(line);
	}
	return(0);
}

