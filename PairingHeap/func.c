#include "func.h"

struct PHeap *CreateHeap(int key, struct PHeap *node)
{
	struct PHeap *heap = malloc(sizeof(*heap));
	if (heap) {
		heap->key = key;
		heap->leftChild = NULL;
		heap->nextSibling = NULL;
		heap->parentNode = NULL;
		heap->prevSibling = NULL;
	}

	return heap;
}

struct PHeap *InsertNode(struct PHeap *heap1, struct PHeap *node, int key)
{
	if (node) {
		node->key = key;
		node->leftChild = NULL;
		node->nextSibling = NULL;
		node->parentNode = NULL;
		node->prevSibling = NULL;
	} else {
		node = malloc(sizeof(*node));
		node->key = key;
		node->leftChild = NULL;
		node->nextSibling = NULL;
		node->parentNode = NULL;
		node->prevSibling = NULL;
	}
	heap1 = MeldHeap(heap1, node);

	return heap1;
}

struct PHeap *FindMin(struct PHeap *heap)
{
	return heap ? heap : NULL;
}

struct PHeap *MeldHeap(struct PHeap *heap1, struct PHeap *heap2)
{
	if (!heap1 && heap2)
		return heap2;
	else if (!heap2 && heap1)
		return heap1;
	
	struct PHeap *tempNode;
	
	if (heap1->key < heap2->key) {
		tempNode = heap1->leftChild;
		heap1->leftChild = heap2;
		if (tempNode)
			tempNode->prevSibling = heap2;
		heap2->nextSibling = tempNode;
		heap2->parentNode = heap1;
		
		return heap1;
	}
	else if (heap1->key > heap2->key) {
		tempNode = heap2->leftChild;
		heap2->leftChild = heap1;
		if (tempNode)
			tempNode->prevSibling = heap1;
		heap1->nextSibling = tempNode;
		heap1->parentNode = heap2;
		
		return heap2;
	}
	
	return NULL;
}

struct PHeap *DeleteMin(struct PHeap *heap) 
{
	return TwoPassMerge(heap->leftChild);
}

struct PHeap *TwoPassMerge(struct PHeap *heap)
{
	if (heap == NULL || heap->nextSibling == NULL) 	// <= 1 дочерний узел
		return heap;
	struct PHeap *A, *B, *newNode;
	
	A = heap;
	B = heap->nextSibling;
	if (heap->nextSibling->nextSibling) { 		// >2 дочерних узлов
		newNode = heap->nextSibling->nextSibling;
		A->nextSibling = NULL;
		A->parentNode = NULL;
		B->nextSibling = NULL;
		B->prevSibling = NULL;
		B->parentNode = NULL;
		newNode->prevSibling = NULL;
		newNode->parentNode = NULL;
		return MeldHeap(MeldHeap(A, B), TwoPassMerge(newNode));
	}
	else { 										// 2 дочерних узла
		A->nextSibling = NULL;
		A->parentNode = NULL;
		B->prevSibling = NULL;
		B->parentNode = NULL;
		return MeldHeap(A, B);
	}
	return NULL;
}

struct PHeap *DecreaseKey(struct PHeap *heap, struct PHeap *node, int newKey)
{
	if (node == heap || newKey >= node->key)
		return heap;
	
	if (newKey < node->key) { // свойство минимального дерева нарушено и необходимо восстановить его
		if (node->prevSibling && node->nextSibling) {
			node->prevSibling->nextSibling = node->nextSibling;
			node->nextSibling->prevSibling = node->prevSibling;
			node->nextSibling = NULL;
			node->prevSibling = NULL;
			node->parentNode = NULL;
			node->key = newKey;
			heap = MeldHeap(heap, node);
		}
		if (node->nextSibling && !node->prevSibling) {
			node->parentNode->leftChild = node->nextSibling;
			node->nextSibling->prevSibling = NULL;
			node->nextSibling = NULL;
			node->parentNode = NULL;
			node->key = newKey;
			heap = MeldHeap(heap, node);
		}
		if (node->prevSibling && !node->nextSibling) {
			node->prevSibling->nextSibling = NULL;
			node->prevSibling = NULL;
			node->parentNode = NULL;
			node->key = newKey;
			heap = MeldHeap(heap, node);
			if (heap == heap->parentNode->parentNode)
				heap->parentNode = NULL;
		}
	}
	return heap;
}

struct PHeap *DeleteNode(struct PHeap *heap, struct PHeap *node)
{
	if (heap == NULL)
		return NULL;
	
	if (node->key == heap->key)
		return DeleteMin(heap);
	
	struct PHeap *childNode, *leftNode;
	
	leftNode = node->nextSibling;
	childNode = DeleteMin(node);
	if (node->prevSibling && node->nextSibling) {
		node->prevSibling->nextSibling = node->nextSibling;
		node->nextSibling->prevSibling = node->prevSibling;
	}
	if (node->nextSibling && !node->prevSibling) {
		node->nextSibling->prevSibling = NULL;
		node->parentNode->leftChild = node->nextSibling;
	}
	if (node->prevSibling && !node->nextSibling) {
		node->prevSibling->nextSibling = NULL;
	}
	heap = MeldHeap(heap, childNode);
	
	return heap;
}