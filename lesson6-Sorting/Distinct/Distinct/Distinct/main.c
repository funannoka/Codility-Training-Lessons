//
//  main.c
//  Distinct
//
//  Created by Ifunanya Nnoka on 1/4/19.
//  Copyright © 2019 funasLab. All rights reserved.
//
/*Write a function
 
 int solution(int A[], int N);
 
 that, given an array A consisting of N integers, returns the number of distinct values in array A.
 
 For example, given array A consisting of six elements such that:
 
 A[0] = 2    A[1] = 1    A[2] = 1
 A[3] = 2    A[4] = 3    A[5] = 1
 the function should return 3, because there are 3 distinct values appearing in array A, namely 1, 2 and 3.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [0..100,000];
 each element of array A is an integer within the range [−1,000,000..1,000,000].
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(int A[], int N);
int cmpfunc (const void * a, const void * b);

int main() {
    int i,n,val;
    int A[100];
    while (1) {
        printf("\nEnter N: ");
        scanf("%d",&n);
        
        for (i=0; i<n; i++) {
            printf("\nEnter A[%d]: ",i);
            scanf("%d",&A[i]);
        }
        
        val = solution(A, n);
        printf("\n# of Distinct Values = %d",val);
        
    }
    return 0;
}

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}
//O(NlogN) or O(N)
int solution(int A[], int N){
    int i;
    int count;
    
    qsort(A, N, sizeof(int), cmpfunc);
    
    for (i=1,count=(N>0); i<N; i++) {
        if (A[i] != A[i-1]) {
            count++;
        }
    }
    return count;
}


int solution_50percent(int A[], int N){
    int i,low,high;
    int count;
    int *plot = calloc(N+1, sizeof(int));

    
    for (i=0,low =1e6,high=-1e6; i<N; i++) {
        plot[A[i]]++;
        low = (A[i]<low)?A[i]:low;
        high = (A[i]>high)?A[i]:high;
    }
    for (i=low,count=0; i<= high; i++) {
        if (plot[i] > 0) {
            count++;
        }
    }
    return count;
}

int solution_60percent(int A[], int N){
    int i;
    int count;
    int *plot = calloc(N+1, sizeof(int));
    
    for (i=0; i<N; i++) {
        plot[A[i]] = 1;
    }
    for (i=0,count=0; i<N; i++) {
        if (plot[A[i]] > 0) {
            count++;
            plot[A[i]]=0;
        }
    }
    return count;
}

