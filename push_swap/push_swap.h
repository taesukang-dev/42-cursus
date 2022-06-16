#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# define SA 0
# define SB 1
# define SS 2

# define PA 0
# define PB 1

# define RA 0
# define RB 1
# define RR 2

# define RRA 0
# define RRB 1
# define RRR 2

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

// stack using doubly list
t_DoublyList		*create_doubly_list(void);
int					add_dl_element(t_DoublyList *dList, int data);
t_DoublyListNode	*pop_dl(t_DoublyList *dList);
t_DoublyListNode	*pop_right_dl(t_DoublyList *dList);

// commands
void	command_sab(t_DoublyList *dList, int flag);
void	command_ss(t_DoublyList *a, t_DoublyList *b);
void	command_pab(t_DoublyList *a, t_DoublyList *b, int flag);
void	command_rab(t_DoublyList *dList, int flag);
void	command_rr(t_DoublyList *a, t_DoublyList *b);
void	command_rrab(t_DoublyList *dList, int flag);
void	command_rrr(t_DoublyList *a, t_DoublyList *b);

# endif