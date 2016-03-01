/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/12 03:39:12 by mcanal            #+#    #+#             */
/*   Updated: 2016/03/01 19:59:29 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** errors handling
** first arg is a flag including enums e_error (cf .h) (ex: E_OPEN | E_NOEXIT)
** second arg is an optionnal error message
*/

#include "fillit.h"
#include <stdlib.h>

//I'm pretty sure there is another way...
static int		get_index(t_int flag)
{
	int		index;

	index = 0;
	while ((flag /= 2))
		index++;
	return (index - 1);
}

void			error(t_int flag, char *msg)
{
	const char	*error[] = {
		"Usage: ./fillit <file>", //TODO: save av[0] in global?
		"Dang... can't open file: ",
		"Ouch... can't read file: ",
		"What the heck is that file? Nah, just try with something else."
	};

	if (msg)
	{
		fail(error[get_index(flag & (t_int)~E_NOEXIT)]);
		failn(msg);
	}
	else
		failn(error[get_index(flag & (t_int)~E_NOEXIT)]);
	if (!(flag & E_NOEXIT))
		exit(EXIT_FAILURE); //TODO: forbidden?
}
