//
//  Sort.c
//  DataStructure
//
//  Created by Mark on 2019/5/29.
//  Copyright © 2019 Mark. All rights reserved.
//

#include "Sort.h"

void InsertionSort(int A[], int N) {
    int j, p, tmp;
    for (p = 1; p < N; p++) {
        tmp =A[p];
        for (j = p; j > 0 && A[j - 1] > tmp; j--)
            A[j] = A[j - 1];
        A[j] = tmp;
    }
}

void Merge(int A[], int tmpArr[], int lPos, int rPos, int rightEnd) {
    int i, leftEnd, numElements, tmpPos;
    leftEnd = rPos - 1;
    tmpPos = lPos;
    numElements = rightEnd - lPos + 1;
    
    while (lPos <= leftEnd && rPos <= rightEnd) {
        if (A[lPos] <= A[rPos])
            tmpArr[tmpPos++] = A[lPos++];
        else
            tmpArr[tmpPos++] = A[rPos++];
    }
    
    while(lPos <= leftEnd)
        tmpArr[tmpPos++] = A[lPos++];
    while(rPos <= rightEnd)
        tmpArr[tmpPos++] = A[rPos++];
    
    for (i = 0; i < numElements; i++, rightEnd--)
        A[rightEnd] = tmpArr[rightEnd];
}

void MSort(int A[], int tmpArr[], int left, int right) {
    int center;
    if (left < right) {
        center = (left + right) / 2;
        MSort(A, tmpArr, left, center);
        MSort(A, tmpArr, center + 1, right);
        Merge(A, tmpArr, left, center + 1, right);
    }
}

void MergeSort(int A[], int n) {
    int *tmpArr;
    tmpArr = malloc(n * sizeof(int));
    if (tmpArr != NULL) {
        MSort(A, tmpArr, 0, n - 1);
    } else
        printf("Out of space\n");
}







