#include<stdlib.h>

#define INT 1
#define CHAR 2
#define LIST 3
#define STRING 4






typedef struct {
  int utype;
  union { 
    int intInfo;
    char charInfo;
    struct nodetype* listInfo;
    char* strInfo;
  } info;
} infotype;

typedef struct nodetype {
  int utype;
   union {
    int intInfo;
    char charInfo;
    struct nodetype* listInfo;
    char* strInfo;
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
node* create();

/* OPERATIONS WHAT DOESNT MODIFY A LIST */
/*
 * @brief Returns void
 * @param list The list which apply the function
 * @param A struct to be filled with the first value from the list
 * */
void head(node* list, infotype* item);

/*
 * @brief Returns the list except the first item
 * @param list The list which apply the function
 * */
node* tail(node* list);

/*
 * @brief Returns the first element from the list
 * @param list The list which apply the function
 * */
node first(node* list);

/*
 * @brief Returns the next element from element passed
 * @param element The list element which apply the function
 * */
node next(node element);

/*
 * @brief Return the field info from element
 * @param element The list element which apply the function
*/

void info(node element, infotype *x); 

/* @brief Returns the type from element
 * @param element The list element which apply the function
 */
int nodetype(node element);


/* Operations which modify a list */

/*
 * @brief Inserts a element from start of the list
 * @param list The list element which apply the function
 * @param x The element to be inserted
 * */
void push(node** list, infotype x);


