//
//  main.c
//  Equileader
//
//  Created by Ifunanya Nnoka on 1/12/19.
//  Copyright © 2019 funasLab. All rights reserved.
//
/*A non-empty array A consisting of N integers is given.
 
 The leader of this array is the value that occurs in more than half of the elements of A.
 
 An equi leader is an index S such that 0 ≤ S < N − 1 and two sequences A[0], A[1], ..., A[S] and A[S + 1], A[S + 2], ..., A[N − 1] have leaders of the same value.
 
 For example, given array A such that:
 
 A[0] = 4
 A[1] = 3
 A[2] = 4
 A[3] = 4
 A[4] = 4
 A[5] = 2
 we can find two equi leaders:
 
 0, because sequences: (4) and (3, 4, 4, 4, 2) have the same leader, whose value is 4.
 2, because sequences: (4, 3, 4) and (4, 4, 2) have the same leader, whose value is 4.
 The goal is to count the number of equi leaders.
 
 Write a function:
 
 int solution(int A[], int N);
 
 that, given a non-empty array A consisting of N integers, returns the number of equi leaders.
 
 For example, given:
 
 A[0] = 4
 A[1] = 3
 A[2] = 4
 A[3] = 4
 A[4] = 4
 A[5] = 2
 the function should return 2, as explained above.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [1..100,000];
 each element of array A is an integer within the range [−1,000,000,000..1,000,000,000].
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        printf("\n# of Equi Leaders = %d",val);
        
    }
    return 0;
}



int solution(int A[], int N){
    int i;
    int rCount,lCount,size=0;
    int equiLeads=0;
    int *lMaxVal =  malloc(N*sizeof(int));
    int *rMaxVal =  malloc(N*sizeof(int));
    int *rcount =  malloc(N*sizeof(int));
    
    
    for (i=N-1; i>=0; i--)
    {
        if (size == 0)
        {
            size +=1;
            rMaxVal[i] = A[i];
        }
        else
        {
            rMaxVal[i] = rMaxVal[i+1];
            if (rMaxVal[i] != A[i])
                size -= 1;
            else
            {
                size += 1;
            }
        }
    }
    if (!(size>0))
        return 0;
    
    for (i=0,size=0; i<N-1; i++)
    {
        if (size == 0)
        {
            size +=1;
            lMaxVal[i] = A[i];
        }
        else
        {
            lMaxVal[i] = lMaxVal[i-1];
            if (lMaxVal[i] != A[i])
                size -= 1;
            else
            {
                size += 1;
            }
        }
    }
    for (i=N-1,rCount=0; i>0; i--)
    {
        if (A[i]==rMaxVal[1])
            rCount++;
        rcount[i] = rCount;
    }
    for (i=0,lCount=0; i<N-1; i++)
    {
        if (A[i]==lMaxVal[N-2])
            lCount++;
        if ((lCount >  (int)((i+1)/2.0))&&
            (rcount[i+1] > (int)((N-i-1)/2.0))&&
            (lMaxVal[i]==rMaxVal[i+1]))
            equiLeads++;
    }
    

    return equiLeads;
}

