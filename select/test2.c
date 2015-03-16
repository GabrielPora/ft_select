#include "ft_select.h"

t_select *tmp2;

int main(int argc, char **argv)
{
  int tableau[argc - 1];
  int i = 0;

  while (i < argc -1)
    {
      tableau[i] = 5;
      printf("%d\n", tableau[i]);
      i++;
    }
}
