#include <stdio.h>
#include <stdlib.h>

#include "./commons/helpers.h"

int main()
{
    // => Declaring
    int x = 30;
    int *px = &x;

    // => Dereferencing
    *px = 40;
    printf("%p -> %d\n", px, *px);
    printf("%p stores -> %p (px), which stores -> %d (x)\n", &px, px, *px);

    // => Null Pointer
    // int *py = 0;
    // int *pn = NULL;
    // printf("%p -> %d\n", py, *py); // causes seg-fault!



    return 0;
}
