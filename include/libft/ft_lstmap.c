/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edufour <edufour@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 13:36:21 by edufour           #+#    #+#             */
/*   Updated: 2022/12/08 15:35:51 by edufour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*a_new;
	t_list	*new_list;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		content = (f(lst->content));
		a_new = ft_lstnew(content);
		if (!a_new)
		{
			ft_lstclear(&new_list, del);
			free (content);
			return (NULL);
		}
		ft_lstadd_back(&new_list, a_new);
		lst = lst->next;
	}
	return (new_list);
}
