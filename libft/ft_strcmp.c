#include "libft.h"

int	ft_strcmp(const char *first, const char *second)
{
	size_t	i;

	i = 0;
	while ((first[i] || second[i]) && first[i] == second[i])
		i++;
	return ((unsigned char)first[i] -(unsigned char)second[i]);
}