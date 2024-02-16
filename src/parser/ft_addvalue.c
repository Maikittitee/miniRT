/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addvalue.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:30:04 by nkietwee          #+#    #+#             */
/*   Updated: 2024/02/16 16:16:41 by nkietwee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

void	ft_doublefree(char **str)
{
	int	i;

	i = 0;
	if(!str)
		return;
	while(str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	ft_add_ambient(t_amb *amb, char **sp_line, int *state)
{
	// printf(GRN"Hello ambient\n"RESET);
	*state = 0;
	ft_check_amount_2d(sp_line, 3);
	amb->ratio = ft_atof(sp_line[1]); // protect ratio [0.0 1.0]
	if (*state == 1)
	{
		printf("exit\n");
		exit(0);
	}
	// printf("state : %d\n", state);
	ft_chk_rangefloat(amb->ratio, 0.0, 1.0);
	amb->color = ft_color(sp_line[2]);
	// printf("Error\n");
}

int	ft_add_camera(t_cam *cam, char **sp_line, int *state)
{
	*state = 1;
	ft_check_amount_2d(sp_line, 4);
	cam->ori = ft_vector(sp_line[1]);
	cam->normal_vec = ft_vector_norm(sp_line[2]);
	cam->fov = ft_atoi(sp_line[3]);
	ft_chk_rangeint(cam->fov, 0, 180);
	// printf("End camera\n");
	return(0);
}
void	ft_add_light(t_light *light, char **sp_line, int *state)
{
	*state = 1;
	ft_check_amount_2d(sp_line, 4);
	light->ori = ft_vector(sp_line[1]);
	light->ratio = ft_atof(sp_line[2]);
	ft_chk_rangefloat(light->ratio, 0.0, 1.0);

}

t_data	*ft_addvalue(char *file, t_data *data)
{
	char 	*line;
	char	**sp_line;
	int		fd;
	int		state;
	int		i;

	state = 0;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return(0);
	data->nobj = ft_cnt_obj(file);
	data->obj = malloc(sizeof(t_obj) * data->nobj);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (0);
		if(line[0] != '\n')
		{
			sp_line = ft_split(line, ' ');
			if (ft_strcmp(sp_line[0], "A") == 0)
				ft_add_ambient(&data->amb, sp_line, &state);
			if (ft_strcmp(sp_line[0], "C") == 0)
				ft_add_camera(&data->cam, sp_line, &state);
			if (ft_strcmp(sp_line[0], "L") == 0)
				ft_add_light(&data->light, sp_line, &state);
			if(ft_checkobj(sp_line[0]) == FOUND)
			{
				ft_assign_obj(data, sp_line, i, &state);
				i++;
			}
			ft_doublefree(sp_line);
		}
		free(line);
	}
}


