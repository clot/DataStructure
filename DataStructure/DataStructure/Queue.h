//
//  Queue.h
//  DataStructure
//
//  Created by Mark on 2019/5/27.
//  Copyright © 2019 Mark. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>

struct QueueRecord;
typedef struct QueueRecord *Queue;
typedef char ElementType;

int IsEmptyQueue(Queue Q);
int IsFullQueue(Queue Q);
Queue CreateQueue(int MaxElements);
void DisposeQueue(Queue Q);
void MakeEmptyQueue(Queue Q);
void Enqueue(ElementType X, Queue Q);
ElementType Front(Queue Q);
void Dequeue(Queue Q);
ElementType FrontAndDequeue(Queue Q);

#endif /* Queue_h */
