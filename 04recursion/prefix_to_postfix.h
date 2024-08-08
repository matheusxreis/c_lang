
#define MAXLENGTH 15
/* convert prefix to postfix string */
void convert (char *prefix, char *postfix);
/* discover if char is operator */
int is_operator (char op);
/* find the first prefix expression */
int find (char *str);

void substring (char *target, char *source, int from, int amount);
