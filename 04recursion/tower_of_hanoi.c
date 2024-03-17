

#include <stdio.h>

void tower(int n, char from, char to, char aux) {
     
    if(n == 1) {
      /* Simple case, when only 1 disk */
      /* Move disk 1 from A to C, using B */
      printf("Moving disk 1 from rod %c to rod %c\n", from, to);
      return;
    }
    /* Recursive case */
    /* Move disks n-1 from A to B, using C */
    tower(n-1, from,aux, to);
    printf("Moving disk %d from rod %c to rod %c\n", n, from, to);

    tower(n-1, aux, to, from);
}

int main() {
  
  tower(4, 'A', 'C', 'B');
  return 1;
}
