//
//  main.c
//  TapeEquilibrium
//
//  Created by Ifunanya Nnoka on 12/27/18.
//  Copyright © 2018 funasLab. All rights reserved.
//
/*
 A non-empty array A consisting of N integers is given. Array A represents numbers on a tape.
 
 Any integer P, such that 0 < P < N, splits this tape into two non-empty parts: A[0], A[1], ..., A[P − 1] and A[P], A[P + 1], ..., A[N − 1].
 
 The difference between the two parts is the value of: |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|
 
 In other words, it is the absolute difference between the sum of the first part and the sum of the second part.
 
 For example, consider array A such that:
 
 A[0] = 3
 A[1] = 1
 A[2] = 2
 A[3] = 4
 A[4] = 3
 We can split this tape in four places:
 
 P = 1, difference = |3 − 10| = 7
 P = 2, difference = |4 − 9| = 5
 P = 3, difference = |6 − 7| = 1
 P = 4, difference = |10 − 3| = 7
 Write a function:
 
 int solution(int A[], int N);
 
 that, given a non-empty array A of N integers, returns the minimal difference that can be achieved.
 
 For example, given:
 
 A[0] = 3
 A[1] = 1
 A[2] = 2
 A[3] = 4
 A[4] = 3
 the function should return 1, as explained above.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [2..100,000];
 each element of array A is an integer within the range [−1,000..1,000].
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int solution(int [], int);
int solutionMostEfficient(int [], int);

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
        
        val = solutionMostEfficient(A, n);
        printf("\nMin Difference: %d ",val);
        
    }
    return 0;
}

//diff = |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|
//O(N*N)
int solutionMediumEfficient69percent(int A[], int N){
#define max 100000001
    int i,n,p;
    long  topHalf =  0;
    long bottomHalf = 0;
    long diff = 0;
    long  min=max;
    
    for (p = 1; p <= N-1; p++) {
        topHalf = 0;
        bottomHalf = 0;
        for (n=0; n <= p-1; n++)
            topHalf += (long)A[n];
        for (i=p; i <= N-1; i++)
            bottomHalf  += (long)A[i];
        diff = abs(topHalf - bottomHalf);
      //  if(p == 1)
        //    min = abs(topHalf - bottomHalf);
        //else
        if(diff < min)
            min = diff;
    }
    return min;
}

//diff = |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|
//O(N*N)
int solution53percentperformance(int A[], int N){
    //#define max 100000001
    int i,n=0,p=1;
    long  topHalf =  0;
    long bottomHalf = 0;
    long diff = 0;
    long  min = 1;
    i=p;
    while(p <= N-1){
        //for (p = 1; p <= N-1; p++) {
        if(n <= p-1)
            topHalf += (long)A[n];
        if(i <= N-1)
            bottomHalf  += (long)A[i];
        if ((i>=N-1)&(n >= p-1))
        {
            diff = abs(topHalf - bottomHalf);
            topHalf = 0;
            bottomHalf = 0;
            p++;
            i=p;
            n=0;
        }
        else
        {
            n++;
            i++;
        }
        if(p-1 == 1)
            min = diff;
        else if(diff < min)
            min = diff;
    }
    return min;
}


#include <limits.h>
    //O(N)
int solutionMostEfficient(int A[], int N){
        int *p = malloc(sizeof(int) * N);
        int  topHalf;
        int bottomHalf;
        int diff;
        int i;
        int min = INT_MAX;
        
        for (p[0] = A[0],i=1; i <= N-1; i++) {
            p[i] = p[i-1] + A[i];  //Prefix Sum
        }
        
        for (i=1; i <= N-1; i++){
            topHalf = p[i-1];
            bottomHalf  = p[N-1] -topHalf;
            diff = abs(topHalf - bottomHalf);
            if(diff < min){
                min = diff;
                if(min == 0)
                    break;
            }
        }
        return min;
    }
