#include <assert.h>
#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test_ft_isupper(void);
void	test_ft_islower(void);
void	test_ft_toupper(void);
void	test_ft_tolower(void);
void	test_ft_isalpha(void);
void	test_ft_isdigit(void);
void	test_ft_isalnum(void);
void	test_ft_isascii(void);
void	test_ft_isprint(void);
void	test_ft_strlen(void);
void	test_ft_memset(void);
void	test_ft_bzero(void);
void	test_ft_memcpy(void);
void	test_ft_memmove(void);
void	test_ft_strlcpy(void);
void	test_ft_strlcat(void);
void	test_ft_strchr(void);

int	main(void)
{
	printf("\n\n*************** TESTS ***************\n\n");

	test_ft_isupper();
	test_ft_islower();
	test_ft_toupper();
	test_ft_tolower();
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
	test_ft_memmove();
	test_ft_strlcpy();
	test_ft_strlcat();
	test_ft_strchr();

	printf("\n*************** TESTS OK ************\n");
	return (0);
}
void	test_ft_strchr(void)
{
	printf("ft_strchr: ");
	char str[] = "uma frase de teste";

	char *ptr_first_e = ft_strchr(str, 'e');	
	assert(ptr_first_e == &str[8]);

	char *ptr_end_str = ft_strchr(str, '\0');
	assert(ptr_end_str == &str[18]);
	printf("OK \n");
}

void	test_ft_isupper(void)
{
	printf("ft_isupper: ");
	assert(ft_isupper('A') == 1);
	assert(ft_isupper('a') == 0);
	assert(ft_isupper('1') == 0);
	printf("OK \n");
}

void	test_ft_islower(void)
{
	printf("ft_islower: ");
	assert(ft_islower('A') == 0);
	assert(ft_islower('a') == 1);
	assert(ft_islower('1') == 0);
	printf("OK \n");
}

void	test_ft_toupper(void)
{
	printf("ft_toupper: ");
	assert(ft_toupper('A') == 'A');
	assert(ft_toupper('a') == 'A');
	assert(ft_toupper('1') == '1');
	printf("OK \n");
}

void	test_ft_tolower(void)
{
	printf("ft_tolower: ");
	assert(ft_tolower('A') == 'a');
	assert(ft_tolower('a') == 'a');
	assert(ft_tolower('1') == '1');
	printf("OK \n");
}

void	test_ft_isalpha(void)
{
	printf("ft_isalpha: ");
	assert(ft_isalpha('A') == 1);
	assert(ft_isalpha('a') == 1);
	assert(ft_isalpha('[') == 0);
	assert(ft_isalpha('1') == 0);
	printf("OK \n");
}

void	test_ft_isdigit(void)
{
	printf("ft_isdigit: ");
	assert(ft_isdigit('A') == 0);
	assert(ft_isdigit('a') == 0);
	assert(ft_isdigit('0') == 1);
	assert(ft_isdigit('9') == 1);
	printf("OK \n");
}

void	test_ft_isalnum(void)
{
	printf("ft_isalnum: ");
	assert(ft_isalnum('A') == 1);
	assert(ft_isalnum('a') == 1);
	assert(ft_isalnum('0') == 1);
	assert(ft_isalnum('9') == 1);
	assert(ft_isalnum('[') == 0);
	printf("OK \n");
}

void	test_ft_isascii(void)
{
	printf("ft_isascii: ");
	assert(ft_isascii(0) == 1);
	assert(ft_isascii(10) == 1);
	assert(ft_isascii(-1) == 0);
	assert(ft_isascii(128) == 0);
	printf("OK \n");
}

void	test_ft_isprint(void)
{
	printf("ft_isprint: ");
	assert(ft_isprint(-1) == 0);
	assert(ft_isprint(0) == 0);
	assert(ft_isprint(31) == 0);
	assert(ft_isprint(127) == 0);
	assert(ft_isprint(32) == 1);
	assert(ft_isprint(126) == 1);
	printf("OK \n");
}

void	test_ft_strlen(void)
{
	printf("ft_strlen: ");
	assert(ft_strlen("") == 0);
	assert(ft_strlen("cinco") == 5);
	printf("OK \n");
}

void	test_ft_memset(void)
{
	printf("ft_memset: ");
	char str[] = "cinco";
	char *result = (char *) ft_memset(str, 5, 5);
	assert(result[0] == 5);
	assert(result[4] == 5);

	assert(str[0] == 5);
	assert(str[4] == 5);
	printf("OK \n");
}

void	test_ft_bzero(void)
{
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
}

void	test_ft_memcpy(void)
{
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
}

void	test_ft_memmove(void)
{
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
}

void	test_ft_strlcpy(void)
{	
	printf("ft_strlcpy: ");
	char src[] = "um texto longo";
	char dst[5];
	size_t len_src = ft_strlcpy(dst, src, sizeof(dst));
	assert(dst[0] == 'u');
	assert(dst[3] == 't');
	assert(dst[4] == '\0');
	assert(len_src == 14);
	printf("OK \n");
}

void	test_ft_strlcat(void)
{	
	printf("ft_strlcat: ");
	char src[] = "um texto longo";
	
	// Teste 1: dst menor que src
	char dst_less[10] = "1-";
	size_t len = ft_strlcat(dst_less, src, sizeof(dst_less));
	assert(dst_less[0] == '1');
	assert(dst_less[2] == 'u');
	assert(dst_less[9] == '\0');
	assert(len == 16);

	// Teste 2: dst igual a src
	char dst_equal[15] = "";
	len = ft_strlcat(dst_equal, src, sizeof(dst_equal));
	assert(dst_equal[0] == 'u');
	assert(dst_equal[13] == 'o');
	assert(dst_equal[14] == '\0');
	assert(len == 14);

	// Teste 3: dst maior a src
	char dst_bigger[50] = "um texto longo";
	len = ft_strlcat(dst_bigger, src, sizeof(dst_bigger));
	assert(dst_bigger[0] == 'u');
	assert(dst_bigger[27] == 'o');
	assert(dst_bigger[28] == '\0');
	assert(len == 28);

	// Teste 4: dst maior a src, mas sem espaço suficiente para src
	char dst_bigger_but_not[20] = "um texto longo";
	len = ft_strlcat(dst_bigger_but_not, src, sizeof(dst_bigger_but_not));
	assert(dst_bigger_but_not[0] == 'u');
	assert(dst_bigger_but_not[18] == 'e');
	assert(dst_bigger_but_not[19] == '\0');
	assert(len == 28);
	printf("OK \n");
}