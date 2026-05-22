#include <stdio.h>
#include <stdlib.h>

extern char* infixToPostfix(char* infix, char* postfix);
extern int evalPostfix(char* postfix);
extern int precedence(char op);