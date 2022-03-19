#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*buf;
	t_list	*head;

	if (!lst || !f || !del)
		return (NULL);
	buf = ft_lstnew(f(lst->content));
	if (!buf)
		return (NULL);
	lst = lst->next;
	head = buf;
	while (lst)
	{
		buf->next = ft_lstnew(f(lst->content));
		if (!buf->next)
		{
			ft_lstclear(&buf, del);
			break;
		}
		lst = lst->next;
		buf = buf->next;
	}
	return (head);
}
