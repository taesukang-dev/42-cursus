#include "push_swap.h"

int main(int argc, char *argv[])
{
	int				*sorted_arr;
	t_DoublyList	*temp;
	t_DoublyList	*temp2;

	t_DoublyListNode	*buf;

	temp2 = create_doubly_list();
	init_doubly(&temp, argv, argc);
	sorted_arr = init_sorted_arr(temp);
	sorting(temp, temp2, sorted_arr);
	
	// buf = temp->headerNode;
	// for(int i = 0; i < temp->currentElementCount; i++)
	// {
	// 	printf("%d \n", buf->data);
	// 	buf = buf->next;
	// }

	// printf("===========================\n");

	// buf = temp2->headerNode;
	// for(int i = 0; i < temp2->currentElementCount; i++)
	// {
	// 	printf("%d \n", buf->data);
	// 	buf = buf->next;
	// }

	return (0);
}
