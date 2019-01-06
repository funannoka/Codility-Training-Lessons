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
