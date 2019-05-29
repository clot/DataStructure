//
//  Queue.c
//  DataStructure
//
//  Created by Mark on 2019/5/27.
//  Copyright © 2019 Mark. All rights reserved.
//

#include "Queue.h"

struct QueueRecord {
    int Capacity;
    int Front;
    int Rear;
    int Size;
    ElementType *Array;
};

int IsEmptyQueue(Queue Q) {
    return Q->Size == 0;
}

void MakeEmptyQueue(Queue Q) {
    Q->Size = 0;
    Q->Front = 1;
    Q->Rear = 0;
}

static int Succ(int value, Queue Q) {
    if (++value == Q->Capacity) {
        value = 0;
    }
    return value;
}

void Enqueue(ElementType X, Queue Q) {
    if (IsFullQueue(Q))
        printf("Full Queue");
    else {
        Q->Size++;
        Q->Rear = Succ(Q->Rear, Q);
        Q->Array[Q->Rear] = X;
    }
}

int IsFullQueue(Queue Q) {
    return Q->Rear == Q->Size;
}
