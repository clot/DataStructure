//
//  List.h
//  DataStructure
//
//  Created by Mark on 2019/5/27.
//  Copyright © 2019 Mark. All rights reserved.
//

#ifndef List_h
#define List_h

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;
typedef char ElementType;

List MakeEmpty(List L);
int IsEmptyList(List L);
int IsLast(Position P, List L);
Position Find(ElementType X, List L);
void Delete(ElementType X, List L);
Position FindPrevious(ElementType X, List L);
void Insert(ElementType X, List L, Position P);
void DeleteList(List L);
Position Header(List L);
Position First(List L);
Position Advance(Position P);
ElementType Retrieve(Position P);

#endif /* List_h */
