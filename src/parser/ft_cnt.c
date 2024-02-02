/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cnt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkietwee <nkietwee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:58:54 by nkietwee          #+#    #+#             */
/*   Updated: 2024/01/31 00:49:07 by nkietwee         ###   ########.fr       */
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

