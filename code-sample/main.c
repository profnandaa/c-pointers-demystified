#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void swap1(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}

void swap2(int **a, int **b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
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
    int arr[] = { 1, 2, 3, 4, 5 };
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

    // => Character pointer
    char sl[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
    char *ps = sl;
    // notice that the length of the array will always be +1 the length of the
    // string, because of the \0
    printf("%s, length = %ld, array length = %ld\n", ps, strlen(ps), sizeof(sl));
    char *ps2 = "another hello"; // using double quotes to denote string
    printf("%s, str length = %ld\n", ps2, strlen(ps2));
    
    // the sentinel is everything when it comes to string termination
    char hackedStr[] = { 'g', 'o', '\0', 'o', 'd'};
    printf("%s, str length = %ld, array length = %ld\n", hackedStr, strlen(hackedStr), sizeof(hackedStr));

    // => Pointer to Pointer
    int y = 10;
    int *py = &y;
    int **ppy = &py;
    int ***pppy = &ppy; // we can go on and on

    printf("%p -> %p -> %p has -> %d\n", pppy, ppy, py, y);
    // we can deference any to get to our int value
    // notice the symetry in the *
    // as per the declaration
    printf("%d, %d, %d\n", ***pppy, **ppy, *py);
    // likewise you can modify through indirection
    ***pppy = 40;
    printf("%d\n", y);
    // likewise, pointer to array pointer
    int arr2[] = { 2, 5, 6, 8 };
    int *p2 = arr2;
    int **ppArr = &p2;
    printf("1st element in arr: %d\n", **ppArr);
    printf("2nd element in arr: %d\n", *(*ppArr + 1)); // notice the brackets

    // => Passing by Value vs. Reference
    int m = 30, n = 20;
    int *pm = &m, *pn = &n;
    swap1(pm, pn); // passed by value
    printf("m -> %d, n -> %d\n", *pm, *pn); // no swap done!
    // we have to pass by reference
    swap2(&pm, &pn);
    printf("m -> %d, n -> %d\n", *pm, *pn); // now swap done

    return 0;
}
