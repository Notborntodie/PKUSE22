#include <stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define BLOCKSIZE 10000000
int pi[BLOCKSIZE];
int* next(int* p);
int* read_pi();
int KMP(int* T, int* Next,int* P);

int main()
{
    printf("Please input your birthday:\n");
    int b[8];
    char temp[8];
    for (int k = 0; k < 8; k++)
        temp[k] = getchar();
    int* p = b;
    for (int i = 0; i < 8; i++)
    {
        *p = (int)temp[i]-48;
        p++;
    }
    int* Next = next(b);
    int* T = read_pi();
    int ans = KMP(T, Next,b);
    if(ans!=-1)
        printf("Your birthday starts at T[%d]", ans);
    else
        printf("Can't find your birthday");
    return 0;
}
int* next(int* p) {
    int* next;
    next = (int*)malloc(sizeof(int)*8);
    int i = 0;
    int j = -1;
    next[0] = -1;
    next[1] = 0;
    while(i<7)
    {
        if (j == -1 || (p[i] == p[j]))
        {
            j++;
            i++;
            next[i] = j;
        }
        else
            j = next[j];
    }
    return next;
}
int* read_pi() {
    FILE* file;
    if ((file = fopen("pi_10million_seq.txt", "rt")) == NULL)
    {
        perror("fopen");
        exit(1);
    }
    int i;
    for (i = 0; i < BLOCKSIZE; i++)
            fscanf(file, "%1d", &pi[i]);
    fclose(file);
    return pi;
}
int KMP(int* T, int* Next,int* P) {
    int j = -1;
    for (int i = 0; i < BLOCKSIZE;)
    {
        if (j == -1 || T[i] == P[j])
        {
            j++;
            i++;
            if (j > 7)
                return i-j;
        }
        else
            j = Next[j];
    }
    return -1;
}