//
//  main.c
//  CyclicRotation
//
//  Created by Ifunanya Nnoka on 12/26/18.
//  Copyright © 2018 funasLab. All rights reserved.
//

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
