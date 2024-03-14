

#include "CALC_interface.h"

#define MAX_EXPR_SIZE 100
s8 infix[MAX_EXPR_SIZE];
#define NULL 0

struct Stack {
	s32 top;
	unsigned capacity;
	s32* array;
};

struct Stack* createStack(unsigned capacity)
{
	struct Stack* stack
	= (struct Stack*)malloc(sizeof(struct Stack));

	if (!stack)
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array
	= (s32*)malloc(stack->capacity * sizeof(s32));

	if (!stack->array)
		return NULL;

	return stack;
}

s32 isEmpty(struct Stack* stack)
{
	return stack->top == -1;
}

s32 peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

s32 pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--];
	return '$';
}

void push(struct Stack* stack, s32 op)
{
	stack->array[++stack->top] = op;
}


s8* infixToPostfix(s8* infix)
{
	s32 i, j;
	s32 len = strlen(infix);
	s8* postfix = (s8*)malloc(sizeof(s8) * (len + 2));
	s8 stack[MAX_EXPR_SIZE];
	s32 top = -1;

	for (i = 0, j = 0; i < len; i++)
	{
		if (infix[i] == ' ' || infix[i] == '\t')
			continue;

		// If the scanned charcter is operand
		// add it to the postfix expression
		if (isalnum(infix[i]))
		{
			postfix[j++] = infix[i];
		}

		// if the scanned charcter is '('
		// push it in the stack
		else if (infix[i] == '(')
		{
			stack[++top] = infix[i];
		}

	 	// if the scanned charcter is ')'
		// pop the stack and add it to the
		// output string until empty or '(' found
		else if (infix[i] == ')')
		{
			while (top > -1 && stack[top] != '(')
				postfix[j++] = stack[top--];
			if (top > -1 && stack[top] != '(')
				return "Invalid Expression";
			else
				top--;
		}


		else if (isOperator(infix[i]))
		{

			postfix[j] = ' ';
			postfix[++j] = ' ';

			while (top > -1&& precedence(stack[top])>= precedence(infix[i]))
			{

				postfix[j++] = stack[top--];

			}

			stack[++top] = infix[i];
		}
	}

	// Pop all remaining elements from the stack
	while (top > -1)
	{
		if (stack[top] == '(')
		{
			return "Invalid Expression";
		}
		postfix[j++] = stack[top--];
	}
	postfix[j] = '\0';
	return postfix;
}


s32 evaluatePostfix(s8* exp)
{
	// Create a stack of capacity equal to expression size
	struct Stack* stack = createStack(strlen(exp));
	s32 i;

	// See if stack was created successfully
	if (!stack)
		return -1;

	// Scan all character one by one
	for (i = 0; exp[i]; ++i) {
		// if the character is blank space then continue
		if (exp[i] == ' ')
			continue;

		// If the scanned character is an
		// operand (number here),extract the full number
		// Push it to the stack.
		else if (isdigit(exp[i])) {
			s32 num = 0;

			// extract full number
			while (isdigit(exp[i])) {
				num = num * 10 + (s32)(exp[i] - '0');
				i++;
			}
			i--;

			// push the element in the stack
			push(stack, num);
		}

		// If the scanned character is an operator, pop two
		// elements from stack apply the operator
		else {
			s32 val1 = pop(stack);
			s32 val2 = pop(stack);

			switch (exp[i]) {
			case '+':
				push(stack, val2 + val1);
				break;
			case '-':
				push(stack, val2 - val1);
				break;
			case '*':
				push(stack, val2 * val1);
				break;
			case '/':
				push(stack, val2 / val1);
				break;
			}
		}
	}
	return pop(stack);
}

s32 precedence(s8 operator)
{
	switch (operator)
	{
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}


s32 isOperator(s8 ch)
{
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/'
			|| ch == '^');
}

