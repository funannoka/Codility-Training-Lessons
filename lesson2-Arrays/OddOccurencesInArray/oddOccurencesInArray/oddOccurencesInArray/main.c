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
#include <unistd.h>

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


int solution (int A[], int N){
    int i=0,j=0,val=0;

    int buff[N];
    memset(buff, 0, sizeof(buff));//, (void) 0);
    
    while(j<N){
        for (i=N-1; i >= 0; i--) {
            if (A[i] == A[j])
                if(i != j)
                    if (buff[i] != 1)
                        if(buff[j] != 1){
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
  
    printf("Unmatched Val = %d\n",val);
    return val;
}


//Corectness plus performance reached
int solution_highperformance(int A[], int N)
{
    int i;
    int odd = A[0];
    for (i = 1; i<N; i++)
    {
        odd ^= A[i];
    }
    return odd;
}
