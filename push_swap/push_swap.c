#include "push_swap.h"

int main(int argc, char *argv[])
{
	int				*sorted_arr;
	t_DoublyList	*temp;
	t_DoublyList	*temp2;

	temp2 = create_doubly_list();
	init_doubly(&temp, argv, argc);
	sorted_arr = init_sorted_arr(temp);
	for(int i = 0; sorted_arr[i]; i++)
		printf("%d\n", sorted_arr[i]);
	// sorting(temp, temp2);
	// command_sab(temp, SA);
	// command_rrab(temp, RRA);
	// buf = temp->headerNode;
	// for(int i = 0; i < temp->currentElementCount; i++)
	// {
	// 	printf("%d \n", buf->data);
	// 	buf = buf->next;
	// }
	return (0);
}
