/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romargar <romargar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 13:31:32 by romargar          #+#    #+#             */
/*   Updated: 2025/06/23 15:11:27 by romargar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static void	free_if_wrong_instr(char *instr, t_stack **a, t_stack **b)
{
	free_stack(*a);
	free_stack(*b);
	get_next_line(-102);
	free(instr);
	error_exit();
}

static void	do_instruction(char *instr, t_stack **a, t_stack **b)
{
	if (ft_strncmp(instr, "pa\n", 3) == 0)
		pa(a, b, 1);
	else if (ft_strncmp(instr, "pb\n", 3) == 0)
		pb(a, b, 1);
	else if (ft_strncmp(instr, "sa\n", 3) == 0)
		sa(a, 1);
	else if (ft_strncmp(instr, "sb\n", 3) == 0)
		sb(b, 1);
	else if (ft_strncmp(instr, "ss\n", 3) == 0)
		ss(a, b, 1);
	else if (ft_strncmp(instr, "ra\n", 3) == 0)
		ra(a, 1);
	else if (ft_strncmp(instr, "rb\n", 3) == 0)
		rb(b, 1);
	else if (ft_strncmp(instr, "rr\n", 3) == 0)
		rr(a, b, 1);
	else if (ft_strncmp(instr, "rra\n", 4) == 0)
		rra(a, 1);
	else if (ft_strncmp(instr, "rrb\n", 4) == 0)
		rrb(b, 1);
	else if (ft_strncmp(instr, "rrr\n", 4) == 0)
		rrr(a, b, 1);
	else
		free_if_wrong_instr(instr, a, b);
}

static void	print_ok_ko(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && stack_size(b) == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*instr;

	if (argc == 1)
		return (0);
	stack_b = NULL;
	stack_a = parse_arguments(argc, argv);
	if (!stack_a)
		error_exit();
	instr = get_next_line(0);
	while (instr)
	{
		do_instruction(instr, &stack_a, &stack_b);
		free(instr);
		instr = get_next_line(0);
	}
	free(instr);
	print_ok_ko(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	get_next_line(-102);
	return (0);
}
