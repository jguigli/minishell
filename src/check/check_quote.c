int	check_quote(char *str)
{
	int	i;
	int	simpleq;
	int	doubleq;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"')
			doubleq++;
		if (str[i] == 39)
			simpleq++;
		i++;
	}
	if (!(doubleq % 2) && !(simpleq % 2))
		return (1);
	else
		return (0);
}