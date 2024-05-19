/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:52:14 by hdrahm            #+#    #+#             */
/*   Updated: 2024/05/19 16:52:16 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_parcing(char *temp, int f, t_stack **a)
{
	char	**allargs;
	int		test;

	check_chars(temp, f);
	allargs = ft_split(temp, ' ');
	if (f == 1)
		free(temp);
	if (allargs[1] == NULL)
		ft_free_arr(allargs, 1);
	check_len_zero(allargs);
	check_max_min(allargs);
	check_doublication(allargs);
	test = check_sort(allargs);
	if (test == 0)
	{
		ft_free_arr(allargs, 0);
		exit(0);
	}
	insert_in_a(allargs, a);
	ft_free_arr(allargs, 2);
}

void	big_sort(t_stack **a, t_stack **b)
{
	int	count;
	int	j;

	push_b(a, b);
	push_b(a, b);
	count = count_stack(a);
	j = 0;
	while (j < count)
	{
		numbers_index(a);
		numbers_index(b);
		find_target(a, b);
		j++;
	}
	j = 0;
	count = count_stack(b);
	while (j < count)
	{
		numbers_index(a);
		numbers_index(b);
		send_max(a, b);
		j++;
	}
}

char	*join_the_args(char **arv, char *temp, int arc)
{
	int		i;
	char	*argsoneline;
	char	*join;

	i = 1;
	join = NULL;
	while (i <= arc - 1)
	{
		argsoneline = ft_strjoin(temp, arv[i], join);
		free(temp);
		temp = argsoneline;
		i++;
	}
	return (temp);
}

int	main(int arc, char **arv)
{
	int		f;
	char	*temp;
	t_stack	*a;
	t_stack	*b;

	temp = NULL;
	b = NULL;
	a = NULL;
	f = 0;
	if (arc == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	else if (arc == 2)
		temp = arv[1];
	else if (arc > 2)
	{
		temp = join_the_args(arv, temp, arc);
		f = 1;
	}
	ft_parcing(temp, f, &a);
	if (small_sort(&a, &b, 0) == 0)
		big_sort(&a, &b);
	free_list(&a);
}
