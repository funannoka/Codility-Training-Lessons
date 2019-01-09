//
//  main.c
//  Brackets
//
//  Created by Ifunanya Nnoka on 1/6/19.
//  Copyright © 2019 funasLab. All rights reserved.
//
/*A string S consisting of N characters is considered to be properly nested if any of the following conditions is true:
 
 S is empty;
 S has the form "(U)" or "[U]" or "{U}" where U is a properly nested string;
 S has the form "VW" where V and W are properly nested strings.
 For example, the string "{[()()]}" is properly nested but "([)()]" is not.
 
 Write a function:
 
 int solution(char *S);
 
 that, given a string S consisting of N characters, returns 1 if S is properly nested and 0 otherwise.
 
 For example, given S = "{[()()]}", the function should return 1 and given S = "([)()]", the function should return 0, as explained above.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [0..200,000];
 string S consists only of the following characters: "(", "{", "[", "]", "}" and/or ")".
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int solution(char *S);

int main()
{
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
    int i;
    int pos;
    int len = strlen(S);
    
    char * stack = malloc(len);
    
    if (len==0)
    {
        return 1;
    }
    if (len&1) {
        return 0;
    }
    for (i=0,pos=0; i < len; i++)
    {
        if ((S[i] == '[')||(S[i]=='{')||(S[i]== '('))
        {
            stack[pos++] = S[i];
        }
        else
        {
            pos--;
            if (!(((stack[pos]=='[')&&(S[i]==']'))||
                ((stack[pos]=='{')&&(S[i]=='}'))||
                ((stack[pos]=='(')&&(S[i]==')'))))
            {
                return 0;
            }
        }
    }
    free(stack);
    return (pos == 0);
}

