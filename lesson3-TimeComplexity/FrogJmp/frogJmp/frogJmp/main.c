//
//  main.c
//  frogJmp
//
//  Created by Ifunanya Nnoka on 12/27/18.
//  Copyright © 2018 funasLab. All rights reserved.
//
/*
 A small frog wants to get to the other side of the road. The frog is currently located at position X and wants to get to a position greater than or equal to Y. The small frog always jumps a fixed distance, D.
 
 Count the minimal number of jumps that the small frog must perform to reach its target.
 
 Write a function:
 
 int solution(int X, int Y, int D);
 
 that, given three integers X, Y and D, returns the minimal number of jumps from position X to a position equal to or greater than Y.
 
 For example, given:
 
 X = 10
 Y = 85
 D = 30
 the function should return 3, because the frog will be positioned as follows:
 
 after the first jump, at position 10 + 30 = 40
 after the second jump, at position 10 + 30 + 30 = 70
 after the third jump, at position 10 + 30 + 30 + 30 = 100
 Write an efficient algorithm for the following assumptions:
 
 X, Y and D are integers within the range [1..1,000,000,000];
 X ≤ Y.
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int solution(int, int, int);

int main() {
    int x,d,y,val;
    while (1) {
        printf("\nEnter X: ");
        scanf("%d",&x);
        printf("\nEnter Y: ");
        scanf("%d",&y);
        printf("\nEnter D: ");
        scanf("%d",&d);
        val = solution(x, y, d);
        printf("\nNo of Jumps: %d ",val);

    }
    return 0;
}
int solution(int X, int Y, int D){
    int n;
    double dist;
    double d = D;

    dist = (Y-X)/d;
    n = ceil(dist);
    printf("\nceil: %f ",dist);
    printf("\nceil: %d ",n);
    return n;
}


