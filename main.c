
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main ()
{
	int fd;
	int fd2;
	char *line =  malloc(50);

	if ( -1 == (fd = open("file_to_read.txt", O_RDONLY)))
	{
		printf("Open error\n");
		return (1);
	}
	if ( -1 == (fd2 = open("file_to_read2.txt", O_RDONLY)))
	{
		printf("Open error\n");
		return (1);
	}
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
	printf("%d",get_next_line(fd, &line));
	printf("---->LINE === %s\n", line);
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

