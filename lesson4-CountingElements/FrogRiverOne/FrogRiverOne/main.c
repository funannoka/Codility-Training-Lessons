//
//  main.c
//  FrogRiverOne
//
//  Created by Ifunanya Nnoka on 12/28/18.
//  Copyright © 2018 funasLab. All rights reserved.
//


/*A small frog wants to get to the other side of a river. The frog is initially located on one bank of the river (position 0) and wants to get to the opposite bank (position X+1). Leaves fall from a tree onto the surface of the river.
 
 You are given an array A consisting of N integers representing the falling leaves. A[K] represents the position where one leaf falls at time K, measured in seconds.
 
 The goal is to find the earliest time when the frog can jump to the other side of the river. The frog can cross only when leaves appear at every position across the river from 1 to X (that is, we want to find the earliest moment when all the positions from 1 to X are covered by leaves). You may assume that the speed of the current in the river is negligibly small, i.e. the leaves do not change their positions once they fall in the river.
 
 For example, you are given integer X = 5 and array A such that:
 
 A[0] = 1
 A[1] = 3
 A[2] = 1
 A[3] = 4
 A[4] = 2
 A[5] = 3
 A[6] = 5
 A[7] = 4
 In second 6, a leaf falls into position 5. This is the earliest time when leaves appear in every position across the river.
 
 Write a function:
 
 int solution(int X, int A[], int N);
 
 that, given a non-empty array A consisting of N integers and integer X, returns the earliest time when the frog can jump to the other side of the river.
 
 If the frog is never able to jump to the other side of the river, the function should return −1.
 
 For example, given X = 5 and array A such that:
 
 A[0] = 1
 A[1] = 3
 A[2] = 1
 A[3] = 4
 A[4] = 2
 A[5] = 3
 A[6] = 5
 A[7] = 4
 the function should return 6, as explained above.
 
 Write an efficient algorithm for the following assumptions:
 
 N and X are integers within the range [1..100,000];
 each element of array A is an integer within the range [1..X].
 
 *0 Initialize lowTime variable to -1;
 *1 Iterate through array and compare equality with X
 *2 If match is found with X compare K time val with variable lowTime,
    If lower than lowest val stored, update  with K val
 *3 Repeat until iterated through entire array, return lowTime
 
 */

#include <stdio.h>

int solution(int X, int A[], int N);


int main() {
    int i,n,x,val;
    int A[100000];
    while (1) {
        printf("\nEnter N: ");
        scanf("%d",&n);
        printf("\nEnter X: ");
        scanf("%d",&x);
        for (i=0; i<n; i++) {
            printf("\nEnter A[%d]: ",i);
            scanf("%d",&A[i]);
        }
        
        val = solution(x, A, n);
        printf("\nEarliest time frog can jump: %d ",val);
        
    }
    return 0;
}

int solution(int X, int A[], int N){
    int K,count;
    int *plot = calloc(X+1,sizeof(int));
    
    for (K=0,count =0; K <=N-1; K++) {
        
        if (plot[A[K]]==0) {
            plot[A[K]]=1;
            count++;
            if (count == X) {
                return K;
            }
        }
    }
    return -1;
}
