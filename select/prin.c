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

void print_name(t_list *lc)
{
  if (lc->indice & CURSOR)
    printf("\033[1m");
  if (lc->indice & SELECTED)
    printf("\033[7m");
  printf("%s", lc->name);
  if (lc->indice & CURSOR || lc->indice & SELECTED)
    printf("\033[0m");
}

void print_list(t_select sl)
{
  int k;

  put_command("cl", 0);
  while (sl.lc != NULL)
    {
      print_name(sl.lc);
      k = 0;
      if (sl.lc->next && (sl.lc->next->row == sl.lc->row))
	while (k < sl.sp[sl.lc->col] - sl.lc->len + 2)
	  {
	    printf(" ");
	    k++;
	  }
      else
	    printf("\n");
      sl.lc = sl.lc->next;
    }
}
