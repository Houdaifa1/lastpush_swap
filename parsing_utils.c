/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:52:03 by hdrahm            #+#    #+#             */
/*   Updated: 2024/05/19 16:52:05 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_chars(char *str, int f)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' ' || str[i] == '-'
				|| str[i] == '+'))
		{
			write(2, "Error\n", 6);
			if (f == 1)
				free(str);
			exit(1);
		}
		i++;
	}
}

int	check_numbers(char *str)
{
	int	i;
	int	check;

	i = 0;
	check = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			check = 1;
		i++;
	}
	if (check == 0)
		return (1);
	return (0);
}

void	check_len_zero(char **arr)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		len = 0;
		if (check_numbers(arr[i]) == 1)
			ft_free_arr(arr, 1);
		if (arr[i][0] == '-' || arr[i][0] == '+')
			j++;
		while (arr[i][j] && arr[i][j] == '0')
			j++;
		while (arr[i][j])
		{
			j++;
			len++;
			if (len > 11)
				ft_free_arr(arr, 1);
		}
		i++;
	}
}

void	check_max_min(char **arr)
{
	int		i;
	long	num;

	i = 0;
	while (arr[i])
	{
		num = ft_atoi(arr[i], arr);
		if (num > INT_MAX || num < INT_MIN)
			ft_free_arr(arr, 1);
		i++;
	}
}

void	check_doublication(char **arr)
{
	int	curr;
	int	i;
	int	count;

	count = 0;
	while (arr[count] != NULL)
		count++;
	curr = 0;
	while (curr < count)
	{
		i = 0;
		while (arr[i] != NULL)
		{
			if (i == curr)
				i++;
			else if (i != curr)
			{
				if (ft_atoi(arr[curr], arr) == ft_atoi(arr[i], arr))
					ft_free_arr(arr, 1);
				i++;
			}
		}
		curr++;
	}
}
