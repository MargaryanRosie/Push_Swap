#include "../include/push_swap.h"

//1.divide the normalized input into chunks
//2.orinak unem 5 chunk
//n = 0(the next smallest index)     u offset = 5
//sksum em nayel [0, 5] chunky
//hertov nayum em stacki indexnery
//ete arajin indexy == n(aysinqn amenapoqr indexn e), push em anum B u rotate, vor pahi stacki verjum
//u n++, vor arden nayem hajord amenapoqry
//bayc ete havasar che n bayc nuyn chunki mej e, aysinqn index <= n + offset, uxxaki push em anum B, bayc rotate petq che, amenapoqr indexy che
//stex el em n++ anum, vor offsety araj gna, bayc payman enq grum vor  ed next expected-ic (n) poqrery eli push ani B u rotate
//isk ete ed offseti mek che, iran uxxaki pahum enq A-i mej, bayc rotate enq anum, vor A-i mnacac elementnery nayenq
//mec chunk chapy vat e, vorovhetev push em anum tvery random dzevov, voch mi dzevov sortavorvac chen
//bayc poqrik chunkeri depqum, skzbum push em anum orinak 0-5 mijakayqi index, heto 1-6, heto 2-7...hamematabar organized e, u heto push backi jmn aveli 
//qich operationner kogtagorcvi

static int	find_position(t_stack **b, int index)
{
	t_stack	*tmp;
	int		pos;

	tmp = *b;
	pos = 0;
	while (tmp)
	{
		if (tmp->index == index)
			return (pos);
		pos++;
		tmp = tmp->next;
	}
	return (-1);
}

static void	push_back(t_stack **a, t_stack **b)
{
	int	max_index;
	int	size_b;

	size_b = stack_size(*b);
	max_index = size_b - 1;
	while (*b)
	{
		if (find_position(b, (*b)->index) <= size_b / 2)              //in the first half of the stack
		{
			while ((*b)->index !=  max_index)
				rb(b, 0);
		}
		else
		{
			while ((*b)->index !=  max_index)                          //second half
				rrb(b, 0);
		}
		pa(a, b);
		max_index--;
	}
}

void	butterfly_sort(t_stack **a, t_stack **b)
{
	//considering normalized stack
	int next_expected;
	int	chunk_size;
	int	current_index;
	int	size;

	size = stack_size(*a);
	next_expected = 0;                                //the next smallest index
	chunk_size = ft_sqrt(size) + ft_cbrt(size);       //sqrt vorovhetev optimal chunk chap e, voch mec e voch poqr
	while (*a)
	{
		current_index = (*a)->index;
		if (current_index <= next_expected)
		{
			pb(a, b);
			rb(b, 0);
			next_expected++;
		}
		else if (current_index <= next_expected + chunk_size)          //ed chunki mej e, bayc amenapoqry che
		{
			pb(a, b);
			next_expected++;
		}
		else
			ra(a, 0);
	}
	push_back(a, b);
}