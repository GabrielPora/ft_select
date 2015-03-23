#include "ft_select.h"

char *get_name(t_list *lc)
{
  t_list *tmp;

  tmp = lc;
  while (tmp != NULL)
    {
      if (tmp->indice & CURSOR)
	return (tmp->name);
      tmp = tmp->next;
    }
  return (NULL);
}

void put_help(void)
{
  put_command("cl", 0);
  printf("%s%s%s \n%s%s%s \n%s%s%s \n%s%s%s \n%s%s%s \n%s%s%s \n%s%s%s \n%s%s%s \n%s%s%s \n",
	 WHITE_BLUE, "Unknown", RESET, BLUE, "Directory", RESET, MAGENTA, "Link", RESET, BRUN,
	 "Pipe", RESET, GREEN, "Socket", RESET, BLUE_CYAN, "Block", RESET, BLUE_YELLOW,
	 "Special file", RESET, RED, "Executable", RESET, WHITE, "Regular file", RESET);
  printf("\n\n Select commands \n");
  printf(" A : Select all \n S : Search \n I : Get file info (if a file)\n");
  printf(" H : Help \n ");
}

void put_info(t_select *sl)
{
  struct stat buff;
  char *filename;

  filename = get_name(sl->lc);
  put_command("cl", 0);
  if ((lstat(filename, &buff)) != -1)
    {
      printf("filename   : %s%s%s\n", BOLD, filename, RESET);
      printf("filesize   : %s%d%s\n", BOLD, (int)buff.st_size, RESET);
    }
  else
    {
      printf("Not a existant file.\n");
    }
}
