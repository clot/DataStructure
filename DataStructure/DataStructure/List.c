//
//  List.c
//  DataStructure
//
//  Created by Mark on 2019/5/27.
//  Copyright © 2019 Mark. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "List.h"

struct Node {
    ElementType Element;
    Position Next;
};

List MakeEmpty(List L) {
    L->Next = NULL;
    return L;
}

int IsEmpty(List L) {
    return L->Next == NULL;
}

int IsLast(Position P, List L) {
    return P->Next == NULL;
}

Position Find(ElementType X, List L) {
    Position P;
    P = L->Next;
    while (P != NULL && P->Element != X) {
        P = P->Next;
    }
    return P;
}

void Delete(ElementType X, List L) {
    Position P = FindPrevious(X, L);
    Position tmp;
    if (!IsLast(P, L)) {
        tmp = P->Next;
        P->Next = tmp->Next;
        free(tmp);
    }
}

Position FindPrevious(ElementType X, List L) {
    Position P = L;
    while (P != NULL && P->Next->Element != X) {
        P = P->Next;
    }
    return P;
}

void Insert(ElementType X, List L, Position P) {
    Position tmp;
    tmp = malloc(sizeof(struct Node));
    if (tmp == NULL)
        printf("Out of space\n");
    tmp->Element = X;
    tmp->Next = P->Next;
    P->Next = tmp;
}

void DeleteList(List L) {
    Position P = L->Next;
    Position current;
    while (P != NULL) {
        current = P;
        P = P->Next;
        free(current);
    }
}

//Position Header(List L);
//Position First(List L);
//Position Advance(Position P);
//ElementType Retrieve(Position P);
