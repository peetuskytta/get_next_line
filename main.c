#include "get_next_line.h"
#include <stdio.h>

int main()
{
  char  *line;
  int   fd1;
  
    fd1 = open("file1", O_RDONLY);
    printf("fd1 value: %d\n", fd1);
    get_next_line(fd1, &line);
    printf("\n------------------------------------");
    printf("\nin main\n");
    printf("returned line 1 in main: \t%s\n", line);
    printf("------------------------------------");
    printf("\n\n");
    get_next_line(fd1, &line);
    printf("\n------------------------------------");
    printf("\nin main\n");
    printf("returned line 2 in main: \t%s\n", line);
    printf("------------------------------------");
    printf("\n\n");
    get_next_line(fd1, &line);
    printf("\n------------------------------------");
    printf("\nin main\n");
    printf("returned line 3 in main: \t%s\n", line);
    printf("------------------------------------");
    printf("\n\n");
    get_next_line(fd1, &line);
    printf("\n------------------------------------");
    printf("\nin main\n");
    printf("returned line 4 in main: \t%s\n", line);
    printf("------------------------------------");
    printf("\n\n");

        get_next_line(fd1, &line);
    printf("\n------------------------------------");
    printf("\nin main\n");
    printf("returned EOF: \t%s\n", line);
    printf("------------------------------------");
    printf("\n\n");

    printf("fd1: %d", fd1);

    close(fd1);
  return (0);
}
