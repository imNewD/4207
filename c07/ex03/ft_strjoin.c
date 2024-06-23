#include <stdlib.h>
#include <stdio.h>

int str_len(char *str)
{
    int len = 0;

    while (str[len] != '\0')
        len++;
    return len;
}

char *ft_strjoin(int size, char **strs, char *sep)
{
    char *s;
    int total_len = 0;
    int i = 0;
    int j, k;
    int sep_len;

    if (size == 0)
    {
        s = malloc(1); // Allocate memory for an empty string
        if (s == NULL)
            return NULL;
        s[0] = '\0'; // Set the empty string
        return s;
    }

    sep_len = str_len(sep);

    while (i < size)
    {
        total_len += str_len(strs[i]);
        i++;
    }
    total_len += sep_len * (size - 1);

    s = malloc(total_len + 1);
    if (s == NULL)
        return NULL;

    i = 0;
    k = 0;
    while (i < size)
    {
        j = 0;
        while (strs[i][j] != '\0')
        {
            s[k] = strs[i][j];
            j++;
            k++;
        }
        if (i < size - 1)
        {
            j = 0;
            while (sep[j] != '\0')
            {
                s[k] = sep[j];
                j++;
                k++;
            }
        }
        i++;
    }
    s[k] = '\0';
    return s;
}


int main(void)
{
    char *tab[4];
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

    return 0;
}

