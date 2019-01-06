//
//  main.c
//  oddOccurencesInArray
//
//  Created by Ifunanya Nnoka on 12/26/18.
//  Copyright © 2018 funasLab. All rights reserved.
//
/*A non-empty array A consisting of N integers is given. The array contains an odd number of elements, and each element of the array can be paired with another element that has the same value, except for one element that is left unpaired.
 
 For example, in array A such that:
 
 A[0] = 9  A[1] = 3  A[2] = 9
 A[3] = 3  A[4] = 9  A[5] = 7
 A[6] = 9
 the elements at indexes 0 and 2 have value 9,
 the elements at indexes 1 and 3 have value 3,
 the elements at indexes 4 and 6 have value 9,
 the element at index 5 has value 7 and is unpaired.
 Write a function:
 
 int solution(int A[], int N);
 
 that, given an array A consisting of N integers fulfilling the above conditions, returns the value of the unpaired element.
 
 For example, given array A such that:
 
 A[0] = 9  A[1] = 3  A[2] = 9
 A[3] = 3  A[4] = 9  A[5] = 7
 A[6] = 9
 the function should return 7, as explained in the example above.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an odd integer within the range [1..1,000,000];
 each element of array A is an integer within the range [1..1,000,000,000];
 all but one of the values in A occur an even number of times.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution (int[], int);
int solution_highperformance(int[], int);


int main() {
    int i,n,k;
    int buff[101];
    while(1) {
        printf("Enter size\n::::>>>>>>>>>");
        scanf("%d",&n);
        for (i=0; i<n; i++) {
            printf("A[%d] = ",i);
            scanf("%d",&buff[i]);  //&buff[i]);
        }
        k = solution(buff, n);
       // printf("Unmatched Val = %d\n",k);

    }
    return 0;
}


int solution_lowperformance (int A[], int N){
    int i=0,j=0,val=0;
    int buff[N];
    memset(buff, 0, sizeof(buff));
    
    while(j<N){
        for (i=N-1; i >= 0; i--) {
            if ((A[i] == A[j])&&(i != j)&&(buff[i] != 1)&&(buff[j] != 1)){
                buff[i] = 1;
                buff[j] = 1;
                break;
            }
        }
        if (buff[j]==0) {
            val = A[j];
            break;
        }
        
        j++;
    }
    return val;
}


//Corectness plus performance reached
int solution(int A[], int N)
{
    int i;
    int odd = A[0];
    for (i = 1; i<N; i++)
    {
        odd ^= A[i];
    }
    return odd;
}
