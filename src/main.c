/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 00:12:49 by mcanal            #+#    #+#             */
/*   Updated: 2016/03/08 23:57:34 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main...
*/

#include "fillit.h"

/* <debug */
static void		debug_tetr(char **tetr)
{
	if (!*tetr)
		return ;
	ft_debugstr("tetr", *tetr);
	debug_tetr(tetr + 1);
}

static void		debug_list(t_lst *list)
{
	if (!list)
		return ;
	ft_debugstr("zboub", "zob");
	debug_tetr(*(char ***)list->content);
	debug_list(list->next);
}
/* debug> */

static void		clean_data(t_lst **list)
{
	t_lst   *next;

	if (!*list)
		return ;
	next = (*list)->next;
	ft_arrdel((char ***)(*list)->content);
	ft_memdel((void *)&(*list)->content);
    ft_memdel((void *)list);
	clean_data(&next);
}

int				main(int ac, char **av)
{
	t_lst	*data;

	if (ac != 2)
		error(E_USAGE, NULL);
	data = parse(*(++av));

	debug_list(data);			/* debug */

	clean_data(&data); //it's so useful to free before exiting!
	return (EXIT_SUCCESS);
}
