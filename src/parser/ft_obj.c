#include "../../include/minirt.h"

void    ft_assign_obj(int cnt_obj, t_data *data, char **sp_line)
{
    int i;

    i = 0;
    (void)cnt_obj;
    (void)data;
    
    // printf("assign obj\n");
    data->obj = malloc(sizeof(t_obj) * (cnt_obj + 1));
    if(!data->obj)
        return;
    while(i < cnt_obj)
    {
        if (ft_strcmp(sp_line[0], "sp") == 0)
        {        
            // printf("sp[0] : %s\n", sp_line[0]);
            // printf("dd sphere");
            // ft_print2d(sp_line);
            data->obj[i].obj = ft_add_sphere(data, sp_line);
            data->obj[i].type = SPHERE;
        }
        // else if (ft_strcmp(sp_line[0], "cy"))
        // {        
        //     data->obj[i].obj = ft_add_camera(data, sp_line);
        //     data->obj[i].type = CYLINDER;
        // }
        // else if (ft_strcmp(sp_line[0], "pl"))
        // {        
        //     data->obj->obj[i] = ft_add_(data, sp_line);
        //     data->obj->type = PLANE;
        // }
            
        i++;
    }
}
