/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:52:50 by hdrahm            #+#    #+#             */
/*   Updated: 2024/05/19 16:52:52 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_big_num(t_stack **a, int i)
{
	t_stack	*temp;
	int		big_num;
	int		num_index;

	temp = *a;
	big_num = temp->number;
	num_index = 1;
	while (temp->next != NULL)
	{
		temp = temp->next;
		if (temp->number > big_num)
		{
			big_num = temp->number;
			num_index = temp->index;
		}
	}
	if (i == 1)
		return (num_index);
	else
		return (big_num);
}

int	count_stack(t_stack **a)
{
	int		count;
	t_stack	*temp;

	count = 0;
	temp = *a;
	if (temp)
	{
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
	}
	return (count);
}

void	send_max(t_stack **a, t_stack **b)
{
	int	index;
	int	count;

	index = get_big_num(b, 1);
	count = count_stack(b);
	if (index <= count / 2)
	{
		while (index > 1)
		{
			rotate_b(b);
			index--;
		}
		push_a(b, a);
	}
	else
	{
		while (index <= count)
		{
			rrotate_b(b);
			index++;
		}
		push_a(b, a);
	}
}

void	rotate_the_stack(int index, int count, t_stack **a, char c)
{
	if (index <= (count / 2) + 1)
	{
		while (index > 1)
		{
			if (c == 'a')
				rotate_a(a);
			if (c == 'b')
				rotate_b(a);
			index--;
		}
	}
	else
	{
		while (index <= count)
		{
			if (c == 'a')
				rrotate_a(a);
			if (c == 'b')
				rrotate_b(a);
			index++;
		}
	}
}

void	rrotate_two(t_stack **a)
{
	rrotate_a(a);
	rrotate_a(a);
}
