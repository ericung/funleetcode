#include "stdlib.h" 
#include "stdio.h"
#include "string.h"
#include "stdbool.h"

// variables for operating on the stack
struct Stack {
	char* stack;
	int SIZE;
	int pointer;
};

// template from generic stack operations
void push(struct Stack *stack, char c);
void pop(struct Stack *stack);
char top(struct Stack *stack);

bool isValid(char* s) {
	struct Stack *stack = malloc(sizeof(struct Stack));
	stack->stack = (char*)malloc(strlen(s)+1);
	stack->SIZE = strlen(s);
	stack->pointer = -1;

	// loop invariant is while i is between 0 and strlen(s) = n
	// and s[k] is a valid opening or closing tag
	for (int i = 0; i < strlen(s); i++)
	{
		// put s[k] in the stack
		if ((s[i] == '(')||(s[i] == '{')||(s[i] == '['))
		{
			push(stack, s[i]);
		}
		// pop the stack if s[k] is a valid close
		else if (((s[i] == ')')&&(top(stack) == '('))
			||((s[i] == '}')&&(top(stack) == '{'))
			||((s[i] == ']')&&(top(stack) == '[')))
		{
			pop(stack);
		}
		else
		{
            // if s[k] isn't a valid close, the loop invariant becomes false
			return false;
		}
	}

	// if the pointer is -1 then return true otherwise return false
	return stack->pointer == -1 ? true : false;
}

void push(struct Stack *stack, char c) {
	if (stack->pointer < stack->SIZE) {
		stack->pointer++;
		stack->stack[stack->pointer] = c;
	}
}

void pop(struct Stack *stack) {
	if (stack->pointer >= 0) {
		stack->pointer--;
	}
}

char top(struct Stack *stack) {
	if (stack->pointer != -1)
	{
		return stack->stack[stack->pointer];
	}

	return '\0';
}

int main() {
	char* input1 = "()";
	bool result1 = isValid(input1);
	printf("%d\n", result1);

	char* input2 = "()[]{}";
	bool result2 = isValid(input2);
	printf("%d\n", result2);

	char* input3 = "(]";
	bool result3 = isValid(input3);
	printf("%d\n", result3);

	char* input4 = "([])";
	bool result4 = isValid(input4);
	printf("%d\n", result4);

	return 0;	
}
