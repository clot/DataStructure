//
//  Tree.h
//  DataStructure
//
//  Created by Mark on 2019/5/28.
//  Copyright © 2019 Mark. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include <stdio.h>
#include <stdlib.h>

struct TreeNode;
typedef struct TreeNode *Position;
typedef struct TreeNode *SearchTree;
typedef char ElementType;

SearchTree MakeEmpty(SearchTree T);
Position FindTree(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);
SearchTree InsertTree(ElementType X, SearchTree T);
SearchTree Delete(ElementType X, SearchTree T);
ElementType Retrieve(Position P);

#endif /* BinarySearchTree */
