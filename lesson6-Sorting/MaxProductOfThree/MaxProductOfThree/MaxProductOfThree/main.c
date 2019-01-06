//
//  main.c
//  MaxProductOfThree
//
//  Created by Ifunanya Nnoka on 1/4/19.
//  Copyright © 2019 funasLab. All rights reserved.
//
/*A non-empty array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).
 
 For example, array A such that:
 
 A[0] = -3
 A[1] = 1
 A[2] = 2
 A[3] = -2
 A[4] = 5
 A[5] = 6
 contains the following example triplets:
 
 (0, 1, 2), product is −3 * 1 * 2 = −6
 (1, 2, 4), product is 1 * 2 * 5 = 10
 (2, 4, 5), product is 2 * 5 * 6 = 60
 Your goal is to find the maximal product of any triplet.
 
 Write a function:
 
 int solution(int A[], int N);
 
 that, given a non-empty array A, returns the value of the maximal product of any triplet.
 
 For example, given array A such that:
 
 A[0] = -3
 A[1] = 1
 A[2] = 2
 A[3] = -2
 A[4] = 5
 A[5] = 6
 the function should return 60, as the product of triplet (2, 4, 5) is maximal.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [3..100,000];
 each element of array A is an integer within the range [−1,000..1,000].
 */

#include <stdio.h>
#include <stdlib.h>

int solution(int A[], int N);

int main(int argc, const char * argv[]) {
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
        printf("\nMax Prod. of 3 = %d",val);
        
    }
    return 0;
}

int cmpfunc (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

int solution (int A[], int N){
    int val,valn;
    
    qsort(A, N, sizeof(int), cmpfunc);
    val = A[N-1]*A[N-2]*A[N-3];
    valn = A[0]*A[1]*A[N-1];
    return ((valn > val)?valn:val);
}

