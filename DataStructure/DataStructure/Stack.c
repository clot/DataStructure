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

int IsEmpty(Stack S) {
    return S->Next == NULL;
}
