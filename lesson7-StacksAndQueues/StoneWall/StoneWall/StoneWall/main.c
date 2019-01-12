//
//  main.c
//  StoneWall
//
//  Created by Ifunanya Nnoka on 1/10/19.
//  Copyright © 2019 funasLab. All rights reserved.
//
/*You are going to build a stone wall. The wall should be straight and N meters long, and its thickness should be constant; however, it should have different heights in different places. The height of the wall is specified by an array H of N positive integers. H[I] is the height of the wall from I to I+1 meters to the right of its left end. In particular, H[0] is the height of the wall's left end and H[N−1] is the height of the wall's right end.
 
 The wall should be built of cuboid stone blocks (that is, all sides of such blocks are rectangular). Your task is to compute the minimum number of blocks needed to build the wall.
 
 Write a function:
 
 int solution(int H[], int N);
 
 that, given an array H of N positive integers specifying the height of the wall, returns the minimum number of blocks needed to build it.
 
 For example, given array H containing N = 9 integers:
 
 H[0] = 8    H[1] = 8    H[2] = 5
 H[3] = 7    H[4] = 9    H[5] = 8
 H[6] = 7    H[7] = 4    H[8] = 8
 the function should return 7. The figure shows one possible arrangement of seven blocks.
 
 
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [1..100,000];
 each element of array H is an integer within the range [1..1,000,000,000].
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(int H[], int N);


int main(int argc, const char * argv[]) {
    int i,N;
    int A[100];
    
    while (1) {
        printf("\nEnter N: ");
        scanf("%d",&N);
        for (i=0; i<N; i++) {
            printf("\nEnter H[%d]: ",i);
            scanf("%d",&A[i]);
        }
        printf("\nNumber of blocks: %d",solution(A, N));
    }
    return 0;
}

int solution_(int H[], int N){
    int i,j;
    int block=0;
    int cnt=0;
    int *stack= calloc(N, sizeof(int));
    
    stack[cnt++] = H[0];
    block++;
    for (i=0; i<N; i++)
    {
        if (H[i] < stack[cnt-1])
        {
            // j=0;
            // while(j < cnt)
            for(j=0; j<cnt; j++)
            {
                if (H[i] <= stack[j])
                {
                    cnt = j;
                    if (H[i] < stack[j])
                    {
                        block++;
                        stack[cnt++] = H[i];
                    }
                    //cnt = j+1;
                    break;
                }
                // j++;
            }
        }
        else
        {
            if(H[i] > stack[cnt-1])
            {
                stack[cnt++] = H[i];
                block++;
            }
        }
    }
    return block;
}

int solution(int H[], int N){
    int i;
    int block=0;
    int cnt;
    int *stack= calloc(N+1, sizeof(int));
    
    for (i=0,cnt=1; i<N; i++)
    {
        while((cnt>0)&(stack[cnt-1] > H[i]))
        {
            cnt--;
        }
       
        if((cnt==0)|(H[i] > stack[cnt-1]))
        {
                stack[cnt++] = H[i];
                block++;
        }
    }
    return block;
}
