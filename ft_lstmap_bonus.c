/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoyverdito <zoyverdito@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 00:49:55 by zoyverdito        #+#    #+#             */
/*   Updated: 2023/05/08 00:50:27 by zoyverdito       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *)) {
    if (lst == NULL || f == NULL) {
        return NULL;
    }

    t_list *new_list = NULL;
    t_list *new_node = NULL;
    t_list *last_node = NULL;

    while (lst != NULL) {
        new_node = malloc(sizeof(t_list));
        if (new_node == NULL) {
            ft_lstclear(&new_list, del);
            return NULL;
        }

        new_node->content = f(lst->content);
        new_node->next = NULL;

        if (last_node == NULL) {
            new_list = new_node;
        } else {
            last_node->next = new_node;
        }

        last_node = new_node;
        lst = lst->next;
    }

    return new_list;
}