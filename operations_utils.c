#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"


// //stack declared as a static array 
// int stack[100];
// int top = -1;        // index of the top element

// void push(int x)
// {
// 	stack[++top] = x; 
// }

// int pop()
// {
// 	return (stack[top--]);      //returns then decrements
// }



// //stack implementation using linked list

// typedef struct s_node
// {
// 	int nbr;
// 	struct s_node *next;
// } t_node;


// t_node *top = NULL;     

// void push(t_node **top, int value)
// {
// 	t_node *new_node = (t_node* )malloc(sizeof(t_node));
// 	if(!new_node)
// 		return;

// 	new_node->nbr = value;
// 	new_node->next = *top;              //we make it to point to the current top

// 	//current top becomes the new node
// 	*top = new_node;
// }

// int pop(t_node **top)
// {
// 	if(*top == NULL)
// 		return (-1);
// 	t_node *temp = *top;     
// 	int popped_value = temp->nbr;

// 	*top = temp->next;
// 	free(temp);

// 	return (popped_value);
// }




//stack implementstion using doubly linked list

// typedef struct s_stack
// {
// 	int nbr;
// 	struct s_stack *next;
// 	struct s_stack *prev;
// } t_stack;


//t_stack *head = NULL;



void	push_node(t_stack **stack, t_stack *node)
{
	if (!stack || !node)
		return ;

	node->next = *stack;
	if (*stack)
		(*stack)->prev = node;
	node->prev = NULL;
	*stack = node;
}



t_stack	*pop(t_stack **stack)
{
	printf("Calling pop function\n");
	t_stack	*top;

	if (!(*stack) || !stack)
		return NULL;
	top = *stack;
	*stack = top->next;
	if (*stack)
		(*stack)->prev = NULL;
	top->next = NULL;
	top->prev = NULL;
	return (top);
}


//swaping top two elements

void	swap(t_stack	**stack)
{
	if(!(*stack) || !((*stack)->next))
		return ;
	
	t_stack *first_node = *stack;
	t_stack *second_node = first_node->next;

	first_node->next = second_node->next;
	if (second_node->next)
		second_node->next->prev = first_node;
	second_node->prev = NULL;
	second_node->next = first_node;
	first_node->prev = second_node;

	*stack = second_node;
}



//top becomes buttom    

//[10] [20] [30]
//[20] [30] [10]

void	rotate(t_stack **stack)
{
	if(!(*stack) || !((*stack)->next))
		return ;
	
	t_stack *first_node = *stack;

	//to find the last node we need to go from first to last
	t_stack *last_node = *stack;

	while (last_node->next)
		last_node = last_node->next;
	
	//last node is already pointing to the last element
	*stack = first_node->next;
	(*stack)->prev = NULL;

	first_node->next = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;
}


//reverse rotate, bottom becomes top

//[10] [20] [30]
//[30] [10] [20]


void reverse_rotate(t_stack **stack)
{
	if(!(*stack) || !((*stack)->next))
		return ;

	t_stack *first_node = *stack;
	t_stack *last_node = *stack;

	while (last_node->next)
		last_node = last_node->next;
	
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = first_node;
	first_node->prev = last_node;

	*stack = last_node;
}