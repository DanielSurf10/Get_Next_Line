# Get Next Line

Este projeto faz parte da trilha de fundamentos da instituição 42 e tem como objetivo criar uma função que recebe um descritor de arquivo (`fd`) e retorna a próxima linha desse arquivo.

## Descrição

A função `get_next_line` é responsável por ler um arquivo linha por linha, a cada chamada, retornando a próxima linha encontrada. Ela utiliza o descritor de arquivo fornecido para realizar a leitura.

## Como usar

1. Clone este repositório em sua máquina local.
2. Compile o programa utilizando o comando `gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c main.c -o gnl`.
3. Execute o programa com o comando `./gnl <arquivo>` substituindo `<arquivo>` pelo caminho do arquivo que deseja ler.
4. A função `get_next_line` será chamada repetidamente até que todas as linhas do arquivo tenham sido lidas.

## Exemplo de uso

```c
#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char *argv[])
{
	int		fd;
	char	*line;

	if (argc < 2)
	{
		printf("Forneca um arquivo como parametro\n");
		return (1);
	}
	else if (argv > 2)
	{
		printf("Numero invalido de argumentos!\n");
		return (1);
	}

	fd = open("arquivo.txt", O_RDONLY);

	while ((line = get_next_line(fd)) != NULL)
	{
		// Faça algo com a linha lida
		printf("%s\n", line);
		free(line);
	}

	close(fd);
	return 0;
}
```

## Observações

- Certifique-se de fornecer o caminho correto para o arquivo que deseja ler.
- Lembre-se de fechar o descritor de arquivo após a leitura ser concluída.
- A função `get_next_line` retorna `NULL` quando não há mais linhas para ler ou ocorre um erro.
