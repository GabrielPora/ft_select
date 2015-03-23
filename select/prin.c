#include "ft_select.h"

void print_name(t_list *lc)
{
  if (lc->indice & CURSOR)
    printf("\033[1m");
  if (lc->indice & SELECTED)
    printf("\033[7m");
  printf("%s", lc->color);
  printf("%s", lc->name);
  printf("\033[0m");
}

void print_search(t_list *lc)
{
  int i;

  write(1, INVERSE, strlen(INVERSE));
  write(1, lc->name, lc->s_len);
  write(1, RESET, strlen(RESET));
  write(1, lc->name + lc->s_len, lc->len - lc->s_len);
}

void print_list(t_select sl)
{
  int k;

  put_command("cl", 0);
  while (sl.lc != NULL)
    {
      if (sl.enable & SEARCH)
	print_search(sl.lc);
      else
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
