/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adorofei <adorofei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 13:25:46 by adorofei          #+#    #+#             */
/*   Updated: 2026/10/09 17:40:51 by adorofei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>
# include <limits.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef enum s_sort_mode
{
	MODE_ADAPTIVE,
	MODE_SIMPLE,
	MODE_MEDIUM,
	MODE_COMPLEX
}	t_sort_mode;

typedef struct s_bench
{
	int	sa;
	int	sb;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	pa;
	int	pb;
	int	total_ops;
}	t_bench;

typedef struct s_grid
{
	t_node		*stack_a;
	t_node		*stack_b;
	int			size_a;
	int			size_b;
	float		disorder;
	t_sort_mode	mode;
	int			bench_mode;
	t_bench		ops_count;
}	t_grid;

/* OPERATIONS */
void	sa(t_grid *push_swap);
void	sb(t_grid *push_swap);
void	ss(t_grid *push_swap);
void	ra(t_grid *push_swap);
void	rb(t_grid *push_swap);
void	rr(t_grid *push_swap);
void	rra(t_grid *push_swap);
void	rrb(t_grid *push_swap);
void	rrr(t_grid *push_swap);
void	pa(t_grid *push_swap);
void	pb(t_grid *push_swap);

/* PARSING FLAGS */
int		is_flag(char *str);
void	indicate_flag(t_grid *push_swap, char *argv);

/* PARSING ARGV */
int		process_values(t_grid *push_swap, char *val_str);
void	parse_args(t_grid *push_swap, int argc, char **argv);

/* COUNTING DISORDER OF THE STACK */
float	count_disorder(t_node *stack, int size);

/* BENCH MODE */
void	bench_print(t_grid *push_swap);

/* SORTING */
int		is_sorted(t_node *stack);
int		find_max(t_node *stack);
int		find_max_pos(t_node *stack);
int		find_min_pos(t_node *stack);
void	sort_three(t_grid *push_swap);
void	sort_four(t_grid *push_swap, int stack_size);
void	sort_five(t_grid *push_swap, int stack_size);
void	push_min_to_b(t_grid *push_swap, int stack_size);
void	tiny_sorting(t_grid *push_swap);
void	assign_index(t_node *stack);
void	bubble_sort_array(int *arr, int len);
int		get_median(t_node *stack, int len);

/* ALGORITHMS */
void	sort_simple(t_grid *push_swap, int stack_size);
void	sort_medium(t_grid *push_swap);
void	sort_adaptive(t_grid *push_swap);
void	quicksort_a(t_grid *push_swap, int len, int count_rotations);

/* HELPER FUNCTIONS */
long	ft_atol(const char *str);
char	**ft_split(const char *s, char c);
int		ft_isdigit(int c);
int		ft_strcmp(const char *s1, const char *s2);
int		stack_add_back(t_node **stack, t_node *new);
t_node	*stack_new_node(int new_value);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putnbr_fd(int nbr, int fd);
void	ft_putendl_fd(char *str, int fd);

#endif
