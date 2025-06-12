#include <stdio.h>
#include <stdlib.h>


//stack declared as a static array 
int stack[100];
int top = -1;        // index of the top element

void push(int x)
{
	stack[++top] = x; 
}

int pop()
{
	return (stack[top--]);      //returns then decrements
}



//stack implementation using linked list

typedef struct s_node
{
	int nbr;
	struct s_node *next;
} t_node;


t_node *top = NULL;     

void push(t_node **top, int value)
{
	t_node *new_node = (t_node* )malloc(sizeof(t_node));
	if(!new_node)
		return;

	new_node->nbr = value;
	new_node->next = *top;              //we make it to point to the current top

	//current top becomes the new node
	*top = new_node;
}

int pop(t_node **top)
{
	if(*top == NULL)
		return (-1);
	t_node *temp = *top;     
	int popped_value = temp->nbr;

	*top = temp->next;
	free(temp);

	return (popped_value);
}




//stack implementstion using doubly linked list

typedef struct s_stack
{
	int nbr;
	struct s_stack *next;
	struct s_stack *prev;
} t_stack;


t_stack *head = NULL;

void push(t_stack **stack, int value)       //**stack is a pointer to head
{
	t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
	if(!new_node)
		return;
	
	new_node->nbr = value;
	new_node->next = *stack;
	new_node->prev = NULL;
	if(*stack != NULL)         //vor hankarc NULL-i prevy chvercnem
		(*stack)->prev = new_node;
	*stack = new_node;
}


int pop(t_stack **stack)
{
	if(!*stack)
		return (-1);

	t_stack *temp = *stack;
	int popped_value = temp->nbr;

	*stack = temp->next;
	(*stack)->prev = NULL;

	free(temp);
	return (popped_value);
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