/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktunchar <ktunchar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 21:41:43 by ktunchar          #+#    #+#             */
/*   Updated: 2023/08/16 23:21:28 by ktunchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

float	dot_product(t_vec u, t_vec v)
{
	return ((u.i * v.i) + (u.j * v.j) + (u.k * v.k)); 
}

t_vec cross_product(t_vec u, t_vec v)
{
	t_vec	n;

	n.i = (u.j * v.k) - (u.k * v.j);
	n.j = (u.i * v.k) - (u.k * v.i);
	n.k = (u.i * v.j) - (u.j * v.i);
	return (n);
}

t_vec sub(t_vec u, t_vec v)
{
	t_vec	n;

	n.i = v.i - u.i;
	n.j = v.j - u.j;
	n.k = v.k - u.k;
	return (n);
}

t_vec cmultiply(t_vec u, float c)
{
	t_vec	n;

	n.i = u.i * c;
	n.j = u.j * c;
	n.k = u.k * c;
	return (n);
}

float vec_size(t_vec u)
{	
	return (sqrt(u.i * u.i + u.j * u.j + u.k * u.k));
}

t_vec normalize(t_vec u)
{
	return (cmultiply(u, 1 / vec_size(u)));
}