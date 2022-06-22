#include "push_swap.h"

void	command_rab(t_DoublyList *dList, int flag)
{
	t_DoublyListNode	*temp;

	if (dList->currentElementCount < 2)
		return ;
	temp = pop_dl(dList);
	add_right_dl_element(dList, temp->data);
	free(temp);
	if (flag == RA)
		write(1, "RA\n", 3);
	else if (flag == RB)
		write(1, "RB\n", 3);
}

void	command_rr(t_DoublyList *a, t_DoublyList *b)
{
	command_rab(a, RR);
	command_rab(b, RR);
	write(1, "RR\n", 3);
}

void	command_rrab(t_DoublyList *dList, int flag)
{
	t_DoublyListNode	*temp;

	if (dList->currentElementCount < 2)
		return ;
	temp = pop_right_dl(dList);
	add_dl_element(dList, temp->data);
	free(temp);
	if (flag == RRA)
		write(1, "rra\n", 4);
	if (flag == RRB)
		write(1, "rrb\n", 4);
}

void	command_rrr(t_DoublyList *a, t_DoublyList *b)
{
	command_rrab(a, RRR);
	command_rrab(b, RRR);
	write(1, "RRR\n", 4);
}