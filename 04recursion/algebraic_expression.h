/*
 * Uma expressão é um termo seguido por sinal de mais, seguido por um termo, ou um termo isolado
 * Um termo é um fator seguido por um asterisco, seguido por um fator, ou um fator isolado
 * Um fator é uma letra ou uma expressão entre parênteses
 *
 * A -> é um fator, que é um termo (que pode ser um fator isolado), que é uma expressão (que pode ser um termo isolado);
 * A + B -> é uma expressão;
 * A * B -> é um termo, e portanto uma expressão
 * A * B + C, é uma expressão somente
 * A * (B + C), é uma epxressão, mas não um fator
 */


#define TRUE 1
#define FALSE 0
#define MAXSTRINGSIZE 100


/* get next symbol on string */
char getsymb(char * str, int lenght, int* currentpos);

/* read string*/

void readstr(char* str, int *length);

/* verify if expression is valid */
int expr(char* str, int lenght, int* currentPos);

/* verify if term is valid */
int term(char* str, int length, int* currentPos);

/* verify if factor is valid */
int factor(char* str, int length, int* currentPos);

