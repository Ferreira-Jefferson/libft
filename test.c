#include <assert.h>
#include <stdio.h>
#include <string.h>
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

	// ft_memset
	printf("ft_memset: ");
	char str[] = "cinco";
	char *result = (char *) ft_memset(str, 5, 5);
	assert(result[0] == 5);
	assert(result[4] == 5);

	assert(str[0] == 5);
	assert(str[4] == 5);
	printf("OK \n");

	// ft_bzero
	printf("ft_bzero: ");
	char str_bzero[] = "cinco";
	ft_bzero(str_bzero, 5);
	assert(str_bzero[0] == 0);
	assert(str_bzero[4] == 0);

	int int_bzero[3] = {1, 2, 3};
	ft_bzero(int_bzero, sizeof(int_bzero));
	assert(int_bzero[0] == 0);
	assert(int_bzero[2] == 0);
	printf("OK \n");

	// ft_memcpy
	printf("ft_memcpy: ");
	char str_memcpy[] = "cinco";
	char dst[] = "teste";
	ft_memcpy(dst, str_memcpy, sizeof(str_memcpy));
	assert(dst[0] == 'c');
	assert(dst[4] == 'o');

	int int_memcpy[] = {1, 2, 3};
	int int_dst[3];
	ft_memcpy(int_dst, int_memcpy, sizeof(int_memcpy));
	assert(int_dst[0] == 1);
	assert(int_dst[2] == 3);
	printf("OK \n");

	// ft_memmove
	printf("ft_memmove: ");
	// Teste 1: Sobreposição - Destino ANTES da Origem (copia do final para o início)
    char overlap_dst_before_src[] = "abcdefg";
    ft_memmove(overlap_dst_before_src, overlap_dst_before_src + 2, 4); // Copia "cdef" para o início
    assert(overlap_dst_before_src[0] == 'c');
    assert(overlap_dst_before_src[3] == 'f');

    // Teste 2: Sobreposição - Destino DEPOIS da Origem (copia do início para o final)
    char overlap_dst_after_src[] = "abcdefg";
    ft_memmove(overlap_dst_after_src + 2, overlap_dst_after_src, 4); // Copia "abcd" para 'cdef'
    assert(overlap_dst_after_src[2] == 'a');
    assert(overlap_dst_after_src[5] == 'd');

    // Teste 3: Sem sobreposição (comportamento base)
    char src_no_overlap[] = "hello";
    char dst_no_overlap[6];
    ft_memmove(dst_no_overlap, src_no_overlap, strlen(src_no_overlap) + 1);
    assert(strcmp(dst_no_overlap, "hello") == 0);
	printf("OK \n");
	printf("\n*************** TESTS OK ************\n");
	return (0);
}