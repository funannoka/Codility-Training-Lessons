//
//  main.c
//  Triangle
//
//  Created by Ifunanya Nnoka on 1/4/19.
//  Copyright © 2019 funasLab. All rights reserved.
//
/*An array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:
 
 A[P] + A[Q] > A[R],
 A[Q] + A[R] > A[P],
 A[R] + A[P] > A[Q].
 For example, consider array A such that:
 
 A[0] = 10    A[1] = 2    A[2] = 5
 A[3] = 1     A[4] = 8    A[5] = 20
 Triplet (0, 2, 4) is triangular.
 
 Write a function:
 
 int solution(int A[], int N);
 
 that, given an array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.
 
 For example, given array A such that:
 
 A[0] = 10    A[1] = 2    A[2] = 5
 A[3] = 1     A[4] = 8    A[5] = 20
 the function should return 1, as explained above. Given array A such that:
 
 A[0] = 10    A[1] = 50    A[2] = 5
 A[3] = 1
 the function should return 0.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [0..100,000];
 each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
 */

#include <stdio.h>
#include <stdlib.h>

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
        printf("\nReturn value for triangular triplet detector = %d",val);
    }
    return 0;
}


int cmpfunc (const void * a, const void * b) {
    int f = *(const int*)a;
    int s = *(const int*)b;
    if (f < s) return -1;
    if (f == s) return 0;
    return 1;
}
//O(NLogN) highest performance 
int solution(int A[], int N){
    int i;
    long s;
    
    if (N < 3) return 0;
    qsort(A, N, sizeof(int), cmpfunc);
    
    for (i=0; i<=N-3; i++) {
        s = A[i] + A[i+1] - A[i+2];
        if ((s > 0)&&(A[i]>0)) {
            return 1;
        }
    }
    
    return 0;
}

//O(N**3) Low Performance 
int solution_(int A[], int N){
    int i,j,k;
    int s1,s2,s3;
    if (N < 3) return 0;
    for (i=0; i<N; i++) {
        for (j=i+1; j<N; j++) {
            for (k=j+1; k<N; k++) {
                s1 = A[j] + A[k] - A[i];
                s2 = A[j] + A[i] - A[k];
                s3 = A[i] + A[k] - A[j];
                if ((s1 > 0)&&(s2>0)&&(s3>0)) {
                    return 1;
                }
            }
        }
    }
    
    return 0;
}

