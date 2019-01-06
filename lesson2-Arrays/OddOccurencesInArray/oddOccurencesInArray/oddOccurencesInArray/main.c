//
//  main.c
//  oddOccurencesInArray
//
//  Created by Ifunanya Nnoka on 12/26/18.
//  Copyright © 2018 funasLab. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution (int[], int);

int main() {
    int i,n,k;
    int buff[101];
    while(1) {
        printf("Enter size\n::::>>>>>>>>>");
        scanf("%d",&n);
        for (i=0; i<n; i++) {
            printf("A[%d] = ",i);
            scanf("%d",&buff[i]);  
        }
        k = solution(buff, n);
        printf("Unmatched Val = %d\n",k);

    }
    return 0;
}

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
