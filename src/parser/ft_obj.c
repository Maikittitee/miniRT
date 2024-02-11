#include "../../include/minirt.h"

t_vec	ft_vector(char *sp_line)
{
	char	**sp_vec;
	t_vec	vec;

	sp_vec = ft_split(sp_line , ',');
	vec.i = ft_atof(sp_vec[0]);
	vec.j = ft_atof(sp_vec[1]);
	vec.k = ft_atof(sp_vec[2]);
	return(vec);
}
void	ft_checkerr_color(char	**tmp_color)
{
	int	tmp1;
	int	tmp2;
	int	tmp3;

	tmp1 = ft_atorgb(tmp_color[0]);
	// printf("tmp1 : %d\n", tmp1);
	tmp2 = ft_atorgb(tmp_color[1]);
	// printf("tmp2 : %d\n", tmp2);
	tmp3 = ft_atorgb(tmp_color[2]);
	// printf("tmp3 : %d\n", tmp3);
	if (tmp1 == -1 || tmp2 == -1 || tmp3 == -1)
	{
		printf("Error filec\n");
		free(tmp_color);
		exit(0);
	}

}
t_color	ft_color(char *sp_line)
{
	char	**sp_clr;
	t_color	clr;

	sp_clr = ft_split(sp_line, ',');
	ft_checkerr_color(sp_clr);
	clr.r = ft_atorgb(sp_clr[0]);
	clr.g = ft_atorgb(sp_clr[1]);
	clr.b = ft_atorgb(sp_clr[2]);
	clr.a = 255;
	ft_doublefree(sp_clr);
	return(clr);
}
int		ft_sphere(t_obj *sp, char **sp_line)
{
	// printf("ft_sphere\n");
	// ft_print2d(sp_line);
	sp->type = SPHERE;
	sp->ori = ft_vector(sp_line[1]);
	sp->d = ft_atoi(sp_line[2]);
	sp->color = ft_color(sp_line[3]);
	return(0);
}
int		ft_cylinder(t_obj *cy, char **sp_line)
{
	// char **sp
	(void)cy;
	// printf("ft_cylinder\n");
	// ft_print2d(sp_line);
	cy->type = CYLINDER; // sp[0]
	cy->ori = ft_vector(sp_line[1]); // sp[1]
	cy->normal_vec = ft_vector(sp_line[2]); // sp[2]
	cy->d = ft_atoi(sp_line[3]); // sp[3]
	cy->h = ft_atoi(sp_line[4]);
	cy->color = ft_color(sp_line[5]);
	return(0);
}
int	ft_plane(t_obj *pl, char **sp_line)
{
	// printf("ft_plane\n");
	// ft_print2d(sp_line);
	pl->type = PLANE;
	pl->ori = ft_vector(sp_line[1]);
	pl->normal_vec = ft_vector(sp_line[2]);
	pl->color = ft_color(sp_line[3]);
	return(0);
}
void	ft_assign_obj(int cnt_obj, t_data *data, char **sp_line)
{
	int i;

	i = 0;
	// printf("assign obj\n");
	data->obj = malloc(sizeof(t_obj) * (cnt_obj + 1));
	if(!data->obj)
		return;
	while(i < cnt_obj)
	{
		if (ft_strcmp(sp_line[0], "sp") == 0)
		{
			ft_sphere(&data->obj[i], sp_line);
		}
		else if (ft_strcmp(sp_line[0], "cy") == 0)
		{
			ft_cylinder(&data->obj[i], sp_line);
		}
		else if (ft_strcmp(sp_line[0], "pl") == 0)
		{
			ft_plane(&data->obj[i], sp_line);
		}
		i++;
	}

	// data->obj[i] = NULL;
}
