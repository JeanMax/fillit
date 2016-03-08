/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2016/03/08 21:01:17 by mcanal           ###   ########.fr       */
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
** struct def
typedef struct s_env	t_env;
struct					s_env
{
	char				**envp;
	t_bst				*bin_root;
	time_t				last_update;
};
*/

/*
** BASE
** error.c
*/
void					error(t_int flag, char *msg);

/*
** PARSER
** parse.c
*/
t_lst					*parse(char *file);

/*
** DOER
** todo.c
*/

#endif
