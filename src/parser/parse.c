/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/01 19:13:53 by mcanal            #+#    #+#             */
/*   Updated: 2016/03/01 20:24:40 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

static t_bool	is_valid(char **arr)
{
	return (!!*arr); //TODO
}

char			**parse(char *file)
{
	int		fd;
	char	**arr;

	if ((fd = open(file, O_RDONLY)) == -1)
		error(E_OPEN, file);
	file = NULL;
	arr = NULL;
	if (!get_all(fd, &file))
		error(E_READ, file);
	if (!*file || !(arr = ft_strsplit(file, '\n')) || !is_valid(arr))
		error(E_INVALID, NULL);
	ft_memdel((void *)&file);
	return (arr);
}
