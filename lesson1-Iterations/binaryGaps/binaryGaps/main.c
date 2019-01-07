//
//  main.c
//  binaryGaps
//
//  Created by Ifunanya Nnoka on 12/25/18.
//  Copyright © 2018 funasLab. All rights reserved.
//
/*A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int binary_gap(int);

int main()
{
    
    int n;
    char *pointer;
    int max_gap_len;
    
    while (1)
    {
        printf("Enter an Integer in Decimal Number System\n::::>>>>>>>");
        scanf("%d",&n);
        max_gap_len = binary_gap(n);
        printf("Maximum Binary Gap Lenght of integer %d is: %d\n",n,max_gap_len);
        free(pointer);
    }
    return 0;
}


int binary_gap(int N)
{
    int c, d;
    int low = 0;
    int ones = 0,zeros = 0;
    int no_of_gaps = 0,max_width = 0;
    
    for (c = 31 ; c >= 0 ; c--)
    {
        d = N >> c;
        if(d & 1)
        {
            if(ones > 0)
            {
                if (!low)
                {
                    no_of_gaps++;
                    low = 1;
                    if (zeros > max_width)
                    {
                        max_width = zeros;
                    }
                }
                zeros = 0;
            }
            else
            {
                ones++;
                low = 1;
            }
        }
        else if(ones > 0)
        {
            zeros++;
            if (low) {
            low = 0;
            }
            
        }
    }
   // printf("Number of gaps: %d\n", no_of_gaps);
    return  max_width;
}



