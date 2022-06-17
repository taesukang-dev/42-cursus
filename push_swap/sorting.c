#include "push_swap.h"

void	sorting(t_DoublyList *a, t_DoublyList *b)
{
	if (a->currentElementCount == 2)
	{
		if (a->headerNode->data > a->headerNode->next->data)
			command_sab(a, SA);
	}
}