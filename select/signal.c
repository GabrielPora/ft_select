#include "ft_select.h"

void sig_cont(int signo)
{
  if (signo == SIGCONT)
    {
      term_set(&(select_tmp->term));
      window_resize(select_tmp);
    }
}

void sig_winch(int signo)
{
  if (signo == SIGWINCH)
      window_resize(select_tmp);
}

void signal_handler(void)
{
  signal(SIGWINCH, sig_winch);
  signal(SIGCONT, sig_cont);
}
