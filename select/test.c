#include "ft_select.h"

int term_set(struct termios *term)
{
  char *name;

  term->c_lflag &= ~(ICANON);
  term->c_lflag &= ~(ECHO);
  //  term->c_lflag &= ~(ISIG);
  term->c_cc[VMIN] = 1;
  term->c_cc[VTIME] = 0;
  if (tcsetattr(0, TCSADRAIN, term))
    return (0);
  return (1);
}

int key_gestion(t_select *sl, char *buffer)
{
  if (buffer[0] == 4)
    return (0);
  if (buffer[0] == 27 && sl->enable & WIN_OK)
    direction_key(sl, buffer[2]);
  else if (buffer[0] == 32 && sl->enable & WIN_OK)
    select_arg(sl);
  else if (buffer[0] == 104 && sl->enable & WIN_OK)
    put_help();
  else if (buffer[0] == 105 && sl->enable & WIN_OK)	\
    put_info(sl);
  else if (buffer[0] == 115 && sl->enable & WIN_OK)
    {
      sl->enable += SEARCH;
      search_list(sl);
      print_list(*sl);
    }
  return (1);
}

int     voir_touche(t_select *sl)
{
  char     buffer[3];
  char *res;

  print_list(*sl);
  while (1)
    {
      bzero(buffer, 3);
      read(0, buffer, 3);
      if (!key_gestion(sl, buffer))
	return (0);
    }
  return (0);
}

int exit_select(struct termios *term)
{
  tcgetattr(0, term);
  term->c_lflag = (ICANON | ECHO);
  tcsetattr(0, 0, term);
  return (0);
}

int main(int argc, char **argv, char **env)
{
  t_select sl;
  struct termios term;
  char *name;
  char buff[2];

  if ((name = getenv("TERM")) == NULL)
   return (0);
  if (tgetent(NULL, name) == ERR)
    return (0);
  if (tcgetattr(0, &term) == -1)
    return (0);
  if (!term_set(&term))
    return (0);
  term_set(&term);
  signal_handler();
  sl = init_list(argc - 1, argv + 1);
  sl.term = term;
  if (sl.lc == NULL)
    return (exit_select(&term));
  select_tmp = &sl;
  sl.lc->indice = 1;
  voir_touche(&sl);
  return (0);
}
