#include "../../include/minirt.h"

void	ft_chk_rangefloat(float key, float start, float end)
{
	if (key < start || key > end)
	{
		printf("Error range float\n");
		exit(0);
	}
}
void	ft_chk_rangeint(int key, int start, int end)
{
	if (key < start || key > end)
	{
		printf("Error range int\n");
		exit(0);
	}
}
t_vec	ft_vector(char *sp_line)
{
	char	**sp_vec;
	t_vec	vec;
	// int		state;

	// state = 0;
	sp_vec = ft_split(sp_line , ',');
	ft_check_amount_2d(sp_vec, 3);
	vec.i = ft_atof(sp_vec[0]);
	vec.j = ft_atof(sp_vec[1]);
	vec.k = ft_atof(sp_vec[2]);
	ft_doublefree(sp_vec);
	return(vec);
}
t_vec	ft_vector_norm(char *sp_line)
{
	char	**sp_vec;
	t_vec	vec;
	// int		state;

	// state = 0;
	sp_vec = ft_split(sp_line , ',');
	ft_check_amount_2d(sp_vec, 3);
	vec.i = ft_atof(sp_vec[0]);
	// printf("vec i : %f\n", vec.i);
	ft_chk_rangefloat(vec.i, -1, 1);
	vec.j = ft_atof(sp_vec[1]);
	// printf("vec j : %f\n", vec.j);
	ft_chk_rangefloat(vec.j, -1, 1);
	vec.k = ft_atof(sp_vec[2]);
	// printf("vec k : %f\n", vec.k);
	ft_chk_rangefloat(vec.k, -1, 1);
	ft_doublefree(sp_vec);
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
		printf("Error file\n");
		free(tmp_color);
		exit(0);
	}

}
void	ft_check_amount_2d(char **sp_tmp, int key)
{
	if (ft_cnt2d(sp_tmp) != key)
	{
		printf("Error file\n");
		exit(0);
	}
}

t_color	ft_color(char *sp_line)
{
	char	**sp_clr;
	t_color	clr;

	sp_clr = ft_split(sp_line, ',');
	ft_check_amount_2d(sp_clr, 3);
	// if (ft_cnt2d(sp_clr) != 3)
	// {
	// 	printf("Error clr\n");
	// 	exit(0);
	// }
	ft_checkerr_color(sp_clr);
	clr.r = ft_atorgb(sp_clr[0]);
	clr.g = ft_atorgb(sp_clr[1]);
	clr.b = ft_atorgb(sp_clr[2]);
	clr.a = 255;
	ft_doublefree(sp_clr);
	return(clr);
}
t_obj	ft_sphere(char **sp_line, int *state)
{
	// printf("ft_sphere\n");
	// ft_print2d(sp_line);
	t_obj sp;

	sp.type = SPHERE;
	sp.ori = ft_vector(sp_line[1]);
	sp.d = ft_atoi(sp_line[2]);
	if (sp.d < 0)
	{
		*state = 1;
		printf("Error file\n");
		exit(0);
	}
	sp.color = ft_color(sp_line[3]);
	return(sp);
}
t_obj	ft_cylinder(char **sp_line, int *state)
{
	// printf("ft_cylinder\n");
	// ft_print2d(sp_line);
	t_obj cy;

	cy.type = CYLINDER;
	cy.ori = ft_vector(sp_line[1]);
	cy.normal_vec = ft_vector_norm(sp_line[2]);
	cy.d = ft_atof(sp_line[3]);
	cy.h = ft_atof(sp_line[4]);
	if (cy.d < 0 || cy.h < 0)
	{
		printf("Error file\n");
		*state = 1;
		// exit(0);
	}
	cy.color = ft_color(sp_line[5]);
	return(cy);
}
t_obj	ft_plane(char **sp_line, int *state)
{
	// printf("ft_plane\n");
	// ft_print2d(sp_line);
	t_obj pl;

	*state = 1;
	pl.type = PLANE;
	pl.ori = ft_vector(sp_line[1]);
	pl.normal_vec = ft_vector_norm(sp_line[2]);
	pl.color = ft_color(sp_line[3]);
	return(pl);
}
void	ft_assign_obj(t_data *data, char **sp_line, int i, int *state)
{
	if (ft_strcmp(sp_line[0], "sp") == 0)
		data->obj[i] = ft_sphere(sp_line, state);
	else if (ft_strcmp(sp_line[0], "cy") == 0)
		data->obj[i] = ft_cylinder(sp_line, state);
	else if (ft_strcmp(sp_line[0], "pl") == 0)
		data->obj[i] = ft_plane(sp_line, state);
}
