/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 19:13:53 by mcanal            #+#    #+#             */
/*   Updated: 2016/03/02 01:47:24 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include <sys/types.h> //open
#include <sys/stat.h> //open
#include <fcntl.h> //open
#include <unistd.h> //close

static void		move_topleft(char **tetr)
{
	(void)tetr;
	//if *tetr == "...." then move up
	//if left col == "...." then move left
}

static t_bool	is_valid_tetr(char **tetr)
{
	//all chars are '.' or '#'
	//4 '#' (check now otherwise move_topleft is gonna cry)
	//line len = 4
	//"Chaque bloc d’un Tetriminos doit être en contact avec
	//au moins un autre bloc sur l’un ou l’autre de ses 4 côtés"
	move_topleft(tetr);
	return (!!tetr); //TODO
}

char			**parse(char *file)
{
	int		fd;
	char	**arr;

	if ((fd = open(file, O_RDONLY)) == -1)
		error(E_OPEN, file);
	file = NULL;
	arr = NULL;
	if (!get_all(fd, &file)) //TODO: do not skip extra '\n'
		error(E_READ, file);
	//4 lines then "\n\n"
	if (!*file || !(arr = ft_strsplit(file, '\n')) || !is_valid_tetr(arr))
		error(E_INVALID, NULL); //TODO: check one tetr at a time

	//over and out!
	ft_memdel((void *)&file);
	close(fd);
	return (arr);
}
