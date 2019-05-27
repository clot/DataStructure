//
//  Stack.h
//  DataStructure
//
//  Created by Mark on 2019/5/27.
//  Copyright © 2019 Mark. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include <stdio.h>

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode Stack;
typedef char ElementType;

int IsEmpty(Stack S);
Stack CreateStack(void);
void DisposeStack(Stack S);
void MakeEmpty(Stack S);
void Push(ElementType X, Stack S);
ElementType Top(Stack S);
void Pop(Stack S);

#endif /* Stack_h */
