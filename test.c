#include <assert.h>
#include <stdio.h>
#include "libft.h"

int	main(void)
{
	printf("\n\n*************** TESTS ***************\n\n");

	// ft_toupper
	printf("ft_toupper: ");
	assert(ft_toupper('A') == 1);
	assert(ft_toupper('a') == 0);
	assert(ft_toupper('1') == 0);
	printf("OK \n");

	// ft_tolower
	printf("ft_tolower: ");
	assert(ft_tolower('A') == 0);
	assert(ft_tolower('a') == 1);
	assert(ft_tolower('1') == 0);
	printf("OK \n");

	// ft_isalpha
	printf("ft_isalpha: ");
	assert(ft_isalpha('A') == 1);
	assert(ft_isalpha('a') == 1);
	assert(ft_isalpha('[') == 0);
	assert(ft_isalpha('1') == 0);
	printf("OK \n");

	// ft_isdigit
	printf("ft_isdigit: ");
	assert(ft_isdigit('A') == 0);
	assert(ft_isdigit('a') == 0);
	assert(ft_isdigit('0') == 1);
	assert(ft_isdigit('9') == 1);
	printf("OK \n");

	// ft_isalnum
	printf("ft_isalnum: ");
	assert(ft_isalnum('A') == 1);
	assert(ft_isalnum('a') == 1);
	assert(ft_isalnum('0') == 1);
	assert(ft_isalnum('9') == 1);
	assert(ft_isalnum('[') == 0);
	printf("OK \n");

	// ft_isascii
	printf("ft_isascii: ");
	assert(ft_isascii(0) == 1);
	assert(ft_isascii(10) == 1);
	assert(ft_isascii(-1) == 0);
	assert(ft_isascii(128) == 0);
	printf("OK \n");

	// ft_isprint
	printf("ft_isprint: ");
	assert(ft_isprint(-1) == 0);
	assert(ft_isprint(0) == 0);
	assert(ft_isprint(31) == 0);
	assert(ft_isprint(127) == 0);
	assert(ft_isprint(32) == 1);
	assert(ft_isprint(126) == 1);
	printf("OK \n");

	// ft_strlen
	printf("ft_strlen: ");
	assert(ft_strlen("") == 0);
	assert(ft_strlen("cinco") == 5);
	printf("OK \n");

	printf("\n*************** TESTS OK ************\n");
	return (0);
}