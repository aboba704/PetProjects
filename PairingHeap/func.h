#ifndef _FUNC_H_
#define _FUNC_H_

#include <stdio.h>
#include <stdlib.h>

struct PHeap {
	int key;
	
	struct PHeap *prevSibling;
	struct PHeap *nextSibling;
	struct PHeap *parentNode;
	struct PHeap *leftChild;
};

struct PHeap *CreateHeap(int key, struct PHeap *node);

struct PHeap *InsertNode(struct PHeap *heap, struct PHeap *node, int key);

struct PHeap *FindMin(struct PHeap *heap);

struct PHeap *MeldHeap(struct PHeap *heap1, struct PHeap *heap2);

struct PHeap *DeleteMin(struct PHeap *heap);
struct PHeap *TwoPassMerge(struct PHeap *heap);

struct PHeap *DecreaseKey(struct PHeap *heap, struct PHeap *node, int keyNew);

struct PHeap *DeleteNode(struct PHeap *heap, struct PHeap *node);

struct PHeap *Search(struct PHeap *heap, int key);

#endif // _FUNC_H_