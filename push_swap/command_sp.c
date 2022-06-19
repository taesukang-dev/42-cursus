#include "push_swap.h"

void	command_sab(t_DoublyList *dList, int flag)
{
	t_DoublyListNode	*temp;
	t_DoublyListNode	*next;

	temp = dList->headerNode;
	next = dList->headerNode->next;
	temp->prev = next;
	dList->headerNode = next;
	temp->next = next->next;
	dList->headerNode->prev = NULL;
	dList->headerNode->next = temp;
	if (temp->next == dList->tailNode)
		dList->tailNode->prev = temp;
	if (flag == SA)
		write(1, "SA\n", 3);
	else if (flag == SB)
		write(1, "SB\n", 3);
}

void	command_ss(t_DoublyList *a, t_DoublyList *b)
{
	command_sab(a, SS);
	command_sab(b, SS);
	write(1, "SS\n", 3);
}

void	command_pab(t_DoublyList *a, t_DoublyList *b, int flag)
{
	t_DoublyListNode	*buf;

	if (flag == PA && b->currentElementCount != 0)
	{
		buf = pop_dl(b);
		add_dl_element(a, buf->data);
		free(buf);
		write(1, "PA\n", 3);
	}
	else if (flag == PB && a->currentElementCount != 0)
	{
		buf = pop_dl(a);
		add_dl_element(b, buf->data);
		free(buf);
		write(1, "PB\n", 3);
	}
}
