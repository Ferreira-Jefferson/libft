#include "libft.h"

int	ft_isascii(int c)
{	
	return ((unsigned char)c <= 127);
}