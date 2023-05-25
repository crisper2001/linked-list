#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
} Node;

Node *head, *tail;

void createLinkedList(void);
void addNodeEnd(int);
void removeNodeEnd(void);
void printLinkedList();

int main(void) {
	int value;
	createLinkedList();
	do {
		printf("New value or 0 to leave: ");
		scanf("%d", &value);
		addNodeEnd(value);
	} while (value != 0);
	removeNodeEnd();
	printLinkedList();
	return 0;
}

void createLinkedList(void) {
	head = tail = NULL;
}

void addNodeEnd(int value) {
	Node* newNodePointer = (Node*) malloc(sizeof(Node));
	newNodePointer -> data = value;
	newNodePointer -> link = NULL;
	if (head == NULL)
		head = tail = newNodePointer;
	else {
		tail -> link = newNodePointer;
		tail = newNodePointer;
	}
}

void removeNodeEnd(void) {
	if (head == NULL)
		return;
	if (head -> link != NULL) {
		Node* auxNodePointer = head;
		while (auxNodePointer -> link != tail)
			auxNodePointer = auxNodePointer -> link;
		free(tail);
		tail = auxNodePointer;
		tail -> link = NULL;
	} else {
		free(tail);
		head = tail = NULL;
	}
}

void printLinkedList(void) {
	if (head == NULL)
		return;
	Node* auxNodePointer = head;
	printf("[");
	while (auxNodePointer != NULL) {
		if (auxNodePointer -> link != NULL)
			printf("%d, ", auxNodePointer -> data);
		else
			printf("%d]", auxNodePointer -> data);
		auxNodePointer = auxNodePointer -> link;
	}
}