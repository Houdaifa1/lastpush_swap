/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:51:54 by hdrahm            #+#    #+#             */
/*   Updated: 2024/05/19 16:51:56 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(char **arr)
{
	int	i;
	int	count;
	int	check;
	int	j;
	int	t;

	i = 0;
	t = 1;
	count = 0;
	check = 0;
	while (arr[count])
		count++;
	while (arr[i] != NULL)
	{
		j = t;
		while (j < count)
		{
			if (ft_atoi(arr[i], arr) > ft_atoi(arr[j], arr))
				check = 1;
			j++;
		}
		i++;
		t++;
	}
	return (check);
}

void	insert_in_a(char **arr, t_stack **a)
{
	t_stack	*curr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	curr = malloc(sizeof(t_stack));
	(*a) = curr;
	while (arr[count] != NULL)
		count++;
	while (i < count)
	{
		curr->number = ft_atoi(arr[i], arr);
		if (i != count - 1)
			curr->next = malloc(sizeof(t_stack));
		curr = curr->next;
		i++;
	}
	curr = NULL;
}

void	numbers_index(t_stack **a)
{
	int		i;
	t_stack	*curr;

	i = 1;
	curr = *a;
	while (curr != NULL)
	{
		curr->index = i;
		curr = curr->next;
		i++;
	}
}

void	ft_free_arr(char **arr, int e)
{
	int	n;

	n = 0;
	while (arr[n])
	{
		free(arr[n]);
		n++;
	}
	free(arr);
	if (e == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	free_list(t_stack **list)
{
	t_stack	*temp;

	while (*list != NULL)
	{
		temp = (*list)->next;
		free(*list);
		*list = temp;
	}
}
