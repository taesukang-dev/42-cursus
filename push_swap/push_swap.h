#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

typedef struct s_DoublyListNodeType
{
	int	data;
	struct s_DoublyListNodeType *prev;
	struct s_DoublyListNodeType *next;
} t_DoublyListNode;

typedef struct s_DoublyListType
{
	int					currentElementCount;
	t_DoublyListNode	*headerNode;
	t_DoublyListNode	*tailNode;
} t_DoublyList;

t_DoublyList	*create_doubly_list(void);
int	add_dl_element(t_DoublyList *dList, int data);
t_DoublyListNode *pop_dl(t_DoublyList *dList);

# endif