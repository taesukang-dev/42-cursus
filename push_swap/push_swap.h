#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# define SA 0
# define SB 1
# define SS 2

# define PA 0
# define PB 1

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
void	command_sab(t_DoublyList *dList, int flag);
void	command_ss(t_DoublyList *a, t_DoublyList *b);
void	command_pab(t_DoublyList *a, t_DoublyList *b, int flag);


# endif