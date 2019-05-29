//
//  HashTable.h
//  DataStructure
//
//  Created by Mark on 2019/5/28.
//  Copyright © 2019 Mark. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h

#include <stdio.h>
#include <stdlib.h>

struct ListNode;
typedef struct ListNode *Position;
struct HashTbl;
typedef struct HashTbl *HashTable;
typedef char* ElementType;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position FindTableElement(ElementType Key, HashTable H);
void InsertTable(ElementType Key, HashTable H);
ElementType Retrieve(Position P);
int NextPrime(int Number);

#endif /* HashTable_h */
