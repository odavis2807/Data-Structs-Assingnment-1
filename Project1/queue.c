#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "player.h"

//Creates node and allocates memory
NODE* CreateNode() {
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	if (newNode == NULL) {
		printf("Memory Allocation Error\n");
		return NULL;
	}
	newNode->next = NULL;
	return newNode;
}
//frees node
void FreeNode(NODE* n) {
	free(n);
}
//prints node
void PrintNode(NODE* n) {
	printf("Username: %s Level: %d Faction: %s\n", n->p.username, n->p.level, n->p.faction);
}


//pushes newNode onto queue
void Push(NODE* newNode, QUEUE* q) {
	if (q->head == NULL) {
		q->head = q->tail = newNode;
	}
	else {
		q->tail->next = newNode;
	}
	newNode->next = NULL;
	q->tail = newNode;
}
//pops node off queue
NODE* Pop(QUEUE* q) {
	NODE* temp;
	if (q->head == NULL)
		return NULL;
	temp = q->head;
	q->head = q->head->next;
	return temp;
}
//frees queue
void FreeQueue(QUEUE q) {
	NODE* current = q.head;
	while (current != NULL) {
		NODE* temp = current;
		current = current->next;
		free(temp);
	}
}
//prints queue
void PrintQueue(QUEUE q) {
	NODE* current = q.head;
	while (current != NULL) {
		PrintNode(current);
		current = current->next;
	}
}
//creates empty queue
QUEUE CreateQueue() {
	QUEUE q;
	q.head = CreateNode();
	q.tail = CreateNode();
	q.head = q.tail = NULL;
	return q;
}

int IsQueueEmpty(QUEUE q) {
	return (q.head == NULL);
}