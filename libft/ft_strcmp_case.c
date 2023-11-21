#include "libft.h"

int	ft_strcmp_case(const char *s1, const char *s2, int flag)
{
    if (flag)
    {
        while (*s1 && *s2 && ft_tolower(*s1) == ft_tolower(*s2))
        {
            s1++;
            s2++;
        }
        return(ft_tolower(*s1) - ft_tolower(*s2));
    }
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return ((unsigned char) *s1 - (unsigned char) *s2);
}
