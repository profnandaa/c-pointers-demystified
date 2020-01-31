#include <stdio.h>

void trav(int *arr)
{
    printf("after %p -> %d\n", arr, *arr++);
    printf("%p -> %d\n", arr, *arr);
    printf("%p -> %d\n", arr + 1, *(arr + 1));
    printf("%p -> %d\n", arr + 1, *(arr + 4));
    // arr + 1
}

void trav2(int **arr)
{
    printf("%p -> %p -> %d\n", arr, *arr, *(*arr)++);
    // printf("after %p -> %d\n", arr, *arr++);
}

int main()
{
    
    // pointer to pointer
    // p -> p -> p -> v
    // int x = 10;
    // int *px = &x;
    // int **ppx = &px;

    // printf("%p -> %p -> %d\n", ppx, px, *px);
    // printf("%p -> %p -> %d\n", ppx, px, **ppx);


    int a[] = { 1, 3, 4, 5, 6, 8 }; // int *a = { 1, 2, 3, 4, 5 } // does not work! -> revisit malloc, callow
    trav(a);
    printf("first val -> %d\n", *a);

    int* pa = a; // force the a to decay into a pointer (int*)
    int** ppa = &pa;
    trav2(&pa); // trav2(ppa);
    printf("first val -> %d\n", *a);
    printf("'first val' -> %d\n", *pa);

    return 0;
}


// printf("hello, pointer world!\n");

    // int a = 10;

    // int *pa = &a;
    // printf("%p -> %d\n", pa, a);
    // a = 30;
    // printf("%p -> %d\n", pa, a);
    // printf("addr of pa -> %p\n", &pa);

    // printf("%p -> %p -> %d\n", &pa, pa, *pa);

    // // int b = 300;
    // // int *pb;

    // int *nptr = NULL;
    // // printf("%p -> %d\n", nptr, *nptr);

    // int x;
    // printf("%d\n", x);

    // a[0] -> 1
    // a decays to a pointer - G.K
    // `a` is a special pointer - PN

    // printf("%d\n", sumArray(a));