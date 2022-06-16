#include "push_swap.h"
#include <stdio.h>

void	init_doubly(t_DoublyList *dList, char *argv[], int argc)
{
	size_t	i;

	i = argc - 1;
	while(i > 0)
	{
		add_dl_element(dList, ft_atoi(argv[i]));
		i--;
	}
}

int main(int argc, char *argv[])
{
	t_DoublyList	*temp;
	t_DoublyList	*temp2;
	t_DoublyListNode	*buf;
	
	temp = create_doubly_list();
	init_doubly(temp, argv, argc);
	buf = temp->headerNode;
	for(int i = 0; i < temp->currentElementCount; i++)
	{
		printf("%d \n", buf->data);
		buf = buf->next;
	}
	temp2 = create_doubly_list();
	return (0);
}