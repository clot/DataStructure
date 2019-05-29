//
//  Heap.h
//  DataStructure
//
//  Created by Mark on 2019/5/29.
//  Copyright © 2019 Mark. All rights reserved.
//

#ifndef Heap_h
#define Heap_h

#include <stdio.h>
#include <stdlib.h>

struct HeapStruct;
typedef struct HeapStruct *PriorityQueue;
typedef char *ElementType;

PriorityQueue InitializeHeap(int MaxElements);
void DestroyHeap(PriorityQueue H);
void MakeEmptyHeap(PriorityQueue H);
void InsertHeapNode(ElementType X, PriorityQueue H);
ElementType DeleteMinElement(PriorityQueue H);
ElementType FindMinElement(PriorityQueue H);
int IsEmptyHeap(PriorityQueue H);
int IsFullHeap(PriorityQueue H);

#endif /* Heap_h */
