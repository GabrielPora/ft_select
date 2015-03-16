#include "ft_select.h"

void print_space(int sp)
{
  char *buff;
  int i;

  i = 0;
  buff = (char*)malloc(sizeof(char) * sp + 1);
  bzero(buff, sp);
  while (i < sp)
    {
      buff[i] = ' ';
      i++;
    }
  printf("%s", buff);
  free(buff);
}

void print_list(t_select sl)
{
  int sp;

  while (sl.lc != NULL)
    {
      sp = sl.sp[sl.lc->col] - sl.lc->len + 2;
      printf("%s", sl.lc->name);
      while (sp > 0)
	{
	  printf(" ");
	  sp--;
	}
      if (sl.lc->next && sl.lc->next->row == sl.lc->row + 1)
	printf("\n");
      sl.lc = sl.lc->next;
    }
}
