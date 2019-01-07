//
//  main.c
//  MinAvgTwoSlice
//
//  Created by Ifunanya Nnoka on 1/2/19.
//  Copyright © 2019 funasLab. All rights reserved.
//
/*
 A non-empty array A consisting of N integers is given. A pair of integers (P, Q),
 such that 0 ≤ P < Q < N, is called a slice of array A (notice that the slice contains at least two elements).
 The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice.
 To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).
 
 For example, array A such that:
 
 A[0] = 4
 A[1] = 2
 A[2] = 2
 A[3] = 5
 A[4] = 1
 A[5] = 5
 A[6] = 8
 contains the following example slices:
 
 slice (1, 2), whose average is (2 + 2) / 2 = 2;
 slice (3, 4), whose average is (5 + 1) / 2 = 3;
 slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.
 The goal is to find the starting position of a slice whose average is minimal.
 
 Write a function:
 
 int solution(int A[], int N);
 
 that, given a non-empty array A consisting of N integers, returns the starting position of the slice with the minimal average.
 If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.
 
 For example, given array A such that:
 
 A[0] = 4
 A[1] = 2
 A[2] = 2
 A[3] = 5
 A[4] = 1
 A[5] = 5
 A[6] = 8
 the function should return 1, as explained above.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [2..100,000];
 each element of array A is an integer within the range [−10,000..10,000].
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
            printf("\nindex val = %d",val);
    }
    return 0;
}


int solution(int A[], int N){
    int i,ret;
    int *p = malloc(sizeof(int)*N);
    int slicex2;
    int slicex3;
    double fslicex2;
    double fslicex3;
    int index2=0,index3=0;
    
    for (p[0]=A[0],i=1; i<=N-1; i++) {
        p[i]= p[i-1]+A[i];
    }
    for (i=1,slicex2 = p[1]; i<= N-2; i++) {
        if (slicex2 > (p[i+1] - p[i-1])) {
            slicex2 = p[i+1] - p[i-1];
            index2 = i;
        }
    }
    for (i=1,slicex3 = p[2]; i<= N-3; i++) {
        if (slicex3 > (p[i+2] - p[i-1])) {
            slicex3 = p[i+2] - p[i-1];
            index3 = i;
        }
    }
    fslicex3 = slicex3/3.0;
    fslicex2 = slicex2/2.0;
    if (fslicex2 < fslicex3){
        ret = index2;
    }
    else if (fslicex3 < fslicex2){
        ret = index3;
    }
    else if (index2 < index3){
        ret = index2;
    }
    else{
        ret = index3;
    }
    return ret;
}






















<<<<<<< HEAD


||||||| merged common ancestors


//netflix passwd: arinze850206@yosemite.edu > family638
=======
>>>>>>> 29aba04da91b99d2976f950be4e1e4c15bf787cf
