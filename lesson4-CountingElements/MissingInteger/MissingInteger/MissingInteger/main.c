//
//  main.c
//  MissingInteger
//
//  Created by Ifunanya Nnoka on 12/29/18.
//  Copyright © 2018 funasLab. All rights reserved.
//
/*
 This is a demo task.
 
 Write a function:
 
 int solution(int A[], int N);
 
 that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
 
 For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
 
 Given A = [1, 2, 3], the function should return 4.
 
 Given A = [−1, −3], the function should return 1.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [1..100,000];
 each element of array A is an integer within the range [−1,000,000..1,000,000].
 
 my solution:
 1.Iterate through A[] map each positive integer val contained in A[] to *reg
 2.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int solution(int A[], int N);

int main() {
    int i,n,val;
    int A[100000];
    while (1) {
        printf("\nEnter N: ");
        scanf("%d",&n);
        for (i=0; i<n; i++) {
            printf("\nEnter A[%d]: ",i);
            scanf("%d",&A[i]);
        }
        
        val = solution(A, n);
        printf("\nSmallest positive integer not included: %d",val);
    }
    return 0;
}


int solution(int A[], int N){
    int i;
    int *reg = calloc(N+1,sizeof(int));
    
    for (i=0; i<N; i++) {
        if ((reg[A[i]]==0)&&(A[i]>0)&&(A[i]<=N)) {
            reg[A[i]] = 1;
        }
    }
    for (i=1; i<N+1; i++) {
        if (reg[i]==0) {
            return i;
        }
    }
    
    return i;
}
