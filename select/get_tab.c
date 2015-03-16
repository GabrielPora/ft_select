t_list ***get_tab(int argc, char **argv, int max_row, int max_col)
{
  t_list ***tb;
  int i;
  int j;

  tb = (t_list***)malloc(sizeof(t_list**) * max_col + 1);
  i = 0;
  while (i < max_col)
    {
      tb[i] = (t_list**)malloc(sizeof(t_list*) * max_row + 1);
      j = 0;
      while (j < max_row)
	{
	  tb[i][j] = (t_list*)malloc(sizeof(t_list));
	  tb[i][j]->name = *argv;
	  tb[i][j]->len = ft_strlen(*argv);
	  tb[i][j]->indice = 0;
	  j++;
	  argv++;
	}
      tb[i][j] = NULL;
      i++;
    }
  tb[i] = NULL;
}

void get_space_number(t_select *sl)
{
  int i;
  int j;
  int k;

  i = 0;
  while (
}
t_select get_line_colum(int argc, char **argv)
{
  t_select sl;
  struct winsize ws;

  if ((sl.max_col = get_column(argc, &ws)) == 0)
    {
      sl.lc = NULL;
      return (sl);
    }
  sl.max_row = ws.ws_row;
  sl.col_len = ws.ws_col;
  list.argc = argc;
  sl.tb = get_tab(argc, argv, list.max_row, list.max_col);
  sl.sp = (int*)malloc(sizoef(int) * sl.col_len);
  get_space_number(&sl);
  check_window_size(list);
}
