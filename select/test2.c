#include "ft_select.h"

int main(int argc, char **argv)
{
  char *buffer;
  int fd_tty;

  printf("%lU\n", strlen("\033[31;1m"));
  buffer = "\033[31;1mrouge en gras \033[0m normal";
  write(1, buffer, strlen(buffer));
}
