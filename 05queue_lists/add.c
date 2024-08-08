
// SUM OF TWO LARGER NUMBERS
// EX: 888888889998989 + 881918290198291

#include"clinked_list.c"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// DECIMAL is the amount of decimal places to works with
// and it depends on amount of max decimal places from each 
// item to sum
// [45] + [31] = one decimal place
// [504] + [122] = two decimal place
#define DECIMAL 100000

// SIZE of each item
// consideing the number 99999
// if size is 5, the item is [99999]
// if the size is 2, the items are [99] [99] [9]
// if the size is 1, the item are [9] [9] [9] [9] [9]

#define WORD 5

// ======= ADDING RECURSIVELY 
void
sum_w_carry (node * n1, node * n2, node ** result, int carry)
{

  int number1 = n1->info.intInfo;
  int number2 = n2->info.intInfo;

  if (number1 == -1 && number2 == -1)
    {
      infotype n;
      n.utype = INT;
      n.info.intInfo = carry;
      if (n.info.intInfo != 0)
	{
	  push (result, n);
	}
      return;
    }

  //==Verifications for case n1 or n2 has more decimal cases

  node *next1 = (number1 == -1) ? n1 : n1->next;
  node *next2 = (number2 == -1) ? n2 : n2->next;

  int total =
    (number1 == -1 ? 0 : number1) + (number2 == -1 ? 0 : number2) + carry;

  //==

  infotype n;
  n.utype = INT;
  n.info.intInfo = total % DECIMAL;
  push (result, n);

  return sum_w_carry (next1, next2, result, total / DECIMAL);

}

void
sum (node * n1, node * n2, node ** result)
{

  return sum_w_carry (n1, n2, result, 0);

}

/// ========= READ INPUT ============== ///

void
getstr (char *str, char *temp)
{
  strcpy (temp, str);
  temp[WORD] = '\0';
}

void
read_numbers (node ** list1, node ** list2)
{

  //TODO: implement a function to read a string
  // and mapper it to a reversed list

  // -1 NEED TO BE INSERTED AT THE END
  infotype x;
  x.utype = INT;
  x.info.intInfo = -1;
  insert (list1, x);
  insert (list2, x);
};



int
main ()
{

  node *n1 = create ();
  node *n2 = create ();
  node *result = create ();


  //read_numbers(&n1, &n2);

  //print_list(&n1->next, &n1);
  //print_list(&n2->next, &n2);
  //return 0;
  // sum(n1->next, n2->next, &result);

  //printf("The result is:\n");
  //print_list(&result->next, &result);
  //printf("\n");

}
