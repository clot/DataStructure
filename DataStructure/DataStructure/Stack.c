//
//  Stack.c
//  DataStructure
//
//  Created by Mark on 2019/5/27.
//  Copyright © 2019 Mark. All rights reserved.
//

#include "Stack.h"

struct Node {
    ElementType Element;
    PtrToNode Next;
};

int IsEmptyStack(Stack S) {
    return S->Next == NULL;
}

Stack CreateStack(void) {
    Stack S;
    S = malloc(sizeof(struct Node));
    if (S == NULL)
        printf("Out of space\n");
    S->Next = NULL;
    MakeStackEmpty(S);
    return S;
}

void MakeStackEmpty(Stack S) {
    if (S == NULL)
        printf("Must use CreateStack first");
    else
        while (!IsEmptyStack(S)) {
            Pop(S);
        }
}

void Push(ElementType X, Stack S) {
    PtrToNode Tmp;
    Tmp = malloc(sizeof(struct Node));
    if (Tmp == NULL)
        printf("Must use CreateStack first");
    else {
        Tmp->Element = X;
        Tmp->Next = S->Next;
        S->Next = Tmp;
    }
}

ElementType Top(Stack S) {
    if (!IsEmptyStack(S))
        return S->Next->Element;
    printf("Empty stack\n");
    return 0;
}

void Pop(Stack S) {
    PtrToNode First;
    
    if (IsEmptyStack(S))
        printf("Empty stack\n");
    else {
        First = S->Next;
        S->Next = S->Next->Next;
        free(First);
    }
}
