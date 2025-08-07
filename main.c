#include "libft.h"

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int fd = open("teste.txt", O_RDONLY);
	char *linha = get_next_line(fd);
	printf("%s\n", linha);
	free(linha);

	linha = get_next_line(fd);
	printf("%s\n", linha);
	free(linha);

	return (0);
}