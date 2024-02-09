#include "player.h"
#include "queue.h"
#include <time.h>
#include <stdio.h>

int main(void) {
	srand(time(NULL));
	
	QUEUE q = CreateQueue();

	//fill queue
	for (int i = 0; i < 5; i++) {
		NODE* newNode = CreateNode();
		if (CreatePlayer(&newNode->p) == 0)
			Push(newNode, &q);
	}
	
	//print initial
	printf("\nInitial Queue: \n");
	PrintQueue(q);

	//pop every node
	while (IsQueueEmpty(q) == 0) {
		printf("\nPopped Node: \n");
		NODE* popNode = Pop(&q);
		PrintNode(popNode);
		FreeNode(popNode);
	}

	FreeQueue(q);

	return 0;
}