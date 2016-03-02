/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 00:12:49 by mcanal            #+#    #+#             */
/*   Updated: 2016/03/02 01:48:51 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main...
*/

#include "fillit.h"

/* <debug */
static void		debug_data(char **data)
{
	if (!*data)
		return ;
	ft_debugstr("data", *data);
	debug_data(data + 1);
}
/* debug> */

int				main(int ac, char **av)
{
	char	**data; //what about a list(simple?) of char **(tetr)?

	if (ac != 2)
		error(E_USAGE, NULL);
	data = parse(*(++av));

	debug_data(data);			/* debug */

	ft_arrdel(&data); //it's so useful to free before exiting!
	return (EXIT_SUCCESS);
}
