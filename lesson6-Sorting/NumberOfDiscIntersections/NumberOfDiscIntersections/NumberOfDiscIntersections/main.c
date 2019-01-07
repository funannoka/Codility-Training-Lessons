//
//  main.c
//  NumberOfDiscIntersections
//
//  Created by Ifunanya Nnoka on 1/5/19.
//  Copyright © 2019 funasLab. All rights reserved.
//
/*
 We draw N discs on a plane. The discs are numbered from 0 to N − 1. An array A of N non-negative integers, specifying the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].
 
 We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).
 
 The figure below shows discs drawn for N = 6 and A as follows:
 
 A[0] = 1
 A[1] = 5
 A[2] = 2
 A[3] = 1
 A[4] = 4
 A[5] = 0
 
 
 There are eleven (unordered) pairs of discs that intersect, namely:
 
 discs 1 and 4 intersect, and both intersect with all the other discs;
 disc 2 also intersects with discs 0 and 3.
 Write a function:
 
 int solution(int A[], int N);
 
 that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.
 
 Given array A shown above, the function should return 11, as explained above.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [0..100,000];
 each element of array A is an integer within the range [0..2,147,483,647].
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
        printf("\nPairs of intersecting disks = %d",val);
    }
    return 0;
}

int cmpfunc (const void * a, const void * b) {
    long f = *(const long*)a;
    long s = *(const long*)b;
    if (f < s) return -1;
    if (f == s) return 0;
    return 1;
}

/*Time Complexity: O(nlog(n)) 
* Space Complexity: O(n)*/
int solution(int A[], int N)
{
    int i,j,count = 0,cnt = 0;
    long *p[2];
    long max = 10e6;
    
    for (i=0; i<2; i++)
    {
        p[i] = malloc(sizeof(long)*N);
    }
    for (i=0; i<N; ++i)
    {
        p[0][i] = (long)i + A[i]; //Right
        p[1][i] = (long)i - A[i]; // Left
    }
    qsort(p[0], N, sizeof(long), cmpfunc);
    qsort(p[1], N, sizeof(long), cmpfunc);
    
    for (i=0,j=0; i<N;)
    {
        if (p[1][i]<= p[0][j])
        {
            cnt++;
            count += cnt -1;
            
            if (count > max)
            {
                return -1;
            }
            i++;
        }
        else
        {
            cnt--;
            j++;
        }
    }
    return count;
}

///O(N**2) 81% Performance
int solution_(int A[], int N){
    int i,j,count = 0;
    long *p[2];
    long s0,s1;
    long max = 10e6;
    
    for (i=0; i<2; i++) {
        p[i] = malloc(sizeof(long)*N);
    }
    for (i=0; i<N; i++) {
        p[0][i] = i + (long)A[i];
        p[1][i] = i - (long)A[i];
    }
    for (i=0; i<N; i++) {
        s0 = p[0][i];
        s1 = p[1][i];
        for (j=i+1; j<N; j++) {
            if ((p[1][j]<= s0)&&(p[0][j]>=s1)) {
                count++;
            }
            if (count > max) {
                return -1;
            }
        }
    }
    return count;
}
