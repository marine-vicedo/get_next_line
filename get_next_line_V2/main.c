#include "get_next_line.h"

int	main(void)
{
	//gcc -Wall -Werror -Wextra *.c -D BUFFER_SIZE=42
	char *line;

	//int fd = open("files/file", O_RDONLY);
	//int fd = open("files/empty", O_RDONLY);
	//int fd = open("files/nl", O_RDONLY);
	//int fd = open("files/multiples_lines", O_RDONLY);
	//int fd = open("files/multiples_lines_with_nl", O_RDONLY);
	//int fd = open("files/file_write", O_WRONLY);
	int fd = open("files/no_right", O_RDONLY);

	line = get_next_line(fd);

	while (line)
	{
		printf("%s", line);
		free (line);
		line = get_next_line(fd);
	}

	return (0);
}