#include "push_swap.h"

// delete it later
#include <stdio.h>

int main(int argc, char *argv[])
{
	t_DoublyList	*temp;
	t_DoublyList	*temp2;
	t_DoublyListNode	*buf;

	init_doubly(&temp, argv, argc);
	// command_pab(temp, temp2, PB);
	// command_ss(temp, temp2);
	// command_rab(temp, PA);
	// command_rr(temp, temp2);
	// command_rrr(temp, temp2);
	buf = temp->headerNode;
	for(int i = 0; i < temp->currentElementCount; i++)
	{
		printf("%d \n", buf->data);
		buf = buf->next;
	}
	printf("===============================================================\n");
	// buf = temp2->headerNode;
	// for(int i = 0; i < temp2->currentElementCount; i++)
	// {
	// 	printf("%d \n", buf->data);
	// 	buf = buf->next;
	// }
	// printf("===============================================================\n");

	return (0);
}
