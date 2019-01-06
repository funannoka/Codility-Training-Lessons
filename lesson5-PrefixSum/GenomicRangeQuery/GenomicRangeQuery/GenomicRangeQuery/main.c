//
//  main.c
//  GenomicRangeQuery
//
//  Created by Ifunanya Nnoka on 12/30/18.
//  Copyright © 2018 funasLab. All rights reserved.
//
/*
 A DNA sequence can be represented as a string consisting of the letters A, C, G and T, which correspond to the types of successive nucleotides in the sequence. Each nucleotide has an impact factor, which is an integer. Nucleotides of types A, C, G and T have impact factors of 1, 2, 3 and 4, respectively. You are going to answer several queries of the form: What is the minimal impact factor of nucleotides contained in a particular part of the given DNA sequence?
 
 The DNA sequence is given as a non-empty string S = S[0]S[1]...S[N-1] consisting of N characters. There are M queries, which are given in non-empty arrays P and Q, each consisting of M integers. The K-th query (0 ≤ K < M) requires you to find the minimal impact factor of nucleotides contained in the DNA sequence between positions P[K] and Q[K] (inclusive).
 
 For example, consider string S = CAGCCTA and arrays P, Q such that:
 
 P[0] = 2    Q[0] = 4
 P[1] = 5    Q[1] = 5
 P[2] = 0    Q[2] = 6
 The answers to these M = 3 queries are as follows:
 
 The part of the DNA between positions 2 and 4 contains nucleotides G and C (twice), whose impact factors are 3 and 2 respectively, so the answer is 2.
 The part between positions 5 and 5 contains a single nucleotide T, whose impact factor is 4, so the answer is 4.
 The part between positions 0 and 6 (the whole string) contains all nucleotides, in particular nucleotide A whose impact factor is 1, so the answer is 1.
 Assume that the following declarations are given:
 
 struct Results {
 int * A;
 int M; //Length of the array
 };
 
 Write a function:
 
 struct Results solution(char *S, int P[], int Q[], int M);
 
 that, given a non-empty string S consisting of N characters and two non-empty arrays P and Q consisting of M integers, returns an array consisting of M integers specifying the consecutive answers to all queries.
 
 Result array should be returned as a structure Results.
 
 For example, given the string S = CAGCCTA and arrays P, Q such that:
 
 P[0] = 2    Q[0] = 4
 P[1] = 5    Q[1] = 5
 P[2] = 0    Q[2] = 6
 the function should return the values [2, 4, 1], as explained above.
 
 Write an efficient algorithm for the following assumptions:
 
 N is an integer within the range [1..100,000];
 M is an integer within the range [1..50,000];
 each element of arrays P, Q is an integer within the range [0..N − 1];
 P[K] ≤ Q[K], where 0 ≤ K < M;
 string S consists only of upper-case English letters A, C, G, T.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

struct Results {
    int * A;
    int M; // Length of the array
};

struct Results solution(char *S, int P[], int Q[], int M);

int main() {
    int i,m;
    char S[100];
    int P[100];
    int Q[100];
    struct Results result;

    while (1) {
        printf("\n\nEnter S: ");
        scanf("%s",S);
        printf("\nEnter M: ");
        scanf("%d",&m);
        for (i=0; i<m; i++) {
            printf("\nEnter P[%d]: ",i);
            scanf("%d",&P[i]);
        }
        for (i=0; i<m; i++) {
            printf("\nEnter Q[%d]: ",i);
            scanf("%d",&Q[i]);
        }
        result = solution(S, P, Q, m);
        for (i = 0; i < result.M;i++) {
            printf("\nresult.A[%d]= %d",i, *(result.A+i));
        }
    }
    return 0;
}

// O(N+M)
struct Results solution(char *S, int P[], int Q[], int M){
    struct Results result;
    int i,j;
    char nucleotides[4] = "ACGT";
    int *part[4];
    
    result.A = malloc(M*sizeof(int));
    
    for(i=0;i<4;i++){
        part[i]=malloc(strlen(S)*sizeof(int));
    }
    //Find occurence position of first nucleotide in S
    for(j=0;j<4;j++){
        part[j][0] = (S[0] == nucleotides[j]) - 1;
    }
    //Find occurence position of ith nucleotide in S
    for (i=1; i<strlen(S); i++) {
        for (j=0; j<4; j++) {
            part[j][i] = (S[i] == nucleotides[j])?i:part[j][i-1];
        }
    }
    for (i=0; i<M; i++) {
        result.A[i]=-1;
        for (j=0; j<4; j++) {
            //check for at least one jth nucleotide within the range P[i] to Q[i]?
            if((part[j][Q[i]] >= P[i])&&(part[j][P[i]] <= Q[i])) {
                result.A[i] = j+1;
                break;
            }
        }
    }
    result.M = M;
    return result;
}

//0(N*M) LOWER PERFORMANCE
struct Results solution_N_M(char *S, int P[], int Q[], int M){
    struct Results result;
    int i,n,val=INT_MAX;
    int *buff = calloc((strlen(S))+1, sizeof(int));

    result.A = calloc(M+1, sizeof(int));
    for (i=0; i<M; i++) {
        for (n=P[i]; n<=Q[i]; n++) {            
            switch (S[n]) {
                case 'A':
                    buff[n] = 1;
                    break;
                case 'C':
                    buff[n] = 2;
                    break;
                case 'G':
                    buff[n] = 3;
                    break;
                case 'T':
                    buff[n] = 4;
                    break;
                default:
                    printf("\nInvalid String!");
                    break;
            }
            if(val > buff[n]) {
                val = buff[n];
            }
        }
        result.A[i] = val;
        val = INT_MAX;
    }
    result.M = M;
    return result;
}

