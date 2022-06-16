#include "push_swap.h"

t_DoublyList	*create_doubly_list(void)
{
	t_DoublyList	*temp;

	temp = (t_DoublyList *)ft_calloc(1, sizeof(t_DoublyList));
	return (temp);
}

int	add_dl_element(t_DoublyList *dList, int data)
{
	t_DoublyListNode	*buf;
	t_DoublyListNode	*new;

	new = ft_calloc(1, sizeof(t_DoublyListNode));
	if (!new)
		return (0);
	new->data = data;
	if (dList->currentElementCount == 0)
	{
		dList->headerNode = new;
		dList->tailNode = new;
		dList->currentElementCount += 1;
		return (1);
	}
	buf = dList->headerNode;
	buf->prev = new;
	new->next = buf;
	dList->headerNode = new;
	dList->currentElementCount += 1;
	return (1);
}

t_DoublyListNode	*pop_dl(t_DoublyList *dList)
{
	t_DoublyListNode	*buf;

	if (dList->currentElementCount == 0)
		return (NULL);
	buf = dList->headerNode;
	dList->headerNode = dList->headerNode->next;
	if (dList->currentElementCount == 1)
		dList->tailNode = NULL;
	else
		dList->headerNode->prev = NULL;
	buf->prev = NULL;
	buf->next = NULL;
	dList->currentElementCount -= 1;
	return (buf);
}

t_DoublyListNode	*pop_right_dl(t_DoublyList *dList)
{
	t_DoublyListNode	*buf;

	if (dList->currentElementCount == 0)
		return (NULL);
	buf = dList->tailNode;
	dList->tailNode = dList->tailNode->prev;
	if (dList->currentElementCount == 1)
		dList->headerNode = NULL;
	else
		dList->tailNode->next = NULL;
	buf->prev = NULL;
	buf->next = NULL;
	dList->currentElementCount -= 1;
	return (buf);
}