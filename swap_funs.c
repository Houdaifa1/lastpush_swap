/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_funs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:53:11 by hdrahm            #+#    #+#             */
/*   Updated: 2024/05/19 16:53:13 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **a)
{
	t_stack	*tempa;
	t_stack	*tempb;
	t_stack	*tempc;
	t_stack	*curr;

	curr = *a;
	if (curr && curr->next != NULL)
	{
		tempa = curr;
		tempb = curr->next;
		tempc = curr->next->next;
		tempa->index = 1;
		tempb->index = 0;
		tempa->next = tempc;
		tempb->next = tempa;
		*a = tempb;
		write(1, "sa\n", 3);
	}
}

void	swap_b(t_stack **a)
{
	t_stack	*tempa;
	t_stack	*tempb;
	t_stack	*tempc;
	t_stack	*curr;

	curr = *a;
	if (curr && curr->next != NULL)
	{
		tempa = curr;
		tempb = curr->next;
		tempc = curr->next->next;
		tempa->index = 1;
		tempb->index = 0;
		tempa->next = tempc;
		tempb->next = tempa;
		*a = tempb;
		write(1, "sb\n", 3);
	}
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*new_node;
	t_stack	*top_a;

	if (*a)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		top_a = (*a);
		new_node->number = top_a->number;
		new_node->index = 0;
		new_node->next = *b;
		*b = new_node;
		*a = top_a->next;
		free(top_a);
		write(1, "pa\n", 3);
	}
}

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*new_node;
	t_stack	*top_a;

	if (*a)
	{
		new_node = (t_stack *)malloc(sizeof(t_stack));
		top_a = (*a);
		new_node->number = top_a->number;
		new_node->index = 0;
		new_node->next = *b;
		*b = new_node;
		*a = top_a->next;
		free(top_a);
		write(1, "pb\n", 3);
	}
}
