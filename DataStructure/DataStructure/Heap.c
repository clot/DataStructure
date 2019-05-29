//
//  Heap.c
//  DataStructure
//
//  Created by Mark on 2019/5/29.
//  Copyright © 2019 Mark. All rights reserved.
//

#include "Heap.h"

#define MIN_PQ_SIZE 1
#define NO_SPACE printf("Out of space\n");

struct HeapStruct {
    int Capacity;
    int Size;
    ElementType *Elements;
};

PriorityQueue InitializeHeap(int MaxElements) {
    PriorityQueue H;
    
    if (MaxElements < MIN_PQ_SIZE) {
        NO_SPACE
    }
    
    H = malloc(sizeof(struct HeapStruct));
    H->Elements = malloc(sizeof(ElementType) * (MaxElements + 1));
    if (H->Elements == NULL) {
        NO_SPACE
    }
    
    H->Capacity = MaxElements;
    H->Size = 0;
    H->Elements[0] = "";
    
    return H;
}

void InsertHeapNode(ElementType X, PriorityQueue H) {
    if (IsFullHeap(H)) {
        printf("Priority queue is full\n");
        return;
    }
    
    int i;
    for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = X;
}

ElementType DeleteMinElement(PriorityQueue H) {
    int i, Child;
    ElementType MinElement, LastElement;
    
    if (IsEmptyHeap(H)) {
        printf("Priority queue is empty");
        return H->Elements[0];
    }
    MinElement = H->Elements[1];
    LastElement = H->Elements[H->Size -1];
    
    for (i = 1; i * 2 <= H->Size; i = Child) {
        Child = i * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;
        if (LastElement > H->Elements[Child])
            H->Elements[i] = H->Elements[Child];
        else break;
    }
    H->Elements[i] = LastElement;
    return MinElement;
}

int IsEmptyHeap(PriorityQueue H) {
    return H->Size == 0;
}

int IsFullHeap(PriorityQueue H) {
    return H->Size == H->Capacity;
}
