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
        printf("\nMin Difference: %d ",val);
        
    }
    return 0;
}

//diff = |(A[0] + A[1] + ... + A[P − 1]) − (A[P] + A[P + 1] + ... + A[N − 1])|
#include <limits.h>
    //O(N)
int solution(int A[], int N){
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
