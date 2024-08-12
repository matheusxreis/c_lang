#include<stdio.h>
#include"repeat.c"

int
main ()
{


  int list[16] = { 14, 15, 4, 9, 7, 18, 3, 5, 16, 4, 20, 17, 9, 14, 5, 4 };

  find_repeat_elements (list, sizeof (list) / sizeof (int));


}
