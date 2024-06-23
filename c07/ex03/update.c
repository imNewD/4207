#include <stdlib.h>
#include <stdio.h>

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		total_len;
	int		i;
	int		j;
	int		c;
	int		sep_len;

	if (size == 0)
	{
		s = malloc(1);
		if (s == NULL)
			return (NULL);
		s[0] = '\0';
		return (s);
	}
	sep_len = str_len(sep);
	total_len = 0;
	i = 0;
	while (i < size)
		total_len += str_len(strs[i++]);
	total_len += sep_len * (size - 1);
	s = malloc(total_len + 1);
	if (s == NULL)
		return (NULL);
	i = -1;
	c = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
			s[c++] = strs[i][j++];
		j = 0;
		while (sep[j] != '\0' && i < size - 1)
			s[c++] = sep[j++];
	}
	s[c] = '\0';
	return (s);
}

/*
int	main(void)
{
	char	*tab[4];

	tab[0] = "Hello";
	tab[1] = "World";
	tab[2] = "How";
	tab[3] = "Are you";

	char *result = ft_strjoin(4, tab, " ");
	if (result != NULL)
	{
		printf("%s\n", result);
		free(result);
	}

	// Test with size 0
	result = ft_strjoin(0, tab, " ");
	if (result != NULL)
	{
		printf("Empty string: '%s'\n", result);
		free(result);
	}

	return (0);
}
*/
