#include "get_next_line_bonus.h"

int	main(void)
{
	//gcc -Wall -Werror -Wextra *.c -D BUFFER_SIZE=42
	char *line1;
	char *line2;
	char *line3;

	int fd1 = open("files/file", O_RDONLY);
	int fd2 = open("files/multiples_lines", O_RDONLY);
	int fd3 = open("files/multiples_lines_with_nl", O_RDONLY);

	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);

	
	while (line1 || line2 || line3)
	{
		printf("%s", line1);
		printf("%s", line2);
		printf("%s", line3);
		free (line1);
		free (line2);
		free (line3);
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		line3 = get_next_line(fd3);
	}

	return (0);
}