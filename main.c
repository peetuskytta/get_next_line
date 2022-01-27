#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <time.h>

int	main(void)
{
	char		*line;
	int		fd;
	int		res;
	clock_t		start;
	clock_t		end;
	double		time;
	int		i;

//	fd = open("file1", O_RDONLY);
	fd = open("test_bible.txt", O_RDONLY);
//	fd = open("10_superlongsentence_no_newline.txt", O_RDONLY);
	start = clock();

	i = 0;
	while (1)
	{
		res = get_next_line(fd, &line);
		if (res <= 0)
		{
			line = NULL;
			printf("%d, %s\n", res, line);
			break ;
		}
		printf("%d, %s\n", res, line);
		free(line);
		++i;
	}
	end = clock();
	time = ((double) (end - start)) / CLOCKS_PER_SEC;
	printf("\nTime: %f\n", time);
	printf("\nLines read: %d\n", i);

	close(fd);
	return (0);
}
