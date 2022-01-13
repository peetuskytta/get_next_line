#include "get_next_line.h"
#include <stdio.h>

int main(int ac, char **av)
{
  char  *line;
  int   fd;
  int   ret;
  int   line_count;
  int   k;

  k = 1;
  printf("\n");
  printf("\033[0;34m------------------------------------\033[0m\n");
  while (k <= ac)
  {
    line_count = 1;
    ret = 1;
    fd = open(av[k], O_RDONLY);
    while (ret == 1)
    {
      if (fd == -1)
        return (0);
      ret = get_next_line(fd, &line);
      if (ret == 0)
      {
        printf("ret value: \033[0;32m%d\033[0m\t", ret);
        printf("Status:\033[0;32m\tEOF reached\033[0m\n");
        printf("\033[0;34m------------------------------------\033[0m\n\n");
        break ;
      }
      else if (ret == -1)
      {
        printf("\nret value: \033[0;31m%d\033[0m\t", ret);
        printf("Status:\033[0;31m\tError\033[0m\n");
        printf("\n\033[0;34m------------------------------------\033[0m\n");
      }
      else
      {
        printf("line %d:\t\033[0;33m%s\033[0m", line_count, line);
        printf("\n\033[0;34m------------------------------------\033[0m\n");
        ++line_count;
      }
    }
    ++k;
  }
  close(fd);
  printf("\n");
  return (0);
}
