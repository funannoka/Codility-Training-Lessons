//
//  main.c
//  PermCheck
//
//  Created by Ifunanya Nnoka on 12/29/18.
//  Copyright © 2018 funasLab. All rights reserved.
//

/*
 A non-empty array A consisting of N integers is given.
 
 A permutation is a sequence containing each element from 1 to N once, and only once.
 
 For example, array A such that:
 
 A[0] = 4
 A[1] = 1
 A[2] = 3
 A[3] = 2
 is a permutation, but array A such that:
 
 A[0] = 4
 A[1] = 1
 A[2] = 3
 is not a permutation, because value 2 is missing.
 
 The goal is to check whether array A is a permutation.
 
 Write a function:
 
 int solution(int A[], int N);
 
 that, given an array A, returns 1 if array A is a permutation and 0 if it is not.
 
 For example, given array A such that:
 
 A[0] = 4
 A[1] = 1
 A[2] = 3
 A[3] = 2
 the function should return 1.
 
 Given array A such that:

 A[0] = 4
 A[1] = 1
 A[2] = 3
 the function should return 0.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [1..100,000];
 each element of array A is an integer within the range [1..1,000,000,000].
 */

#include <stdio.h>
#include <stdlib.h>
int solution(int A[], int N);

int main() {
    int i,n,num,val;
    int A[100000];
    while (1) {
        printf("\nEnter N: ");
        scanf("%d",&n);
        printf("\nEnter num: ");
        scanf("%d",&num);
        for (i=0; i<num; i++) {
            printf("\nEnter A[%d]: ",i);
            scanf("%d",&A[i]);
        }
        val = solution(A, n);
        if(val)
            printf("\nArray A[] is a permutation");
        else
            printf("\nArray A[] is NOT a permutation");
        
    }
    return 0;
}

int solution(int A[], int N){
    
    int *pointer = calloc(N+1,sizeof(int));
    int i,count=0,ret=1;
    
    for (i=0,count=0,pointer[0]=1; i < N; i++) {
            if(A[i] > N){
                ret = 0;
                break;
            }
            else if (pointer[A[i]] > 0) {
                ret = 0;
                break;
            }
            else {
                pointer[A[i]] = 1;
                count++;
            }
    }
    free(pointer);
    if (count < N)
        ret = 0;
    return ret;
}
