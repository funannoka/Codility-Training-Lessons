//
//  main.c
//  PassingCars
//
//  Created by Ifunanya Nnoka on 12/30/18.
//  Copyright © 2018 funasLab. All rights reserved.
//
/*
 A non-empty array A consisting of N integers is given. The consecutive elements of array A represent consecutive cars on a road.
 
 Array A contains only 0s and/or 1s:

 0 represents a car traveling east,
 1 represents a car traveling west.
 The goal is to count passing cars. We say that a pair of cars (P, Q), where 0 ≤ P < Q < N, is passing when P is traveling to the east and Q is traveling to the west.
 
 For example, consider array A such that:
 
 A[0] = 0
 A[1] = 1
 A[2] = 0
 A[3] = 1
 A[4] = 1
 We have five pairs of passing cars: (0, 1), (0, 3), (0, 4), (2, 3), (2, 4).
 
 Write a function:
 
 int solution(int A[], int N);
 
 that, given a non-empty array A of N integers, returns the number of pairs of passing cars.
 
 The function should return −1 if the number of pairs of passing cars exceeds 1,000,000,000.
 
 For example, given:
 A[0] = 0
 A[1] = 1
 A[2] = 0
 A[3] = 1
 A[4] = 1
 the function should return 5, as explained above.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [1..100,000];
 each element of array A is an integer that can have one of the following values: 0, 1.
 */

#include <stdio.h>

int solution(int A[], int N);

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
        printf("\nNumber of Pairs: %d ",val);
    }
    return 0;
}

//O(n+m)
int solution(int A[], int N){
    int i,pairs;
    int *reg = malloc(sizeof(int) * N);
    
    for (i=1,reg[0]=A[0]; i<N; i++) {
        reg[i] =reg[i-1]+A[i];  //Prefix Sum
    }
    for (i=0,pairs=0; i<N; i++) {
        if (!A[i]) {
            pairs += (reg[N-1] - reg[i]);
        }
        if(pairs > 1e9){
            pairs = -1;
            break;
        }
    }
    return pairs;
}
