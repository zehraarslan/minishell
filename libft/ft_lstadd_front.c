/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faydin <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/20 17:37:29 by faydin            #+#    #+#             */
/*   Updated: 2022/01/30 13:58:54 by faydin           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

/*
int	main()
{
	t_list *ilk;
	char dizi[] = "ilk content";
	t_list *iki;
	char dizi2[] = "ikinci content";
	ilk = ft_lstnew(dizi);
	iki = ft_lstnew(dizi2);

	ft_lstadd_front(&ilk,iki);
	printf("%s",(ilk)->content);
}*/
