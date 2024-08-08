#include<stdio.h>
#include<stdarg.h>
#include <stdlib.h>
#include"linked_list.h"



void
set_info (infotype * t1, infotype * t2)
{

  t1->utype = t2->utype;

  switch (t2->utype)
    {
    case INT:
      t1->info.intInfo = t2->info.intInfo;
      break;
    case CHAR:
      t1->info.charInfo = t2->info.charInfo;
      break;
    case LIST:
      t1->info.listInfo = t2->info.listInfo;
      break;
    case STRING:
      t1->info.strInfo = t2->info.strInfo;
      break;
    }
}

int
compareinfo (infotype * t1, infotype * t2)
{

  switch (t2->utype)
    {
    case INT:
      return t1->info.intInfo == t2->info.intInfo;
      break;
    case CHAR:
      return t1->info.charInfo == t2->info.charInfo;
      break;
    case LIST:
      return t1->info.listInfo == t2->info.listInfo;
      break;
    case STRING:
      return t1->info.strInfo == t2->info.strInfo;
      break;
    };

  return 0;
}

node *
create ()
{
  node *n = (node *) malloc (sizeof (node));
  n = NULL;
  return n;
}

node *
createlist (int size, ...)
{

  va_list argptr;
  va_start (argptr, size);

  node *n = create ();

  for (int i = 0; i < size; i++)
    {
      insert (&n, *va_arg (argptr, infotype *));
    }
  va_end (argptr);
  return n;
}

/// (1, 2, null)
/// *null
/// *n = 2
/// *n.next = null
/// return (2, null)
/// *n = 1
/// *n.next = (2, null)
///  (1, 2, null)

node *
copy (node * list)
{

  if (list == NULL)
    {
      return NULL;
    }
  node *n = (node *) malloc (sizeof (node));
  *n = *list;
  n->next = copy (tail (list));
  return n;
}

void
info (node element, infotype * x)
{
  set_info (x, (infotype *) & element);
}

node
next (node element)
{
  return *element.next;
}

node
first (node * list)
{
  if (list == NULL)
    {
      printf ("The list is empty (first method)");
    }
  return *list;
}

void
head (node * list, infotype * x)
{

  if (list == NULL)
    {
      printf ("The list is empty (head method)\n");
      return;
    }

  set_info (x, (infotype *) list);
}

node *
tail (node * list)
{
  if (list == NULL)
    {
      printf ("The list is empty (tail method)\n");
      return list;
    }
  return (list->next);
}

int
nodetype (node element)
{
  return element.utype;
}

// ex. 4.2.24n
int
len (node * list)
{

  if (list == NULL)
    {
      return 0;
    }

  return 1 + len (tail (list));
}


node *
filterlist (node * list, node * result, infotype elem)
{
  if (list == NULL)
    {

      if (!compareinfo ((infotype *) result, &elem))
	{
	  return NULL;
	}
      return result;
    }

  if (compareinfo ((infotype *) list, &elem))
    {
      result = list;
      result->next = filterlist (list->next, result->next, elem);
      return result;
    }

  return filterlist (list->next, result, elem);
}

node *
filter (node * l1, infotype elem)
{
  node *n = (node *) malloc (sizeof (node));
  //TODO: try filter without copy
  return filterlist (copy (l1), n, elem);
};

node *
find (node * l1, infotype elem)
{

  if (l1 == NULL)
    {
      return l1;
    }

  if (compareinfo ((infotype *) l1, &elem))
    {
      return l1;
    }

  return find (l1->next, elem);
}


//========================
node *
reverse_with_head (node * tail, node * head)
{

  if (head == NULL)
    {
      return tail;
    }

  node *list = head->next;
  head->next = tail;

  return reverse_with_head (head, list);
}

// ex 4.2.3d
void
reverse (node ** list)
{
  *list = reverse_with_head (NULL, *list);
}

// ec 4.2.3b
node *
concat (node * l1, node * l2)
{

  if (l1 == NULL && l2 == NULL)
    {
      return NULL;
    }

  if (l1 == NULL)
    {
      l1 = l2;
      return l1;
    }

  l1->next = concat (l1->next, l2);

  return l1;

}

void
push (node ** list, infotype x)
{

  node *n = (node *) malloc (sizeof (node));
  set_info ((infotype *) n, &x);

  if (!n)
    {
      printf ("ops");
    }
  n->next = *list;

  *list = n;
}

/*
 *  (10, 20, 30, 40)
 *  set(list, 4, 's')
 *   set((20, 30, 40), 3, 's');
 *    set((30, 40), 2, 's');
 *     set((40), 1, 's')
 *      
 *
 */
void
set (node ** list, int index, infotype info)
{
  if (list == NULL)
    {
      printf ("Index out of bounds (set)\n");
      exit (1);
    }
  if (index < 1)
    {
      set_info ((infotype *) * list, &info);
      return;
    }
  set (&(*list)->next, index - 1, info);
}

node *
addon (node * list, infotype x)
{

  node *n = (node *) malloc (sizeof (node));
  set_info ((infotype *) n, &x);
  n->next = list;
  return n;
}


// ex 4.2.3a
void
insert (node ** list, infotype x)
{

  if (*list == NULL)
    {
      push (list, x);
      return;
    }

  insert (&(*list)->next, x);
}

/* TODO: handle with segment fault and 
 * refactor set method too
 * */
void
remov (node ** list, int index)
{

  if (list == NULL)
    {
      printf ("Index out of bounds (set)\n");
      exit (1);
    }
  if (index < 1)
    {
      *list = (*list)->next;
      return;
    };

  remov (&(*list)->next, index - 1);
};

///// ============================= print list

void
print_list (node ** list)
{

  if (*list == NULL)
    {
      return;
    }

  int type = (*list)->utype;

  if (type == INT)
    {
      printf (" %d ", (*list)->info.intInfo);
    }
  else if (type == STRING)
    {
      printf (" %s ", (*list)->info.strInfo);
    }
  else if (type == CHAR)
    {
      printf (" %c ", (*list)->info.charInfo);
    }
  else if (type == LIST)
    {
      printf (" ( ");
      print_list (&(*list)->info.listInfo);
      printf (" ) ");
    }

  node *rest = tail (*list);
  print_list (&rest);

}
