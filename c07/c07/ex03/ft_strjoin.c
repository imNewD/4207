#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*s;
	int		i;
	int		j;
	int		c;
if (size == 0)
{
    s = malloc(1);
    if (!s) return NULL;
    s[0] = '\0';
    return s;
}

	s = malloc(sizeof(strs));
	i = 0;
	c = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			s[c++] = strs[i][j++];
		}
		j = 0;
		while (sep[j] != '\0' && i != size - 1)
		{
			s[c++] = sep[j++];
		}
		i++;
	}
	s[c] = '\0';
	return (s);
}
/*
int	main(void)
{
	char	*tab[4];
	tab[0] = "h";
	tab[1] = "e";
	tab[2] = "ll";
	tab[3] = "o";
	printf("%s", ft_strjoin(4, tab, ""));
	return (0);
}
*/