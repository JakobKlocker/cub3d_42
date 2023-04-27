#include "libft.h"

int    ft_strcmp(char *s1, char *s2)
{
    unsigned int    compare;

    if (s1 == NULL || s2 == NULL)
        return (0);
    compare = 0;
    while ((s1[compare] == s2[compare]) && (s1[compare] != '\0'
            && s2[compare] != '\0'))
    {
        compare++;
    }
    return (s1[compare] - s2[compare]);
}