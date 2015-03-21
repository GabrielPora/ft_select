#include "ft_select.h"

void sig_cont(int signo)
{
  if (signo == SIGCONT)
    {
      term_set(&(tmp->term));
    }
}

void sig_winch(int signo)
{
  if (signo == SIGWINCH)
      window_resize(select_tmp);
  print_list(*select_tmp);
}
