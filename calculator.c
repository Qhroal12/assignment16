#include "calculator.h"
#include "ArrayStack.h"

char* infixToPostfix(char* infix, char* postfix) {
	int j = 0;
	ArrayStack* opStack = createArrayStack(100, CHARACTER);

	for (int i = 0; infix[i] != NULL; i++) {
		if (infix[i] >= '0' && infix[i] <= '9') {
			postfix[j] = infix[i];
			j++;
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {

			while (!emptyArrayStack(opStack)) {
				stackElement prevOp = peekArrayStack(opStack);

				if (precedence(infix[i]) <= precedence(prevOp.operator)) {
					postfix[j] = popArrayStack(opStack).operator;
					j++;
				}
				else if (precedence(infix[i]) > precedence(prevOp.operator)) {
					break;
				}
			}
			pushArrayStack(opStack, (stackElement) { infix[i] });
		}
		else if (infix[i] == '(') {
			pushArrayStack(opStack, (stackElement) { infix[i] });
		}
		else if (infix[i] == ')') {
			do
			{
				stackElement prevOp = popArrayStack(opStack);

				if (prevOp.operator != '(') {
					postfix[j] = prevOp.operator;
					j++;
				}
				if (prevOp.operator == '(') {
					break;
				}
			} while (!emptyArrayStack(opStack));
		}
		else
			continue;

		printf("Postfix : ");
		for (int k = 0; k < j; k++) {
			printf("%c ", postfix[k]);
		}
		printf("| ");
		printArrayStack(opStack);
	}

	while (!emptyArrayStack(opStack)) {
		postfix[j] = popArrayStack(opStack).operator;
		j++;
	}
	////////////////////////////////마지막 후위 표기/////////////////////
	printf("Postfix : ");
	for (int k = 0; k < j; k++) {
		printf("%c ", postfix[k]);
	}
	printf("| ");
	printArrayStack(opStack);

	/////////////////////////////////Result 출력/////////////////////////
	printf("Result : ");
	for (int k = 0; k < j; k++) {
		printf("%c ", postfix[k]);
	}
	printf("\n");

	postfix[j] = NULL;
	return postfix;
}

int evalPostfix(char* postfix) {

	ArrayStack* NumStack = createArrayStack(100, INTEGER);

	for (int i = 0; postfix[i] != NULL; i++) {
		if (postfix[i] >= '0' && postfix[i] <= '9') {
			printf("Current: %c | ", postfix[i]);
			pushArrayStack(NumStack, (stackElement) { postfix[i] - '0' });
		}
		else if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/'){
			printf("Current: %c | ", postfix[i]);
			int a, b;
			int result = 0;

			b = popArrayStack(NumStack).value;
			a = popArrayStack(NumStack).value;

			switch (postfix[i]) {
			case '+':
				result = a + b;
				break;
			case '-':
				result = (int)a - b;
				break;
			case '*':
				result = a * b;
				break;
			case '/':
				result = a / b;
				break;
			}
			pushArrayStack(NumStack, (stackElement) {.value = result });
		}	
		printArrayStack(NumStack);
	}
	return popArrayStack(NumStack).value;
}


int precedence(char op) {
	switch (op)
	{
	case ')':
		return 3;
	case '*':
	case '/':
		return 2;
	case '+':
	case '-':
		return 1;
	case '(':
		return 0;
	default:
		return 0;
	}
}
