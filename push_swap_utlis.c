/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgriset <kgriset@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 09:52:43 by kgriset           #+#    #+#             */
/*   Updated: 2024/02/14 09:54:47 by kgriset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_array(int * array, size_t size)
{
    size_t i;
    
    i = 0;
    ft_printf("\n");
    while (i < size)
    {
        ft_printf("%d\n", array[i]);
        ++i;
    }
}

void print_cdl(t_circular_double_link_list * cdl_list)
{
    t_double_link_node * cdl_node;

    if (cdl_list && cdl_list->first_node)
    {
        ft_printf("\n");
        cdl_node = cdl_list->first_node;
        do {
            ft_printf("%d\n", *((int *)cdl_node->data));
            cdl_node = cdl_node->next;
        } while (cdl_node != cdl_list->first_node);
    }
    if (cdl_list)
        ft_printf("total: %u\n", cdl_list->total);
}

void print_cdl_str(t_circular_double_link_list * cdl_list)
{
    t_double_link_node * cdl_node;

    if (cdl_list && cdl_list->first_node)
    {
        cdl_node = cdl_list->first_node;
        do {
            ft_printf("%s\n", ((char *)cdl_node->data));
            cdl_node = cdl_node->next;
        } while (cdl_node->next != cdl_list->first_node);
        ft_printf("%s", ((char *)cdl_node->data));
    }
}
