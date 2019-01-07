//
//  main.c
//  CyclicRotation
//
//  Created by Ifunanya Nnoka on 12/26/18.
//  Copyright © 2018 funasLab. All rights reserved.
//
<<<<<<< HEAD
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
||||||| merged common ancestors
=======
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
>>>>>>> 29aba04da91b99d2976f950be4e1e4c15bf787cf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Results {
    int * A;
    int N; // Length of the array
};
struct Results solution(int[], int , int);

int main() {
    int i;
    struct Results result;
    int n,k;
    int buff[101];
    
    while(1) {
        printf("Enter size\n::::>>>>>>>>>");
        scanf("%d",&n);
        printf("Enter no of rotations\n::::>>>>>>>>>");
        scanf("%d",&k);
        for (i=0; i<n; i++) {
            printf("A[%d] = ",i);
            scanf("%d",&buff[i]);  
        }
        result = solution(buff, n, k); 
        for (i = 0; i < result.N;i++) { 
            printf("result.A[%d]= %d\n",i, *(result.A+i));
        }
    }
    return 0;
}



struct Results solution(int A[], int N, int K){
    struct Results results;
    int i,j;
    int buff;
    int *p;
    results.A = (int*)malloc(sizeof(int) * N);
    for (i = K; i > 0; i--){
        p = A;
        buff = *(p+N-1);
       // printf("\nAfter 1 rotation:\n");
        for(j = N-1; j > 0; j--){
            *(p+j)   = *(p+j-1);
          //  printf("A[%d]= %d\n",j, *(p+j));
        }
        *p = buff;
       // printf("A[0]= %d\n",*(p));
    }
    results.A = A;
    results.N = N;
    return results;
}
