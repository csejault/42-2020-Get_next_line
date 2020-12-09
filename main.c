
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main ( int ac, char **av)
{
	int fd;
	int fd2;
	int ret;
	char *line;
	char *line2;

	ret = 0;

	if (ac == 2)
	{
		if ( -1 == (fd = open(av[1], O_RDONLY)))
		{
			printf("Open error\n");
			return (1);
		}

	}
	else if (ac == 3)
	{
		if ( -1 == (fd = open(av[1], O_RDONLY)))
		{
			printf("Open error\n");
			return (1);
		}
		if ( -1 == (fd2 = open(av[2], O_RDONLY)))
		{
			printf("Open error\n");
			return (1);
		}

		ret = 1;
		while (ret)
		{
			if ((ret = get_next_line(fd, &line)))
				printf("%d---->LINE ===%s\n", ret, line);
			if ((ret = get_next_line(fd2, &line2)))
				printf("%d---->LINE2 ===%s\n", ret, line2);
		}
				printf("%d---->LINE ===%s\n", ret, line);
				printf("%d---->LINE2 ===%s\n", ret, line2);

	}
	else if ( -1 == (fd = open("file_to_read.txt", O_RDONLY)))
	{
		printf("Open error\n");
		return (1);
	}
	while ((ret = get_next_line(fd, &line)))
		printf("%d---->LINE ===%s\n", ret, line);
	printf("%d OUTSIDE ---->LINE ===%s\n", ret, line);
	//get_next_line(fd, &line);
	//printf(" ---->LINE === %s\n", line);
	//	get_next_line(fd2, &line);
	//	printf(" ---->LINE === %s\n", line);
	//	get_next_line(fd, &line);
	//	printf(" ---->LINE === %s\n", line);
	//	get_next_line(fd2, &line);
	//	printf(" ---->LINE === %s\n", line);



	close (fd);
	free (line);
}

