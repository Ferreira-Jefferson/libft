#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "libft.h"
#include <bsd/string.h>

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
void	test_ft_strrchr(void);
void	test_ft_strncmp(void);
void	test_ft_memchr(void);
void	test_ft_memcmp(void);
void	test_ft_strstr(void);
void	test_ft_atoi(void);
void	test_ft_calloc(void);
void	test_ft_strdup(void);
void	test_ft_substr(void);
void	test_ft_strjoin(void);
void	test_ft_strtrim(void);
void	test_ft_split(void);
void	test_ft_itoa(void);
void	test_ft_strmapi(void);

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
	test_ft_strrchr();
	test_ft_strncmp();
	test_ft_memchr();
	test_ft_memcmp();
	test_ft_strstr();
	test_ft_atoi();
	test_ft_calloc();
	test_ft_strdup();
	test_ft_substr();
	test_ft_strjoin();
	test_ft_strtrim();
	test_ft_split();
	test_ft_itoa();
	test_ft_strmapi();

	printf("\n*************** TESTS OK ************\n");
	return (0);
}

char pass_to_1_if_odd_or_subsequent_char(unsigned int index, char sub)
{
	if(index & 0b1)
		return ('1');
	return (sub + 1);
}
void	test_ft_strmapi(void)
{
	printf("ft_strmapi: ");

	// s1 nula
	char *s = NULL;
	char *result = ft_strmapi(s, pass_to_1_if_odd_or_subsequent_char);
    assert(result == NULL);

	// s1 vazia
	s = ft_strdup("");
	result = ft_strmapi(s, pass_to_1_if_odd_or_subsequent_char);
    assert(strcmp(result, "") == 0);
    free(s);
    free(result);

	// s1 com um char
	s = ft_strdup("1");
	result = ft_strmapi(s, pass_to_1_if_odd_or_subsequent_char);
    assert(strcmp(result, "2") == 0);
    free(s);
    free(result);

	// s1 n char
	s = ft_strdup("12345");
	result = ft_strmapi(s, pass_to_1_if_odd_or_subsequent_char);
    assert(strcmp(result, "21416") == 0);
    free(s);
    free(result);

	printf("OK\n");
}

void    test_ft_itoa(void)
{
    printf("ft_itoa: ");

    char *result;

    // Teste com número positivo
    result = ft_itoa(123);
    assert(strcmp(result, "123") == 0);
    free(result);

    // Teste com número negativo
    result = ft_itoa(-456);
    assert(strcmp(result, "-456") == 0);
    free(result);

    // Teste com zero
    result = ft_itoa(0);
    assert(strcmp(result, "0") == 0);
    free(result);

    // Teste com o menor inteiro (INT_MIN)
    result = ft_itoa(-2147483648); // Ou use INT_MIN se a macro estiver disponível
    assert(strcmp(result, "-2147483648") == 0);
    free(result);

    // Teste com o maior inteiro (INT_MAX)
    result = ft_itoa(2147483647); // Ou use INT_MAX se a macro estiver disponível
    assert(strcmp(result, "2147483647") == 0);
    free(result);

    // Teste com número de um dígito positivo
    result = ft_itoa(7);
    assert(strcmp(result, "7") == 0);
    free(result);

    // Teste com número de um dígito negativo
    result = ft_itoa(-9);
    assert(strcmp(result, "-9") == 0);
    free(result);

    printf("OK\n");
}

void    test_ft_split(void)
{
    printf("ft_split: ");
    
    char *s1;
    char c;
    char **splited_list;
    int i;

    // s1 nula
    s1 = NULL;
    c = ' ';
    splited_list = ft_split(s1, c);
    assert(splited_list == NULL);

    // s1 vazia
    s1 = ft_strdup("");
    c = ' ';
    splited_list = ft_split(s1, c);
    assert(splited_list[0] == NULL);
    free(s1);
    free(splited_list);

    // s1 com uma palavra
    s1 = ft_strdup("palavra");
    c = ' ';
    splited_list = ft_split(s1, c);
    assert(ft_strncmp(splited_list[0], "palavra", ft_strlen("palavra")) == 0);
    assert(splited_list[1] == NULL);
    free(s1);
    i = 0;
    while (splited_list[i] != NULL)
    {
        free(splited_list[i]);
        i++;
    }
    free(splited_list);

    // s1 com mais de duas palavras
    s1 = ft_strdup("palavra p4l4vr4");
    c = ' ';
    splited_list = ft_split(s1, c);
    assert(ft_strncmp(splited_list[0], "palavra", ft_strlen("palavra")) == 0);
    assert(ft_strncmp(splited_list[1], "p4l4vr4", ft_strlen("p4l4vr4")) == 0);
    assert(splited_list[2] == NULL);
    free(s1);
    i = 0;
    while (splited_list[i] != NULL)
    {
        free(splited_list[i]);
        i++;
    }
    free(splited_list);

    // s1 com mais de três palavras
    s1 = ft_strdup("palavra p4l4vr4 p@1454@");
    c = ' ';
    splited_list = ft_split(s1, c);
    assert(ft_strncmp(splited_list[0], "palavra", ft_strlen("palavra")) == 0);
    assert(ft_strncmp(splited_list[1], "p4l4vr4", ft_strlen("p4l4vr4")) == 0);
    assert(ft_strncmp(splited_list[2], "p@1454@", ft_strlen("p@1454@")) == 0);
    assert(splited_list[3] == NULL);
    free(s1);
    i = 0;
    while (splited_list[i] != NULL)
    {
        free(splited_list[i]);
        i++;
    }
    free(splited_list);

    // sem o caracter de split
    s1 = ft_strdup("palavra p4l4vr4 p@1454@");
    c = '*';
    splited_list = ft_split(s1, c);
    assert(ft_strncmp(splited_list[0], "palavra p4l4vr4 p@1454@", ft_strlen("palavra p4l4vr4 p@1454@")) == 0);
    assert(splited_list[1] == NULL);
    free(s1);
    i = 0;
    while (splited_list[i] != NULL)
    {
        free(splited_list[i]);
        i++;
    }
    free(splited_list);

    printf("OK \n");
}

void	test_ft_strtrim(void)
{
	printf("ft_strtrim: ");
	
	char *s1, *set;
	
	//parametros nulos
	s1 = NULL;
	set = NULL;
	s1 = ft_strtrim(s1, set);
	assert(s1 == NULL); 

	//parametros vazios
	s1 = ft_strdup("");
	set = ft_strdup("");
	ft_strtrim(s1, set);
	assert(s1[0] == '\0');

	//apenas set vazio
	s1 = ft_strdup("****");
	set = ft_strdup("*");
	char *result = ft_strtrim(s1, set);
	assert(ft_strncmp(result, "", sizeof(result)) == 0);

	//cenário perfeito para um set
	s1 = ft_strdup("**#*Hello*World*#**");
	set = ft_strdup("*");
	ft_strtrim(s1, set);
	assert(ft_strncmp(s1, "#*Hello*World*#", ft_strlen(s1)));

	//cenário perfeito para um set
	s1 = ft_strdup("**#*Hello*World*#**");
	set = ft_strdup("*#");
	ft_strtrim(s1, set);
	assert(ft_strncmp(s1, "Hello*World", ft_strlen(s1)));

	printf("OK \n");
	free(s1);
	free(set);
}

void	test_ft_strjoin(void)
{
	printf("ft_strjoin: ");
	char *s1, *s2;

	//parametros nulos
	s1 = NULL;
	s2 = NULL;
	ft_strjoin(s1, s2);
	assert(s1 == NULL);

	//parametros vazios
	s1 = ft_strdup("");
	s2 = ft_strdup("");
	ft_strjoin(s1, s2);
	assert(s1[0] == '\0');

	//vetor de caracteres
	char s1_not_str[] = {'N', 'O', 'T'};
	char s2_not_str[] = {'S', 'T', 'R', 'I', 'N', 'G'};
	ft_strjoin(s1_not_str, s2_not_str);
	assert(s1_not_str); // Comportamento indefinido

	//cenario perfeito
	s1 = ft_strdup("Hello");
	s2 = ft_strdup("World");
	ft_strjoin(s1, s2);
	assert(ft_strncmp(s1, "Hello World", sizeof(s1))); 

	printf("OK \n");
	free(s1);
	free(s2);
}

void    test_ft_substr(void)
{
    printf("ft_substr: ");
    char    *sub;
    char    s[] = "Hello World"; // len 11

    // Teste 1: Substring no meio
    sub = ft_substr(s, 6, 5); // "World"
    assert(sub != NULL);
    assert(sub[0] == 'W');
    assert(sub[4] == 'd');
    assert(sub[5] == '\0');
    assert(strlen(sub) == 5);
    free(sub);

    // Teste 2: Substring do início
    sub = ft_substr(s, 0, 5); // "Hello"
    assert(sub != NULL);
    assert(sub[0] == 'H');
    assert(sub[4] == 'o');
    assert(sub[5] == '\0');
    assert(strlen(sub) == 5);
    free(sub);

    // Teste 3: Substring até o final, 'len' grande
    sub = ft_substr(s, 6, 100); // "World" (até o final de s)
    assert(sub != NULL);
    assert(sub[0] == 'W');
    assert(sub[4] == 'd');
    assert(sub[5] == '\0');
    assert(strlen(sub) == 5);
    free(sub);

    // Teste 4: 'start' maior que o comprimento da string
    sub = ft_substr(s, 20, 5); // "" (string vazia)
    assert(sub != NULL);
    assert(sub[0] == '\0');
    assert(strlen(sub) == 0);
    free(sub);

    // Teste 5: 'len' menor que o restante disponível
    sub = ft_substr(s, 0, 3); // "Hel"
    assert(sub != NULL);
    assert(sub[0] == 'H');
    assert(sub[2] == 'l');
    assert(sub[3] == '\0');
    assert(strlen(sub) == 3);
    free(sub);

    // Teste 6: String vazia como entrada
    char empty_s[] = "";
    sub = ft_substr(empty_s, 0, 5); // ""
    assert(sub != NULL);
    assert(sub[0] == '\0');
    assert(strlen(sub) == 0);
    free(sub);

    // Teste 7: start no final da string
    sub = ft_substr(s, 11, 5); // "" (string vazia, porque start é o '\0')
    assert(sub != NULL);
    assert(sub[0] == '\0');
    assert(strlen(sub) == 0);
    free(sub);

    printf("OK \n");
}

void	test_ft_strdup(void)
{
	printf("ft_strdup: ");
	char	*p;
	char	str[] = "teste";

	p = ft_strdup(str);
	if (!p)
	{
		assert(p == NULL);
		return ;
	}
	assert(p[0] == 't');
	assert(p[4] == 'e');
	assert(p[5] == '\0');
	printf("OK \n");
}

void	test_ft_calloc(void)
{
	printf("ft_calloc: ");
	int	*i;

	i = ft_calloc(3, sizeof(int));
	if (!i)
	{
		assert(i == NULL);
		return ;
	}
	i[0] = 1;
	i[1] = 2;
	assert(i[0] == 1);
	assert(i[1] == 2);
	assert(i[2] == 0);
	printf("OK \n");
}

void	test_ft_atoi(void)
{
	// Definições das strings de teste (assumindo que você as tenha definido antes)
	char s1[] = "0";
	char s2[] = "0123";
	char s3[] = "abc0123";
	char s4[] = "-abc0123";
	char s5[] = "  \t\n\r\f\v123";
	char s6[] = "  -456";
	char s7[] = "+789";
	char s8[] = "123teste";
	char s9[] = "  \t\n\r\f\v";
	char s10[] = "";
	char s11[] = "-2147483648";
	char s12[] = "2147483647";
	char s13[] = "999999999999";
	char s14[] = "-999999999999";
	char s15[] = "++123";
	char s16[] = "--456";
	char s17[] = "12-34";

	// Testes:
	assert(ft_atoi(s1) == 0);
	assert(ft_atoi(s2) == 123);
	assert(ft_atoi(s3) == 0); // atoi para ao encontrar 'a'
	assert(ft_atoi(s4) == 0); // atoi para ao encontrar 'a' após o sinal
	assert(ft_atoi(s5) == 123);
	assert(ft_atoi(s6) == -456);
	assert(ft_atoi(s7) == 789);
	assert(ft_atoi(s8) == 123); // atoi para ao encontrar 't'
	assert(ft_atoi(s9) == 0);
	assert(ft_atoi(s10) == 0);
	assert(ft_atoi(s11) == INT_MIN); // Valor mínimo de int
	assert(ft_atoi(s12) == INT_MAX); // Valor máximo de int
	assert(ft_atoi(s13) == INT_MAX); // Overflow positivo
	assert(ft_atoi(s14) == INT_MIN); // Overflow negativo
	assert(ft_atoi(s15) == 0); // Múltiplos sinais (o padrão é parar no segundo)
	assert(ft_atoi(s16) == 0); // Múltiplos sinais (o padrão é parar no segundo)
	assert(ft_atoi(s17) == 12); // Sinal no meio da string (atoi para antes)
}

void	test_ft_strstr(void)
{
	printf("ft_strstr: ");
	char s1[] = "foo bar baz";
	char s2[] = "bar";

	char s2_empty[] = "";
	char *ret = ft_strstr(s1, s2_empty);
	assert(ret == s1);

	char s1_empty[] = "";
	ret = ft_strstr(s1_empty, s2);
	assert(ret == NULL);

	ret = ft_strstr(s1, s2);
	assert(ret == &s1[4]);

	char *s2_diff = "xyz";
	ret = ft_strstr(s1, s2_diff);
	assert(ret == NULL);

	ret = ft_strstr(s1_empty, s2_empty);
	assert(ret == s1_empty);
	printf("OK \n");
}

void	test_ft_memcmp(void)
{
	printf("ft_memcmp: ");
	char s1[] = "teste1";
	char s2[] = "teste3";

	int cmp = ft_memcmp(s1, s2, 5);
	assert(cmp == 0);

	cmp = ft_memcmp(s1, s2, 6);
	assert(cmp == -2);

	cmp = ft_memcmp(s2, s1, 6);
	assert(cmp == 2);

	// ft_memcmp lê até o len passsado, sem considerar o \0
	cmp = ft_memcmp(s1, s2, 8);
	assert(cmp == -2);
	printf("OK \n");
}

void	test_ft_memchr(void)
{
	printf("ft_memchr: ");
	char s1[] = "teste1";
	char c = 't';

	char *occ = (char *) ft_memchr(s1, c, sizeof(s1));
	assert(occ == &s1[0]);

	c = 's';
	occ = (char *) ft_memchr(s1, c, sizeof(s1));
	assert(occ == &s1[2]);

	c = 'x';
	occ = ft_memchr(s1, c, sizeof(s1));
	assert(occ == NULL);

	printf("OK \n");
}

void    test_ft_strncmp(void)
{
    printf("ft_strncmp: ");
    char s1[] = "teste1";
    char s2[] = "teste3";
    char s3[] = "teste";
    char s4[] = "test";
    char s5[] = ""; // String vazia

    int cmp;

    // Teste 1: Comparar partes iguais
    cmp = strncmp(s1, s2, 5);
    assert(cmp == 0);

    // Teste 2: Comparar strings diferentes no final
    cmp = strncmp(s1, s2, 6);
    assert(cmp == -2);

    // Teste 3: Comparar strings diferentes no final (ordem inversa)
    cmp = strncmp(s2, s1, 6);
    assert(cmp == 2);

    // Teste 4: Comparar strings de tamanhos diferentes, prefixo igual
    cmp = strncmp(s1, s3, 5);
    assert(cmp == 0);

    // Teste 5: Comparar strings de tamanhos diferentes, prefixo igual, mas strlen de s3 é menor que s1
    cmp = strncmp(s3, s1, 6); // Compara "teste\0" com "teste1"
    assert(cmp < 0); // Esperado que 's3' seja menor devido ao '\0'

    // Teste 6: Comparar prefixos curtos iguais
    cmp = strncmp(s1, s2, 3);
    assert(cmp == 0);

    // Teste 7: Comparar com len=0
    cmp = strncmp(s1, s2, 0);
    assert(cmp == 0);

    // Teste 8: Comparar com uma string mais curta (s4 = "test")
    cmp = strncmp(s1, s4, 4);
    assert(cmp == 0);

    // Teste 9: Comparar com uma string mais curta, len passa do fim
    cmp = strncmp(s1, s4, 5); // Compara "teste" com "test\0"
    assert(cmp > 0); // Esperado que 's1' seja maior que 's4' devido ao '\0'

    // Teste 10: Comparar com strings vazias
    cmp = strncmp(s5, s5, 1);
    assert(cmp == 0);

    // Teste 11: Comparar string vazia com string não vazia
    cmp = strncmp(s5, s1, 1);
    assert(cmp < 0); // Esperado que '\0' seja menor que 't'

    // Teste 12: Comparar string não vazia com string vazia
    cmp = strncmp(s1, s5, 1);
    assert(cmp > 0); // Esperado que 't' seja maior que '\0'

    // Teste 13: Comparar com valores ASCII diferentes
    char s6[] = "abc";
    char s7[] = "abd";
    cmp = strncmp(s6, s7, 3);
    assert(cmp < 0); // 'c' < 'd'

    cmp = strncmp(s7, s6, 3);
    assert(cmp > 0); // 'd' > 'c'

    printf("OK \n");
}

void	test_ft_strrchr(void)
{
	printf("ft_strrchr: ");
	char str[] = "uma frase de teste";

	char *ptr_first_e = ft_strrchr(str, 'e');	
	assert(ptr_first_e == &str[17]);
	printf("OK \n");
}

void	test_ft_strchr(void)
{
	printf("ft_strchr: ");
	char str[] = "uma frase de teste";

	char *ptr_first_e = ft_strchr(str, 'e');	
	assert(ptr_first_e == &str[8]);

	char *ptr_first_diff = ft_strchr(str, 'x');	
	assert(ptr_first_diff == NULL);

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
    // Cenário 1: src maior que dstsize
    char src1[] = "um texto longo"; 
    char dst1[5]; 
    size_t len_src1 = ft_strlcpy(dst1, src1, sizeof(dst1));
    assert(dst1[0] == 'u');
    assert(dst1[3] == 't');
    assert(dst1[4] == '\0'); 
    assert(len_src1 == strlen(src1)); 
    
    // Cenário 2: dstsize = 0
    char src2[] = "abc"; 
    char dst2[5]; 
    size_t len_src2 = ft_strlcpy(dst2, src2, 0);
     assert(dst2[0] != 'a'); 
     assert(dst2[0] == '\0'); 
    assert(len_src2 == strlen(src2));
    
    // Cenário 3: dstsize = 1 (apenas espaço para \0)
    char src3[] = "hello";
    char dst3[5];
    size_t len_src3 = ft_strlcpy(dst3, src3, 1);
    assert(dst3[0] == '\0');
    assert(len_src3 == strlen(src3));
    
    // Cenário 4: src é string vazia
    char src4[] = ""; 
    char dst4[5] = "xxxxx"; 
    size_t len_src4 = ft_strlcpy(dst4, src4, sizeof(dst4));
    assert(dst4[0] == '\0'); 
    assert(len_src4 == strlen(src4)); 
    
    // Cenário 5: src cabe completamente e dstsize eh maior que strlen(src)
    char src5[] = "curto";
    char dst5[10]; 
    memset(dst5, 'Z', sizeof(dst5)); 
    size_t len_src5 = ft_strlcpy(dst5, src5, sizeof(dst5));
    assert(dst5[0] == 'c');
    assert(dst5[4] == 'o');
    assert(dst5[5] == '\0'); 
    assert(dst5[6] == 'Z'); 
    assert(len_src5 == strlen(src5)); 
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

	 // Teste 5: Ao invés de colocar o \0 no dim de dst, dá um comportamento indefinido.
    char dst_full_test[10];
    ft_memset(dst_full_test, 'r', 10); 
    len = ft_strlcat(dst_full_test, src, 5);
    assert(len == (size_t)5 + strlen(src));
	printf("OK \n");
}