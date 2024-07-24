// variables for operating on the stack
// TODOLIST: turn into struct
// TODOLIST: refactor
char* stack;
int SIZE;
int pointer;

// template from generic stack operations
void push(char c);
void pop();
char top();

bool isValid(char* s) {
	stack = (char*)malloc(strlen(s)+1);
	SIZE = strlen(s);
	pointer = -1;

	// loop invariant is while i is between 0 and strlen(s) = n
	for (int i = 0; i < strlen(s); i++)
	{
		// put s[k] in the stack
		if ((s[i] == '(')||(s[i] == '{')||(s[i] == '['))
		{
			push(s[i]);
		}
		// pop the stack if s[k] is a valid close
		else if (((s[i] == ')')&&(top() == '('))
			||((s[i] == '}')&&(top() == '{'))
			||((s[i] == ']')&&(top() == '[')))
		{
			pop();
		}
		else
		{
			return false;
		}
	}

	// if the pointer is -1 then return true otherwise return false
	return pointer == -1 ? true : false;
}

void push(char c) {
	if (pointer < SIZE) {
		pointer++;
		stack[pointer] = c;
	}
}

void pop() {
	if (pointer >= 0) {
		pointer--;
	}
}

char top() {
	if (pointer != -1)
	{
		return stack[pointer];
	}

	return '\0';
}
