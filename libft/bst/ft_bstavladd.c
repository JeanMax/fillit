/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bstavladd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 01:57:44 by mcanal            #+#    #+#             */
/*   Updated: 2015/12/12 22:19:05 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** balance a tree using left/right rotations (AVL)
*/

#include "libft.h"

static int		h(t_bst *node)
{
	return (node ? (int)node->height : 0);
}

static t_bst	*rot_right(t_bst *root, int ret)
{
	t_bst	*node;

	if (!ret)
		return (root);
	if (ret < 0)
	{
		node = root->right->left;
		root->right->left = node->right;
		node->right = root->right;
		root->right = node;
		node->height = (size_t)ft_max(h(node->left), h(node->right)) + 1;
		root->right->height = (size_t)\
			ft_max(h(root->right->left), h(root->right->right)) + 1;
	}
	node = root->right;
	root->right = node->left;
	node->left = root;
	node->height = (size_t)ft_max(h(node->left), h(node->right)) + 1;
	root->height = (size_t)ft_max(h(root->left), h(root->right)) + 1;
	return (node);
}

static t_bst	*rot_left(t_bst *root, int ret)
{
	t_bst	*node;

	if (!ret)
		return (root);
	if (ret > 0)
	{
		node = root->left->right;
		root->left->right = node->left;
		node->left = root->left;
		root->left = node;
		node->height = (size_t)ft_max(h(node->left), h(node->right)) + 1;
		root->left->height = (size_t)\
			ft_max(h(root->left->left), h(root->left->right)) + 1;
	}
	node = root->left;
	root->left = node->right;
	node->right = root;
	node->height = (size_t)ft_max(h(node->left), h(node->right)) + 1;
	root->height = (size_t)ft_max(h(root->left), h(root->right)) + 1;
	return (node);
}

static t_bst	*add_loop(t_bst *node, t_bst *new, \
							int (*cmp)(const void *a, const void *b))
{
	int	ret;

	if (!node)
		return (new);
	if ((ret = cmp(node, new)) < 0)
	{
		node->left = add_loop(node->left, new, cmp);
		if ((h(node->left) - h(node->right)) == 2)
			node = rot_left(node, cmp(node->left, new));
	}
	else if (ret > 0)
	{
		node->right = add_loop(node->right, new, cmp);
		if ((h(node->left) - h(node->right)) == -2)
			node = rot_right(node, cmp(node->right, new));
	}
	else
		new->height = 0;
	node->height = (size_t)ft_max(h(node->left), h(node->right)) + 1;
	return (node);
}

void			ft_bstavladd(t_bst **root, void *content, size_t content_size, \
							int (*cmp)(const void *a, const void *b))
{
	t_bst *new;

	new = ft_bstnew(content, content_size);
	*root = add_loop(*root, new, cmp);
	if (new->height == 0)
		ft_bstfree(&new);
}
