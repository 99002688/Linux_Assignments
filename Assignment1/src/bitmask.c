#include <stdio.h>
#include "../include/bitmask.h"
#include <stdbool.h>

int setBit(int n, int k)
{
    return (n | (1 << (k - 1)));
}


int resetBit(int n, int k)
{
    return (n & (~(1 << (k - 1))));
}

int flip(int n)
{
    return (n^1);
}

int query(int n, int k)
{
    if(n & (1 << (k - 1))){
        printf("SET");}
    return 1;
}

