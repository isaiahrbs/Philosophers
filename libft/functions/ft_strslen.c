#include "../inc/libft.h"

//* string search length
//* search for a certain word inside of a string and then return the index
//* of where it is, or returns the whole string length if nothing found

int ft_strslen(char *str, char c)
{
  int i;

  i = 0;
  while (str[i] != c)
    i++;
  return (i);
}
