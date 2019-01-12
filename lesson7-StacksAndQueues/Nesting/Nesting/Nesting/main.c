//
//  main.c
//  Nesting
//
//  Created by Ifunanya Nnoka on 1/10/19.
//  Copyright © 2019 funasLab. All rights reserved.
//
/*A string S consisting of N characters is called properly nested if:
 
 S is empty;
 S has the form "(U)" where U is a properly nested string;
 S has the form "VW" where V and W are properly nested strings.
 For example, string "(()(())())" is properly nested but string "())" isn't.
 
 
 Write a function:
 
 int solution(char *S);
 
 that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.
 
 For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [0..1,000,000];
 string S consists only of the characters "(" and/or ")".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(char *S);

int main() {
    char s[100];
    
    while (1)
    {
        printf("\n\nEnter S: ");
        scanf("%s",s);
        if (solution(s))
            printf("\nProperly Nested String");
        else
            printf("\nNOT Properly Nested String");
    }
    return 0;
}

int solution(char *S){
    int i,pos=0;
    int l = strlen(S);
    
    if (l==0)
    {
        return 1;
    }
    if (l&1) {
        return 0;
    }
    for (i=0; i<l; i++) {
        if (S[i] == '(')
        {
            pos++;
        }
        else
        {
            pos--;
            if (pos < 0)
            {
                return 0;
            }
        }
    }
    return (pos==0);
}
