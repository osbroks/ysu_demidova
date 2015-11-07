/* Задано арифметическое выражение. С помощью стека проверить в нем
правильность расстановки круглых скобок.
*/

#include<stdio.h>
#pragma warning(disable: 4996)
malloc();
free();
system();

typedef struct node{
	int date;
	struct node *next;
} Stack;

Stack *Push(Stack **stack, char date) {
	Stack *node = (Stack *)malloc(sizeof(Stack));
	node->date = date;
	node->next = *stack;
	*stack = node;
	return *stack;
}

void Print(Stack *stack) {
	int i = 0;
	for (; stack; stack = stack->next) {
		printf("Number of element %d: ", i++);
		printf("%c\n", stack->date);
	}
}

void Check(Stack *stack){
	int i = 0;
	int o = 0, z = 0;
	for (i = 0; stack; stack = stack->next){
		if (stack->date == ')'){
			o++;
		}
		if (stack->date == '('){
			z++;
		}
	}
	if ((o == 0) || (z == 0) || (z != o)){
		printf("\nBad insert\n");
	}
	else {
		printf("\nGreat\n!");
	}
}

void Pop(Stack **stack) {
	Stack *node = *stack;
	*stack = node->next;
	free(node);
}

int main(int argc, char *argv[]) {
	system("chcp 1251");
	system("cls");

	Stack *stack = NULL;
	int date = 0;
	char ch;

	puts("for escape, press '*'");
	while (1) {
		puts("Insert data: ");
		//scanf("%d", &date);
		ch = getchar();
		Push(&stack, ch);
		if (ch == '*') {
			break;
		}
		fflush(stdin);
	}
	Pop(&stack);
	Print(stack);
	Check(stack);

	system("PAUSE");
	return 0;
}
