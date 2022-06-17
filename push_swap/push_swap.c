#include "push_swap.h"

// delete it later
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_DoublyList	*temp;
	t_DoublyList	*temp2;
	t_DoublyListNode	*buf;

	init_doubly(&temp, argv, argc);
	sorting(temp, temp2);
	buf = temp->headerNode;
	for(int i = 0; i < temp->currentElementCount; i++)
	{
		printf("%d \n", buf->data);
		buf = buf->next;
	}
	return (0);
}
