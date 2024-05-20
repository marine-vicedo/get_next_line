#include "get_next_line.h"

// Compile with:
//gcc -Wall -Werror -Wextra get_next_line.c get_next_line_utils.c main.c -D BUFFER_SIZE=42

int main(int ac, char **av)
{
	int		fd;
	char	*line;

	if (ac != 2)
	{
		printf("Usage: ./a.out file\n");
		return (1);
	}

	fd = open(av[1], O_RDONLY);
	while ((line = get_next_line(fd)))
	{
		printf("%s\n", line);
		free(line);
	}
	close(fd);
	return (0);
}