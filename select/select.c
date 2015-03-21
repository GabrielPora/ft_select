#include "ft_select.h"

void select_arg(t_select *sl)
{
  t_list *tmp;

  tmp = sl->lc;
  while (tmp != NULL)
    {
      if (tmp->indice & CURSOR)
	break ;
      tmp = tmp->next;
    }
  if (tmp->indice & SELECTED)
    tmp->indice -= 3;
  else
    tmp->indice += 1;
  if (tmp->next == NULL)
    sl->lc->indice += 1;
  else
    tmp->next->indice += 1;
}
