//
//  main.c
//  dominator
//
//  Created by Ifunanya Nnoka on 2/8/19.
//  Copyright © 2019 funasLab. All rights reserved.
//
/*An array A consisting of N integers is given. The dominator of array A is the value that occurs in more than half of the elements of A.
 
 For example, consider array A such that
 
 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
 The dominator of A is 3 because it occurs in 5 out of 8 elements of A (namely in those with indices 0, 2, 4, 6 and 7) and 5 is more than a half of 8.
 
 Write a function
 
 int solution(int A[], int N);
 
 that, given an array A consisting of N integers, returns index of any element of array A in which the dominator of A occurs. The function should return −1 if array A does not have a dominator.
 
 For example, given array A such that
 
 A[0] = 3    A[1] = 4    A[2] =  3
 A[3] = 2    A[4] = 3    A[5] = -1
 A[6] = 3    A[7] = 3
 the function may return 0, 2, 4, 6 or 7, as explained above.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [0..100,000];
 each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
 */

#include <stdio.h>
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
        printf("\nAn index with dominator = %d",val);
        
    }
    return 0;
}


int solution(int A[], int N)
{
    int i,count;
    int size,value;
   
    for (i=0,size=0; i<N;i++)
    {
        if (size==0)
        {
            size++;
            value = A[i];
        }
        else
        {
            if (value != A[i])
                size--;
            else
                size++;
        }
    }
    if (!(size>0))
        return -1;
    for (i=0,count =0; i<N; i++) {
        if (A[i] == value)
            count++;
        if (count > (int)(N/2.0))
            return i;
    }
    
    return -1;
}
