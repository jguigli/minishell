#include "../../includes/minishell.h"

void	exec_complex_cmd(t_ast *ast) // exécution de la ligne de commande avec l'ast => gestion des pipes, redirs, here_doc, ||, &&
{

}

void	exec_simple_cmd(t_dblist *list) // exécution de la ligne de commande avec le process classique (pid, execve, etc..)
{

}

t_ast	*build_complex_cmd(t_dblist *list) // construit l'AST à partir de la liste de tokens
{

}

int	exec_launcher(t_dblist *list) // cette fonction intervient après le parsing normalement
{
	t_ast	*ast;

	if (list->has_pipe || list->has_redir) // si la liste a un pipe ou une redir au moins
	{
		ast = build_complex_cmd(list);
		exec_complex_cmd(ast);
	}
	else if (!list->has_pipe && !list->has_redir) // si la liste a aucun des deux
	{
		exec_simple_cmd(list);
	}
	return (1);
}