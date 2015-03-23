#include "ft_select.h"

void search_name(t_list *lc, char *buff)
{
  t_list *tmp;
  int t;

  tmp = lc;
  t = 0;
  while (tmp != NULL)
    {
      if ((tmp->s_len = ft_search_str(tmp->name, buff)))
	t = 1;
      tmp = tmp->next;
    }
  if (t == 0)
    put_command("bl", 0);
}

void move_cursor_search(t_select *sl, char *buff)
{
  t_list *tmp;

  tmp = sl->lc;
  while (tmp != NULL)
    {
      if (!strcmp(tmp->name, buff))
	break ;
      tmp = tmp->next;
    }
  if (tmp == NULL)
    return ;
  cursor_dele(sl);
  tmp->indice += 1;
}

void search_list(t_select *sl)
{
  char buff[3];
  char name[256];
  int i;

  i = 0;
  bzero(name, 256);
  printf("S : Search : \n");
  while (1)
    {
      bzero(buff, 3);
      read(0, buff, 3);
      put_command("cl", 0);
      if (isprint(buff[0]))
	{
	  name[i] = buff[0];
	  name[i + 1] = '\0';
	  i++;
	  search_name(sl->lc, name);
	}
      else if (buff[0] == 127 && i > 0)
	{
	  i--;
	  name[i] = '\0';
	  search_name(sl->lc, name);
	}
      else if (buff[0] == 10)
	{
	  move_cursor_search(sl, name);
	  break ;
	}
      print_list(*sl);
      printf("S : Search : %s\n", name);
    }
  sl->enable -= SEARCH;
}
