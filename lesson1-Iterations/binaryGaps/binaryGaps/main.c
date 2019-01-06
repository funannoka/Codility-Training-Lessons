//
//  main.c
//  binaryGaps
//
//  Created by Ifunanya Nnoka on 12/25/18.
//  Copyright © 2018 funasLab. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *decimal_to_binary(int);
int binary_gap(int);

int main()
{
    
    int n;
    char a;
    char *pointer;
    int max_gap_len;
    
    char *p;// = &a;
    while (1)
    {
        printf("Enter an Integer in Decimal Number System\n::::>>>>>>>");
        scanf("%d",&n);
        pointer = decimal_to_binary(n);
        printf("Binary String of Integer %d is: %s\n",n, pointer);
        max_gap_len = binary_gap(n);
        printf("Maximum Binary Gap Lenght of integer %d is: %d\n",n,max_gap_len);
        free(pointer);
        p = &a;
        printf("Continue? (y/n)\n::::>>>>>>>");
        scanf("%s",p);
        if (strcmp (p,"y") != 0)
        break;
    }
    return 0;
}


char *decimal_to_binary(int n)
{
    int c, d, count;
    char *pointer;
    
    count = 0;
    pointer = (char*)malloc(32+1);
    
    if (pointer == NULL)
        exit(EXIT_FAILURE);
    
    for (c = 31 ; c >= 0 ; c--)
    {
        d = n >> c;
        
        if (d & 1)
            *(pointer+count) = 1 + '0';
        else
            *(pointer+count) = 0 + '0';
        
        count++;
    }
    *(pointer+count) = '\0';
    
    return  pointer;
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
               //ones = 0;
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
    printf("Number of gaps: %d\n", no_of_gaps);
    return  max_width;
}



