//
//  main.c
//  CountDiv
//
//  Created by Ifunanya Nnoka on 1/3/19.
//  Copyright © 2019 funasLab. All rights reserved.
//
/*Write a function:
 
 int solution(int A, int B, int K);
 
 that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:
 
 { i : A ≤ i ≤ B, i mod K = 0 }
 
 For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.
 
 Write an efficient algorithm for the following assumptions:
 
 A and B are integers within the range [0..2,000,000,000];
 K is an integer within the range [1..2,000,000,000];
 A ≤ B.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(int A, int B, int K);


int main() {
    int a,b,k,val;
    
    while (1) {
        printf("\nEnter A: ");
        scanf("%d",&a);
        printf("\nEnter B: ");
        scanf("%d",&b);
        printf("\nEnter K: ");
        scanf("%d",&k);
        val = solution(a,b,k);
        printf("\ndivisible count = %d",val);
    }
    return 0;
}
//O(1)
int solution(int A, int B, int K){
    int count;
    count = B/K - A/K;
    if (A%K == 0)
        count++;
    
    return count;
}
