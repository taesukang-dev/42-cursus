#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buf;

	if (!lst || !del)
		return ;
	while(*lst)
	{
		buf = (*lst)->next;
		ft_lstdelone((*lst), del);
		*lst = buf;
	}
	*lst = NULL;
}