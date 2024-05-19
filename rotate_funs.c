/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_funs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:52:25 by hdrahm            #+#    #+#             */
/*   Updated: 2024/05/19 16:52:27 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack **a)
{
	t_stack	*topa;
	t_stack	*last;

	if ((*a) && (*a)->next != NULL)
	{
		topa = (*a)->next;
		last = (*a);
		(*a) = topa;
		while (topa->next != NULL)
		{
			topa = topa->next;
		}
		topa->next = last;
		last->next = NULL;
		write(1, "ra\n", 3);
	}
}

void	rotate_b(t_stack **a)
{
	t_stack	*topa;
	t_stack	*last;

	if ((*a) && (*a)->next != NULL)
	{
		topa = (*a)->next;
		last = (*a);
		(*a) = topa;
		while (topa->next != NULL)
		{
			topa = topa->next;
		}
		topa->next = last;
		last->next = NULL;
		write(1, "rb\n", 3);
	}
}

void	rrotate_a(t_stack **a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *a;
	if (temp1 && temp1->next != NULL)
	{
		while (temp1->next->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = NULL;
		temp2->next = *a;
		*a = temp2;
		write(1, "rra\n", 4);
	}
}

void	rrotate_b(t_stack **a)
{
	t_stack	*temp1;
	t_stack	*temp2;

	temp1 = *a;
	if (temp1 && temp1->next != NULL)
	{
		while (temp1->next->next != NULL)
		{
			temp1 = temp1->next;
		}
		temp2 = temp1->next;
		temp1->next = NULL;
		temp2->next = *a;
		*a = temp2;
		write(1, "rrb\n", 4);
	}
}
