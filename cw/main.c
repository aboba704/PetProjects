#include "func.h"

#include <sys/time.h>

double wtime();

int main() {
	struct PHeap *heap1, *heap2, *node;
	node = malloc(sizeof(*node));
	
	heap1 = CreateHeap(-2, NULL);
	heap1 = InsertNode(heap1, NULL, 4);
	heap1 = InsertNode(heap1, NULL, 3);
	heap2 = CreateHeap(5, NULL);
	heap2 = InsertNode(heap2, node, 2);
	heap2 = InsertNode(heap2, NULL, 6);
	heap1 = MeldHeap(heap1, heap2);
	
	heap1 = CreateHeap(1, NULL);
	heap1 = InsertNode(heap1, NULL, 4);
	heap1 = InsertNode(heap1, NULL, 3);
	heap2 = CreateHeap(5, NULL);
	heap2 = InsertNode(heap2, node, 2);
	heap1 = MeldHeap(heap1, heap2);
	heap1 = DecreaseKey(heap1, node, -2);
	heap1 = DeleteNode(heap1, node);
	
//	double before, after, time;
//	int size = 10;
//	
//	heap1 = CreateHeap(0, NULL);
//	for (int i = 1; i < size; i++)
//		heap1 = InsertNode(heap1, NULL, 1);
//	before = wtime();
//	for (int i = 0; i < size - 1; i++) {
//		//printf("%d\n", heap1 -> key);
//		heap1 = DeleteMin(heap1);
//	}
//	after = wtime();
//	time = (after - before) * 100;
//	
//	printf("%f\n", time);
	
	return 0;
}

double wtime() {
	struct timeval t;
	gettimeofday(&t, NULL);
	return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}