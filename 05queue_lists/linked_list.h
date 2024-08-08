#include<stdlib.h>

#define INT 1
#define CHAR 2
#define LIST 3
#define STRING 4

typedef struct
{
  int utype;
  union
  {
    int intInfo;
    char charInfo;
    struct nodetype *listInfo;
    char *strInfo;
  } info;
} infotype;

typedef struct nodetype
{
  int utype;
  union
  {
    int intInfo;
    char charInfo;
    struct nodetype *listInfo;
    char *strInfo;
  } info;
  struct nodetype *next;
} node;


/*
 * The list itself;
 * The info field from this,
 * can be empty or keep things related
 * to the list like its size
 */

/*
 * Create the list
 */
node *create ();

node *createlist (int size, ...);
/*
 * @brief Copy a list
 * @param list The list to be copied
 */
node *copy (node * list);

/* OPERATIONS WHAT DOESNT MODIFY A LIST */
/*
 * @brief Returns void
 * @param list The list which apply the function
 * @param A struct to be filled with the first value from the list
 * */
void head (node * list, infotype * item);

/*
 * @brief Returns the list except the first item
 * @param list The list which apply the function
 * */
node *tail (node * list);

/*
 * @brief Returns the first element from the list
 * @param list The list which apply the function
 * */
node first (node * list);

/*
 * @brief Returns the next element from element passed
 * @param element The list element which apply the function
 * */
node next (node element);

/*
 * @brief Return the field info from element
 * @param element The list element which apply the function
*/

void info (node element, infotype * x);

/* @brief Returns the type from element
 * @param element The list element which apply the function
 */
int nodetype (node element);


/* @brief Returns the size from the list
 * @param list The list which apply the function
 */
int len (node * list);

/* @brief Concatenate 2 list and return it
 * @param l1 The first list which apply the function
 * @param l2 The second list which apply the function
 
*/
node *concat (node * l1, node * l2);

/* @brief Filter a element and returns a list with them
 * @param l1 The list which apply the function
 * @param elem The element which search 
*/
node *filter (node * l1, infotype elem);

/* @brief Fiilter a element and returns its NODE or NULL
 * @param l1 The list which apply the function
 * @param elem The element which search 
*/
node *find (node * l1, infotype elem);

/*  ======================= Operations which modify a list ========================*/

/*
 * @brief Inserts a element from start of the list
 * @param list The list element which apply the function
 * @param x The element to be inserted
 * */
void push (node ** list, infotype x);

/*
 * @brief Set a new info to index position from the list
 * @param list The list element which apply the function
 * @param index The index where the info must be inserted
 * @param info The element to be inserted
 */
void set (node ** list, int index, infotype info);


/*
 * @brief Returns a new list which x as head and list as tail
 * @param list The list element which apply the function
 * @param x The element to be inserted as head
 * */
node *addon (node * list, infotype x);

/*
 * @brief Inserts a element from end of the list
 * @param list The list element which apply the function
 * @param x The element to be inserted
 * */
void insert (node ** list, infotype x);

/*
 * @brief Remove a element from end of the list
 * @param list The list element which apply the function
 * @param index The element index to be removed
 * */
void remov (node ** list, int index);
/*
 * @brief Revert a list
 * @param list The list element which apply the function
*/
void reverse (node ** list);
