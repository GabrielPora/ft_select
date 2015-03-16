void sig_window(int signo)
{
  signo = SIGWINCH ? print_arg(void) : 0;
  signo = SIGWINCH ? 
}

void signal_handler(void)
{
  signal(SIGWINCH, sig_window);
  signal(SIG
}
