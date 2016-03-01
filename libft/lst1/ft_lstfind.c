/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 05:25:28 by mcanal            #+#    #+#             */
/*   Updated: 2015/12/03 18:05:45 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** retourne l’adresse du premier élément dont la donnée est
** "égale" à la donnée de référence
*/

#include "libft.h"

t_list			**ft_lstfind(t_list **alst, void *data, \
							int (*cmp)(const void *a, const void *b))
{
	if (!(*alst) || !cmp(*alst, data))
		return (alst);
	return (ft_lstfind(&(*alst)->next, data, cmp));
}
