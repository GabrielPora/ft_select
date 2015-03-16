#include <termios.h>
#include <sys/ioctl.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
  struct winsize ws;
  int i = 0;

  ioctl(0, TIOCGWINSZ, &ws);
  printf("row %d col %d\n", ws.ws_col, ws.ws_row);
  while (i < ws.ws_row)
    {
      printf("\n");
      i++;
    }
  printf("\n");
}
