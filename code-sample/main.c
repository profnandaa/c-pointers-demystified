#include <stdio.h>
#include <stdlib.h>

#include "./commons/helpers.h"

int sumArray(int *arr, int sz)
{
    int sum = 0;
    for (int i = 0; i < sz; ++i)
    {
        sum += *(arr + i); // or sum += arr[i]
    }
    return sum;
}

int sumArray2(int arr[], int sz)
{
    int sum = 0;
    for (int i = 0; i < sz; ++i)
    {
        sum += *(arr + i); // or sum += arr[i]
    }
    return sum;
}

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
    // printf("%p -> %d\n", py, *py); // causes seg-fault (always)!
    // int *pz;
    // printf("random *pz -> %d\n", *pz); // causes seg-fault too (sometimes)!

    // => Pointers and Arrays
    int arr[] = { 1, 2, 3 };
    printf("%d, %d, %d\n", *arr, *(arr + 1), *(arr + 2));

    printf("sum -> %d\n", sumArray(arr, 3));
    printf("sum -> %d\n", sumArray2(arr, 3));

    // but then, there's no way of validating a 
    // pointer to array
    // AFAIK (hit me up if you know one)
    printf("fake sum -> %d\n", sumArray(px, 3));
    printf("fake sum -> %d\n", sumArray(px, 300));

    // => Incrementing Pointers
    int *p = arr;   // points to the first element in arr
    p++;            // now p is pointing at the 2nd element
    printf("p -> %d\n", *p); // prints 2
    printf("p -> %d\n", *(++p)); // prints 3

    return 0;
}
