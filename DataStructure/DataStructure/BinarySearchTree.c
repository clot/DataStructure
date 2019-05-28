//
//  Tree.c
//  DataStructure
//
//  Created by Mark on 2019/5/28.
//  Copyright © 2019 Mark. All rights reserved.
//

#include "BinarySearchTree.h"

struct TreeNode {
    ElementType Element;
    SearchTree Left;
    SearchTree Right;
};

SearchTree MakeTreeEmpty(SearchTree T) {
    if (T != NULL) {
        MakeTreeEmpty(T->Left);
        MakeTreeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

Position FindTree(ElementType X, SearchTree T) {
    if (T == NULL)
        return NULL;
    if (X < T->Element)
        return FindTree(X, T->Left);
    else if (X > T->Element)
        return FindTree(X, T->Right);
    else
        return T;
}

Position FindMin(SearchTree T) {
    if (T == NULL)
        return NULL;
    else if (T->Left == NULL)
        return T;
    else
        return FindMin(T);
}

Position FindMax(SearchTree T) {
    if (T != NULL)
        while(T->Right != NULL)
            T = T->Right;
    return T;
}

SearchTree InsertTree(ElementType X, SearchTree T) {
    if (T == NULL) {
        T = malloc(sizeof(struct TreeNode));
        if (T == NULL)
            printf("Out of space\n");
        else {
            T->Element = X;
            T->Left = T->Right = NULL;
        }
    } else if (X < T->Element)
        T->Left = InsertTree(X, T->Left);
    else if (X > T->Element)
        T->Right = InsertTree(X, T->Right);
    return T;
}

SearchTree DeleteTreeNode(ElementType X, SearchTree T) {
    Position TmpCell;
    if (T == NULL)
        printf("Element not found\n");
    else if (X < T->Element)
        T->Left = Delete(X, T->Left);
    else if (X > T->Element)
        T->Right = Delete(X, T->Right);
    else if (T->Left && T->Right) {
        TmpCell = FindMin(T->Right);
        T->Element = TmpCell->Element;
        T->Right = DeleteTreeNode(T->Element, T->Right);
    } else {
        TmpCell = T;
        if (T->Left == NULL)
            T = T->Right;
        else if (T->Right == NULL)
            T = T->Left;
        free(TmpCell);
    }
    return T;
}
