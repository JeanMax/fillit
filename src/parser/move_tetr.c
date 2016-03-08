/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 00:32:55 by mcanal            #+#    #+#             */
/*   Updated: 2016/03/09 00:38:21 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** move tetr to the top left corner
*/

#include "parser.h"

static void		move_up(char **tetr)
{
	char	*s;

	s = *tetr;
	*tetr = *(tetr + 1);
	*(tetr + 1) = *(tetr + 2);
	*(tetr + 2) = *(tetr + 3);
	*(tetr + 3) = s;
}

static void		move_left(char **tetr)
{
	char	c;
	int		i;

	i = -1;
	while (++i < 4)
	{
		c = tetr[i][0];
		tetr[i][0] = tetr[i][1];
		tetr[i][1] = tetr[i][2];
		tetr[i][2] = tetr[i][3];
		tetr[i][3] = c;
	}
}

void			move_topleft(char **tetr)
{
	while (!ft_strcmp(*tetr, "...."))
		move_up(tetr);
	while (tetr[0][0] == '.' && tetr[1][0] == '.'
			&& tetr[2][0] == '.' && tetr[3][0] == '.')
		move_left(tetr);
}
