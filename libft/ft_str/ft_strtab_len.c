#include "libft.h"

size_t	ft_strtab_len(char **tab)
{
	size_t	i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		++i;
	return (i);
}
