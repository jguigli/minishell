#include "../includes/minishell.h"

t_treenode	create_node(t_dblist *list)
{
	t_treenode *tree;

	tree = malloc(sizeof(t_treenode));
	if (!tree)
		return ;
	tree->first = list->first;
	tree->left = NULL;
	tree->right = NULL;
}