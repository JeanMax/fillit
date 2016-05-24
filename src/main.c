/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 00:12:49 by mcanal            #+#    #+#             */
/*   Updated: 2016/05/24 15:21:00 by mcanal           ###   ########.fr       */
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

static void		debug_tetr_arr(char ***tetr_arr_ptr)
{
	if (!*tetr_arr_ptr)
		return ;
	ft_debugstr("tetr_arr", "zboub");
	debug_tetr(*tetr_arr_ptr);
	debug_tetr_arr(tetr_arr_ptr + 1);
}
/* debug> */

static void		free_tetr(void *tetr, size_t useless)
{
	char **swap;

	(void)useless;
	swap = *(char ***)tetr;
	while (*swap)
		ft_memdel((void **)swap++);
	ft_memdel(tetr);
}

int				main(int ac, char **av)
{
	t_arr	*tetr_arr;

	if (ac != 2)
		error(E_USAGE, NULL);
	tetr_arr = ft_arrnew(26, sizeof(char **)); //TODO: start with less?
	tetr_arr->del = free_tetr;

	parse(*(++av), tetr_arr);

	debug_tetr_arr(tetr_arr->ptr);			/* debug */

	ft_arrdel(&tetr_arr);
	return (EXIT_SUCCESS);
}
