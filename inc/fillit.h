/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2016/05/24 12:09:04 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

/*
** define
*/
# define FILLIT_H

/*
** include
*/
# include "libft.h"

/*
** enum
*/
enum					e_error
{
	E_NOERROR = 0, //wtf...
	E_NOEXIT = (1 << 0),
	E_USAGE = (1 << 1),
	E_OPEN = (1 << 2),
	E_READ = (1 << 3),
	E_INVALID = (1 << 4),
};

/*
** BASE
** error.c
*/
void					error(t_uint flag, char *msg);

/*
** PARSER
** parse.c
*/
void					parse(char *file, t_arr *tetr_arr);

/*
** DOER
** todo.c
*/

#endif
