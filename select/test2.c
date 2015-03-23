#include "ft_select.h"

int main(int argc, char **argv)
{
  struct stat buff;

  lstat("test.c", &buff);
  printf("%lu", strlen(WHITE_BLUE));
}
