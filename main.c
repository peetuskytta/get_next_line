#include "get_next_line.h"
#include <stdio.h>

int main()
{
int     fd1;
int     fd2;
char    *line;

fd1 = open("file1", O_RDONLY);
fd2 = open("file2", O_RDONLY);
get_next_line(fd1, &line);
printf("\033[0;31m%s\033[0m", line);
get_next_line(fd2, &line);
printf("\033[0;32m%s\033[0m", line);
get_next_line(fd1, &line);
printf("\033[0;31m%s\033[0m", line);
get_next_line(fd2, &line);
printf("\033[0;32m%s\033[0m", line);
get_next_line(fd1, &line);
printf("\033[0;31m%s\033[0m", line);
get_next_line(fd2, &line);
printf("\n\033[0;32m%s\n\033[0m", line);

close(fd1);
close(fd2);
return (0);
}