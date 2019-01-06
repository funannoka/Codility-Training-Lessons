//
//  main.c
//  PermMissingElem
//
//  Created by Ifunanya Nnoka on 12/27/18.
//  Copyright © 2018 funasLab. All rights reserved.
//
/*An array A consisting of N different integers is given. The array contains integers in the range [1..(N + 1)], which means that exactly one element is missing.
 
 Your goal is to find that missing element.
 
 Write a function:
 
 int solution(int A[], int N);
 
 that, given an array A, returns the value of the missing element.
 
 For example, given array A such that:
 
 A[0] = 2
 A[1] = 3
 A[2] = 1
 A[3] = 5
 the function should return 4, as it is the missing element.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [0..100,000];
 the elements of A are all distinct;
 each element of array A is an integer within the range [1..(N + 1)].
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
        
        val = solutionMostEfficient(A, n);
        printf("\nMissing Num: %d ",val);
        
    }
    return 0;
}

//Adder permutation (N+1)!: 1+2+3+...+N+N+1
//(N+1)! = ((N+1)*(N+2))/2
//X = (N+1)! - A[]!
int solution (int A[], int N){
    int n;
    int X;
    long  perm1LessElem =  0;
    long  nPlusOnePerm = 0;
    
    for (n = 0; n <= N; n++) {
        perm1LessElem += (long)A[n];
    }
    nPlusOnePerm = (long)(N+1) * (long)(N+2);
    nPlusOnePerm >>= 1;
    X = nPlusOnePerm-perm1LessElem;
    return X;
}

