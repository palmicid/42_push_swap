#include <stdlib.h>
#include "libft/libft.h"

int	main(void)
{
	char	**strptr;

	strptr = (char **)malloc(sizeof(char *) * 3);
	int i = 0;
	while (i < 3)
	{
		strptr[i] = (char *)malloc(sizeof(char) * 2);
		strptr[i][0] = 'P';
		strptr[i][1] = 0;
		i++;
	}
	strptr[i] = 0;

	ft_free_p2p_char(strptr);
}
