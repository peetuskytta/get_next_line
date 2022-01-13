#include "get_next_line.h"
#include <stdio.h>

int main()
{
  char  *line;
  int   fd;
  int   ret;
  int   i;

  ret = 1;
  i = 0;
  fd = open("file1", O_RDONLY);

  printf("\n");
  printf("\033[0;34m------------------------------------\033[0m\n");

  while (ret == 1)
  {
    ret = get_next_line(fd, &line);
    if (ret == 0)
      break ;
    printf("line %d:\t\033[0;33m%s\033[0m", i, line);
    printf("\n\033[0;34m------------------------------------\033[0m\n");
    i++;
  }
  if (ret == 0)
  {
    printf("ret value: \033[0;32m%d\033[0m\t", ret);
    printf("Status:\033[0;32m\tEOF reached\033[0m\n");
    printf("\033[0;34m------------------------------------\033[0m\n\n");
  }
  else if (ret == -1)
  {
    printf("\nret value: \033[0;31m%d\033[0m\t", ret);
    printf("Status:\033[0;31m\tError\033[0m\n\n");
    printf("\n\033[0;34m------------------------------------\033[0m\n\n");
  }
  /*else
  {
    printf("\nret value: \033[0;32m%d\033[0m\t", ret);
    printf("\n\033[0;34m------------------------------------\033[0m\n\n");
  }*/
  
  close(fd);
  return (0);
}
