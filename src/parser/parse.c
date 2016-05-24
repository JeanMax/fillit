/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 19:13:53 by mcanal            #+#    #+#             */
/*   Updated: 2016/05/24 14:57:19 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** parse tetr list from file, check input errors
** will fill a double linked list of char **tetr (4x4)
*/

#include "parser.h"
#include <sys/types.h> //open
#include <sys/stat.h> //open
#include <fcntl.h> //open
#include <unistd.h> //close
#include <stdlib.h> //malloc

static t_bool	touch_my_tetr(char **tetr, int i, int j)
{
	if ((j && tetr[i][j - 1] != '#')	//left
			&& tetr[i][j + 1] != '#'	//right
			&& (i < 3 && tetr[i + 1][j] != '#')	//down
			&& (i && tetr[i - 1][j] != '#'))	//up
		error(E_INVALID, "# doesn't touch a #.");
	return (TRUE);
}

static void		check_tetr(char **tetr)
{
	int		sharp;
	int		i;
	int		j;

	sharp = 0;
	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			if (tetr[i][j] == '#' && touch_my_tetr(tetr, i, j))
				sharp++;
			else if (tetr[i][j] != '.')
				error(E_INVALID, "wrong character.");
		if (tetr[i][4] != '\n')
			error(E_INVALID, "missing end of line.");
		tetr[i][4] = 0;
	}
	if (sharp != 4)
		error(E_INVALID, "we need 4 # / tetr");
}

static char		**new_tetr(void)
{
	char	**tetr;
	int		i;

	if (!(tetr = (char **)malloc(sizeof(char *) * 5)))
		return (NULL);
	i = 0;
	while (i < 4)
		tetr[i++] = (char *)malloc(sizeof(char) * 5);
	tetr[i] = NULL;
	return (tetr);
}

static void		read_tetr(int fd, t_arr *tetr_arr)
{
	int		i;
	ssize_t	ret;
	char	buf[25];
	char	**tetr;

	ft_bzero((void *)buf, 25);
	if ((ret = read(fd, (void *)buf, 21)) != 21)
	{
		if (ret != 20)
			error(E_INVALID, "wrong size.");
		else
			ret = FALSE; //this is the last tetr!
	}
	else if (*(buf + 20) != '\n')
		error(E_INVALID, "missing end of line between tetr.");
	tetr = new_tetr();
	i = -1;
	while (++i < 4)
		ft_memcpy(tetr[i], buf + (i * 5), 5);
	check_tetr(tetr);
	move_topleft(tetr);
	ft_arrpush(tetr_arr, tetr, -1);
	if (ret)
		read_tetr(fd, tetr_arr);
}

void			parse(char *file, t_arr *tetr_arr)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		error(E_OPEN, file);
	read_tetr(fd, tetr_arr);
	close(fd);
}
