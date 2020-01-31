#include <stdio.h>
#include <stdlib.h>

#include "./commons/helpers.h"
#include "./commons/samples.h"

int sum(int a, int b)
{
    return a + b;
}

int diff(int a, int b)
{
    return a - b;
}

int main()
{
    // printLine("hello world! %d, %d", 20, 20);
	printf("hello, pointer world!\n");
	int a = 20;
	int *pA = &a;

    // gotcha on declaring pointers
    int *px, x;    // here you have declared an int pointer px and 
                    // a normal integer y.
	// I'd suggest that the star be alway put before the var name
    // to avoid confusion, i.e.
    // int *px, *py;

    // = changing the value pointed to by the pointer.
    px = &x;
    *px = 30;
    printf("%p -> %d\n", px, x);
    // = Dereferencing a pointer (*p) which had not been initialized
    // provokes undefined behavior
    // however, when allocating space to a pointer, you want to
    // allocate to it memory with the size of what it is
    // pointing to by using sizeof operator. This is the only
    // exception to the rule:
    struct Person ***p;
    p = malloc(sizeof *p);
    *p = malloc(sizeof **p);
    **p = malloc(sizeof ***p);
    (**p)->name = "Peter Pointer";
    (**p)->age = 34;
    printf("%s, %d\n", (**p)->name, (**p)->age);
	
    free(**p);
    free(*p);
    free(p);
    // ^ this also explains, pointer to pointer...
    
	// pointer to array
	int B[5] = { 10, 20, 30, 40, 50 };
    printArray("B", B, 5);
	// aB is already a pointer to array
	int *pArray = B;
	// print first element in array
	printf("1st element in aB -> %i\n", *pArray);
    printf("2nd element in B -> %i\n", *(pArray + 1)); // word of bugs -> *pArray + 1
    // let's create a mirror array of pointers,
    // pointing at their counterparts in aB
    
    int *mB[5];
    int i = 0;
    while (i < 5) {
        mB[i] = &B[i];
        i++;
    }

    printf("1st shadow element in mB -> %d\n", *mB[0]);
    printf("5th shadow element in mB -> %d\n", *mB[4]);
    printf("5th shadow element address in mB -> %p\n", mB[4]);

    // now we want to rearrange the logical order for
    // the shadow elements
    printf("%p -> %p -> %d\n", &mB[4], mB[4], *mB[4]);
    swap(&mB[4], &mB[3]);
    printf("5th shadow element address in mB -> %p\n", mB[4]);
    printMirrorArray("mB", mB, 5);
    printArray("B", B, 5);

    // structs and pointers
    struct Person p1 = { "Dennis R.", 78 };
    printf("name: %s\n", p1.name);
    modifyStruct(&p1);
    printf("name: %s\n", p1.name);

    struct Person p2 = { "Anthony N.", 37 };
    printf("name: %s\n", p2.name);
    modifyStruct2(p2);
    printf("name: %s\n", p2.name);

    // = null pointers
    // dereferencing null ptr crushes
    // printf("null ptr -> %i\n", *(myFunc()));

    // = Pointers and Functions
    int (*sum_ptr)(int, int) = &sum;
    printf("sum of 3 and 4 = %d\n", (*sum_ptr)(3, 4));
    // or
    int (*sum_ptr2)(int, int) = sum;
    printf("sum of 3 and 4 = %d\n", sum_ptr2(3, 4));
    // array of pointers to functions
    int (*ptr_array[])(int, int) = { sum_ptr, sum_ptr2, &diff };
    printf("sum of 10 and 2 = %d\n", ptr_array[0](10, 2));
    printf("diff of 10 and 5 = %d\n", ptr_array[2](10, 5));
     
	return 0;
}
