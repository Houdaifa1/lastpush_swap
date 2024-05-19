/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdrahm <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:53:30 by hdrahm            #+#    #+#             */
/*   Updated: 2024/05/19 16:53:32 by hdrahm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}					t_stack;

typedef struct s_infos
{
	int				index;
	int				check_a;
	int				check_b;
	int				count_a;
	int				count_b;
	int				cost;
	int				target_num_index;

}					t_infos;

char				*ft_strjoin(char const *s1, char const *s2, char *join);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
size_t				ft_strlen(const char *s);
char				**ft_split(char const *s, char c);
void				ft_free_arr(char **arr, int e);
long				ft_atoi(char *str, char **arr);
void				swap_a(t_stack **a);
void				swap_b(t_stack **a);
void				push_a(t_stack **a, t_stack **b);
void				push_b(t_stack **a, t_stack **b);
void				rotate_a(t_stack **a);
void				rotate_b(t_stack **a);
void				rrotate_a(t_stack **a);
void				rrotate_b(t_stack **a);
void				free_list(t_stack **list);
void				numbers_index(t_stack **a);
void				send_max(t_stack **a, t_stack **b);
int					count_stack(t_stack **a);
int					get_big_num(t_stack **a, int i);
int					small_sort(t_stack **a, t_stack **b, int check);
void				find_target(t_stack **a, t_stack **b);
void				rotate_the_stack(int index, int count, t_stack **a, char c);
void				check_chars(char *str, int f);
void				check_len_zero(char **arr);
void				check_max_min(char **arr);
void				check_doublication(char **arr);
int					check_sort(char **arr);
void				insert_in_a(char **arr, t_stack **a);
void				rrotate_two(t_stack **a);

#endif
