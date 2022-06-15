#include "../../includes/minishell.h"

char	*ft_strjoin_path(char *s1, char *s2)
{
	static char	*cat;
	int			length;

	if (!s1)
		s1 = ft_strdup("");
	length = ft_strlen(s1) + ft_strlen(s2);
	cat = (char *)malloc(sizeof(char) * length + 1);
	if (!cat)
		return (NULL);
	cat[0] = '\0';
	cat = ft_strcat(cat, s1);
	cat = ft_strcat(cat, s2);
	cat[length] = '\0';
	return (cat);
}
