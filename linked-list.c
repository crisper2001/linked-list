#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node* link;
} Node;

Node *head, *tail;

void addNodeEnd(int);
void addNodeStart(int);
void createLinkedList(void);
int deleteAllNodes(void);
void printLinkedList(void);
int removeNodeEnd(void);
int removeNodeStart(void);

int main(void) {
	int option, value;
	createLinkedList();
	while (1) {
		system("cls");
		printf("Linked List in C [version 1.0.0]\n2023 Crisper. No rights reserved.\n\n");
		printf("1 - Add node at the start\n");
		printf("2 - Add node at the end\n");
		printf("3 - Remove node at the start\n");
		printf("4 - Remove node at the end\n");
		printf("5 - Delete all nodes\n");
		printf("6 - Print\n");
		printf("7 - Exit\n\n> ");
		scanf("%d", &option);
		system("cls");
		switch (option) {
			case 1:
				printf("Value to be added at the start: ");
				scanf("%d", &value);
				addNodeStart(value);
				printf("New node added sucessfully.\n\n");
				break;
			case 2:
				printf("Value to be added at the end: ");
				scanf("%d", &value);
				addNodeEnd(value);
				printf("New node added sucessfully.\n\n");
				break;
			case 3:
				if (removeNodeStart())
					printf("Node at the start removed sucessfully.\n\n");
				else
					printf("ERROR: The list is empty.\n\n");
				break;
			case 4:
				if (removeNodeEnd())
					printf("Node at the end removed sucessfully.\n\n");
				else
					printf("ERROR: The list is empty.\n\n");
				break;
			case 5:
				if (deleteAllNodes())
					printf("All nodes removed sucessfully.\n\n");
				else
					printf("ERROR: The list is empty.\n\n");
				break;
			case 6:
				printLinkedList();
				break;
			case 7:
				return 0;
			default:
				printf("ERROR: Invalid option.\n\n");
				char character;
				while (character = getchar() != '\n');
				break;
		}
		system("pause");
	}
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

void addNodeStart(int value) {
	Node* newNodePointer = (Node*) malloc(sizeof(Node));
	newNodePointer -> data = value;
	newNodePointer -> link = NULL;
	if (head == NULL)
		head = tail = newNodePointer;
	else {
		newNodePointer -> link = head;
		head = newNodePointer;
	}
}

void createLinkedList(void) {
	head = tail = NULL;
}

int deleteAllNodes(void) {
	if (head == NULL)
		return 0;
	while (removeNodeStart());
	return 1;
}

void printLinkedList(void) {
	if (head == NULL) {
		printf("[]\n\n");
		return;
	}
	Node* auxNodePointer = head;
	printf("[");
	while (auxNodePointer != NULL) {
		if (auxNodePointer -> link != NULL)
			printf("%d, ", auxNodePointer -> data);
		else
			printf("%d]\n\n", auxNodePointer -> data);
		auxNodePointer = auxNodePointer -> link;
	}
}

int removeNodeEnd(void) {
	if (head == NULL)
		return 0;
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
	return 1;
}

int removeNodeStart(void) {
	if (head == NULL)
		return 0;
	if (head -> link != NULL) {
		Node* auxNodePointer = head;
		head = head -> link;
		free(auxNodePointer);
	} else {
		free(head);
		head = tail = NULL;
	}
	return 1;
}
