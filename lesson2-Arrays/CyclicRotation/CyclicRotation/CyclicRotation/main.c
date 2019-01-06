//
//  main.c
//  CyclicRotation
//
//  Created by Ifunanya Nnoka on 12/26/18.
//  Copyright © 2018 funasLab. All rights reserved.
//
/*An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9, 7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).
 
 The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.
 
 Assume that the following declarations are given:
 
 struct Results {
 int * A;
 int N; // Length of the array
 };
 
 Write a function:
 
 struct Results solution(int A[], int N, int K);
 
 that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.
 
 For example, given
 
 A = [3, 8, 9, 7, 6]
 K = 3
 the function should return [9, 7, 6, 3, 8]. Three rotations were made:
 
 [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
 [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
 [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
 For another example, given
 
 A = [0, 0, 0]
 K = 1
 the function should return [0, 0, 0]
 
 Given
 
 A = [1, 2, 3, 4]
 K = 4
 the function should return [1, 2, 3, 4]
 
 Assume that:
 
 N and K are integers within the range [0..100];
 each element of array A is an integer within the range [−1,000..1,000].
 In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


struct Results {
    int * A;
    int N; // Length of the array
};
//struct Results result;
struct Results solution(int[], int , int);

int main() {
    int i;
    struct Results result;
    int n,k;
    char opt;
    int buff[101];
    int *A;// = buff;
    while(1) {
        A = buff;
        printf("Enter size\n::::>>>>>>>>>");
        scanf("%d",&n);
        printf("Enter no of rotations\n::::>>>>>>>>>");
        scanf("%d",&k);
        for (i=0; i<n; i++) {
            printf("A[%d] = ",i);
            scanf("%d",&buff[i]);  //&buff[i]);
        }
        //  A = buff;
        printf("Original array\n");
        for(i=0;i<n;i++)
        {
            printf("A[%d] = %d\n",i,*A++);
        }
        result = solution(buff, n, k); //buff
        n = result.N;
        
       // printf("result.N= %d\n", result.N);
       // printf("result.A[%d]= %d\n",result.N-1, *(result.A+result.N-1));

        for (i = 0; i < result.N;i++) { //result.N
            //printf("result.A[%d]= %d\n",i-1, *(result.A+i-1));
            printf("result.A[%d]= %d\n",i, *(result.A+i));

        }
        printf("Quit? (y/n)\n::::>>>>>");
        scanf("%s",&opt);
        if (strcmp(&opt,"n"))
            break;
    }
    return 0;
}



struct Results solution(int A[], int N, int K){
    struct Results results;//= (struct Results)malloc(sizeof(int) * (N+1));
    int i,j;
   // int buff[N];
    int buff;
    int *p;// = A;
   // p = A;
    results.A = (int*)malloc(sizeof(int) * N);
    //results.A = malloc(N*sizeof(int));//p;//A;
    //buff[N-1] = A[N-1];
    for (i = K; i > 0; i--){
        p = A;
        buff = *(p+N-1);// A[N-1]; //*(p+N);
        printf("\nAfter 1 rotation:\n");
        for(j = N-1; j > 0; j--){
            *(p+j)   = *(p+j-1);// A[j] = A[j-1];
            printf("A[%d]= %d\n",j, *(p+j)); // results.A[i-1]
        }
        *p = buff;//A[0] = buff;
        printf("A[0]= %d\n",*(p));
    }
   // p = A;
    //mystruct.nums = malloc(num*sizeof(size));
    results.A = A;
    results.N = N;
    return results;
}
