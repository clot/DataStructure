//
//  main.c
//  DataStructure
//
//  Created by Mark on 2019/5/27.
//  Copyright © 2019 Mark. All rights reserved.
//

#include <stdio.h>
#include "HashTable.h"
#include "Sort.h"

int main(int argc, const char * argv[]) {
    
    
    int a[6] = {45, 3, 34, 10, 25, 12};
    InsertionSort(a, 6);
    
    // test NextPrime func
    int result = NextPrime(100);
    printf("result: %d\n", result);
    
    return 0;
}
