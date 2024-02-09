#pragma once
#include "player.h"

typedef struct Node {
	struct Node* next;
	PLAYER p;
}NODE;

typedef struct Queue {
	NODE* head;
	NODE* tail;
}QUEUE;

NODE* CreateNode();
void FreeNode(NODE* n);
void PrintNode(NODE* n);

void Push(NODE* newNode, QUEUE* q);
NODE* Pop(QUEUE* q);
void FreeQueue(QUEUE q);
void PrintQueue(QUEUE q);
QUEUE CreateQueue();
int IsQueueEmpty(QUEUE q);