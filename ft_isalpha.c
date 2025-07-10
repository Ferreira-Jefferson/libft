#include "libft.h"

int	ft_isalpha(int c)
{
	return (ft_toupper(c) || ft_tolower(c));
}