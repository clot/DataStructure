//
//  HashTable.c
//  DataStructure
//
//  Created by Mark on 2019/5/28.
//  Copyright © 2019 Mark. All rights reserved.
//

#include "HashTable.h"

#define MinTableSize 0
#define NOSPACE printf("Out of space\n");

struct ListNode {
    ElementType Element;
    Position Next;
};

typedef Position List;
typedef int Index;

struct HashTbl {
    int TableSize;
    List *TheLists;
};

Index Hash(const char *Key, int TableSize) {
    unsigned int HashVal = 0;
    
    while(*Key != '\0')
        HashVal = (HashVal << 5) + *Key++;
    return HashVal % TableSize;
}

int NextPrime(int Number) {
    int i;
    for (i = 2; i <= Number; i++) {
        if (Number % i == 0) {
            break;
        }
    }
    if (i != Number) {
        return NextPrime(++Number);
    } else {
        return Number;
    }
}

HashTable InitializeTable(int TableSize) {
    HashTable H;
    int i;
    
    if (TableSize < MinTableSize) {
        printf("Table size too small");
        return NULL;
    }
    
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL) NOSPACE
    
    H->TableSize = NextPrime(TableSize);
    
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL) NOSPACE
    
    for (i = 0; i < H->TableSize; i++) {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL) NOSPACE
        else H->TheLists[i]->Next = NULL;
    }
    return H;
}

Position FindTableElement(ElementType Key, HashTable H) {
    Position P;
    List L;
    
    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;
    while(P != NULL && P->Element != Key)
        P = P->Next;
    return P;
}

