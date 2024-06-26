/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:10:32 by kgriset           #+#    #+#             */
/*   Updated: 2024/04/01 15:16:20 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rank(t_circular_db_ll *cdll, t_circular_db_ll *rank)
{
	int					*array;
	t_double_link_node	*node;
	t_double_link_node	*rank_node;
	size_t				i[2];

	array = cdl2array(cdll);
	array = bottom_up_merge_sort(array, cdll->total);
	i[0] = 0;
	i[1] = 0;
	node = cdll->first_node;
	rank_node = 0;
	while (node != cdll->first_node || i[1] == 0)
	{
		while (*((int *)node->data) != array[i[0]])
			++i[0];
		if (!add_int2node(rank, rank_node, i[0]))
			return (cdl_free_list(cdll), cdl_free_list(rank), free(array),
				ERROR);
		node = node->next;
		i[0] = 0;
		i[1] = 1;
	}
	return (free(array), SUCCESS);
}

static void	rotate_both(t_vars *vars)
{
	rotate(vars->cdl_list_a, 'a', vars->ops);
	rotate(vars->rank_a, 0, vars->ops);
}

static void	push_both(t_vars *vars)
{
	push(vars->cdl_list_b, vars->cdl_list_a, 'b', vars->ops);
	push(vars->rank_b, vars->rank_a, 0, vars->ops);
}

int	deal(t_vars *vars)
{
	size_t	i;
	size_t	j;
	size_t	n;
	int		*array;

	i = 0;
	j = 0;
	n = vars->cdl_list_a->total;
	array = cdl2array(vars->cdl_list_a);
	while (i < n)
	{
		if (array[i] == vars->array[j])
		{
			rotate_both(vars);
			++j;
		}
		else
			push_both(vars);
		++i;
	}
	return (free(array), SUCCESS);
}
