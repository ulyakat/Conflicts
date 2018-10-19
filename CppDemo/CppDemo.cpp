#include <stdio.h>

struct StackElement;

struct Stack 
{
	StackElement *head = nullptr;
};

struct StackElement
{
	int data = 0;
	StackElement *next = nullptr;
};

void push(Stack &stack, int data)
{
	auto newElement = new StackElement{ data, nullptr };
	if (stack.head == nullptr)
	{
		stack.head = newElement;
	}
	else
	{
		newElement->next = stack.head;
		stack.head = newElement;
	}
}

int pop(Stack &stack)
{
	StackElement *temp = stack.head;
	stack.head = stack.head->next;
	const int result = temp->data;
	delete temp;
	return result;
}

void deleteStack(Stack &stack)
{
	while (stack.head != nullptr)
	{
		StackElement *temp = stack.head;
		stack.head = temp->next;
		delete temp;
	}
}

int main()
{
	Stack stack;
	push(stack, 1);
	push(stack, 2);
	push(stack, 3);
	printf("Result: %d\n", pop(stack));
	printf("Result: %d\n", pop(stack));
	deleteStack(stack);
	return 0;
}
