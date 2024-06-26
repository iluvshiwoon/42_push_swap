/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 15:14:50 by kgriset           #+#    #+#             */
/*   Updated: 2024/04/05 09:19:59 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	r_rotate(t_circular_db_ll *cdl_list, char list_name, t_circular_db_ll *ops)
{
	t_double_link_node	*node;

	if (!(cdl_list && cdl_list->first_node))
		return (ERROR);
	if (list_name)
	{
		node = malloc(sizeof(*node));
		if (node && ops->pf_insert_end(ops, node))
			node->data = malloc(sizeof(char) * 4);
		if (!node->data)
			return (ERROR);
		((char *)node->data)[0] = 'r';
		((char *)node->data)[1] = 'r';
		((char *)node->data)[2] = list_name;
		((char *)node->data)[3] = '\0';
	}
	cdl_list->first_node = cdl_list->last_node;
	cdl_list->last_node = cdl_list->last_node->previous;
	return (SUCCESS);
}

int	r_rr(t_circular_db_ll *cdll_a, t_circular_db_ll *cdll_b,
		t_circular_db_ll *ops)
{
	t_double_link_node	*node;

	r_rotate(cdll_a, 0, ops);
	r_rotate(cdll_b, 0, ops);
	node = malloc(sizeof(*node));
	if (node && ops->pf_insert_end(ops, node))
	{
		node->data = malloc(sizeof(char) * 4);
		if (!node->data)
			return (ERROR);
		node->data = (char *){"rrr"};
	}
	else
		return (ERROR);
	return (SUCCESS);
}

void	r_rotate_n(t_circular_db_ll *cdl_list, char list_name, size_t n,
		t_circular_db_ll *ops)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		r_rotate(cdl_list, list_name, ops);
		++i;
	}
}

void	rotate_n(t_circular_db_ll *cdl_list, char list_name, size_t n,
		t_circular_db_ll *ops)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		rotate(cdl_list, list_name, ops);
		++i;
	}
}

void	push_n(t_vars *vars, char list_name, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (list_name)
			push(vars->cdl_list_b, vars->cdl_list_a, list_name, vars->ops);
		else
			push(vars->rank_b, vars->rank_a, list_name, vars->ops);
		++i;
	}
}
