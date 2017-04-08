#include <stdio.h>
#include "queue.h"

int main()
{
	QUEUE queue;
	init_queue(&queue);

	for (int i = 0; i < 10; i++) {
		queue.push(&queue, i);
	}
	printf("top: %d\n", queue.top(&queue));

	printf("pop: ");
	while (!queue.is_empty(&queue)) {
		printf("%d ", queue.pop(&queue));
	}
	printf("\n");

	destroy_queue(&queue);

	return 0;
}
