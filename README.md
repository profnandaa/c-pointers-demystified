# C/C++ Pointers Demystified

**Outline:**
- [Pointers Explained](#pointers-explained)
- [Declaring pointers](#declaring-pointers)
- [Dereferencing pointers](#dereferencing-pointers)
- [Null pointers](#null-pointers)
- [Pointers and Arrays](#pointers-and-arrays)
    - General
    - Character Pointers
    - Incrementing pointers
- [Pointer to Pointer](#pointer-to-pointer)
- [Pointers and Functions](#pointers-and-functions)
    - passing by reference
    - returning pointers
    - pointer to functions
- [`malloc`, `calloc` and `free`](#malloc-calloc-and-free)
- [Memory Leaks](#memory-leaks)
- [C++ Pointers](#c-pointers)
    - References
    - RAII - _resource acquisition is initialization_
    - `unique_ptr`
    - `shared_ptr`
    - `make_shared`

> **ℹ Note** <br/>
> All the code sample used below can be found in [`main.c`](code-sample/main.c).

## Pointers Explained

**Pointers** are variables that store the address of another variable.
    - Allow us to _indirectly_ access variables (i.e. we can talk about its address rather than its _value_)

> add diagram here

### Importance of Pointers:

- More flexible pass-by-reference
- Manipulate complex data structures efficiently, even if their data is scattered in deferent memory locations
- Use polymorphism - calling functions on data without knowing exactly what kind of data it is. (_needs example!_)

## Declaring Pointers

Simply `<type> *<var_name>;`, e.g.

```c
int *ptr;
```
The pointer can then be initialized to a memory address for a variable, which is found by using `&`, e.g.

```c
int x = 30;
int *px = &x;
```

> ℹ **Note** <br/>
> My own preference and the prevalent practice is to put the `*` just before the name of the variable as opposed to putting it after the type, as some do. The later is also misleading when you have a list of variables in one line, e.g. <br/>`int *ptr, x, y` vs. `int* ptr, x, y`. <br/>(`x` and `y` are just integers but the later may make it look like all are pointers!)

## Dereferencing Pointers

- To dereference a pointer is to get the value of what the pointer is pointing to.
- We use `*<pointer_pointer_var_name>`, for example:
    ```c
    int x = 30;
    int *px = &x;
    *px = 40; // changes x
    // print memory address of where px is pointing 
    // at (px) and the value in the address (*px)
    printf("%p -> %d\n", px, *px); 
    // also note that the pointer also is stored 
    // somewhere in memory and we can get its location 
    // by &px, e.g.
    printf("%p\n", &px);
    // so
    printf("%p stores -> %p (px), which stores -> %d (x)\n", &px, px, *px);
    ```

## Null Pointers

- Any pointer set to `0` is called a _null pointer_, since there's no memory location `0`, it is an invalid pointer.
- Dereferencing such a pointer leads to a runtime error. One should check whether the pointer is null before dereferencing it.

    ```c
    int *py = 0; // or int *py = NULL;
    printf("%d\n", *py); // seg-fault!
    ```
- You may ask, what's the point for _null pointers_? Null pointers are very important for initializing pointers which will point to proper memory addresses later on, but they are not yet determined. If we declared `int *pz;` without initializing it, the compiler (GCC in my case), will point `pz` to a random memory address ("allocate"). However, this is not guaranteed, will _seg-fault_ too, sometimes.
    ```c
    int *pz;
    printf("%d\n", *pz);
    ```

## Pointers and Arrays

- An array is a list of values arranged sequentially in memory.
- The variable name of the array is usually _a special kind of pointer_, it can decay into a pointer; as we will see below:

    ```c
    int arr[] = { 1, 2, 3 }; // `arr` decays into int* (int pointer)
    ```
- Therefore, `arr` in the example above is equivalent to an `int*`. `arr` is a pointer pointing to the beginning of the array.
- To get the first element of the array, we will use `*arr`.
- To get the second element of the array, we use `*(arr + 1)`
- Therefore to get the _nth_ element of the array we will use `*(arr + n - 1)`.

    ```c
    int arr[] = { 1, 2, 3 };
    printf("%d, %d, %d\n", *arr, *(arr + 1), *(arr + 2));
    ```
- Let's look at an example for summing up numbers in an array:
    ```c
    int sumArray(int *arr, int sz)
    {
        int sum = 0;
        for (int i = 0; i < sz; ++i)
        {
            sum += *(arr + i); // or sum += arr[i]
        }
        return sum;
    }
    ```
    - `sumArray` takes in a pointer to an array and the size of that array.
    - However, there's not way of telling (AFAIK) that that pointer truly points to an array, it could as well just be an ordinary pointer to an int. For instance of if we gave `x` (from our example in the beginning) to this function, it will compile correctly and it may even run without a seg-fault!
        ```c
        printf("fake sum -> %d\n", sumArray(px, 3));
        // if you thought that's enough, try this!
        printf("fake sum -> %d\n", sumArray(px, 300));
        // 300 contiguous memory addresses
        // from px are summed up
        ```
    - This is the same reason why strings (array of chars) have a sentinel value `\0` at the end that signifies the end of the array (aka, _the null terminator_).

    > **ℹ Note** <br/>
    > In the next section, we will look at pointer-to-pointer. It is worth noting here that `&arr` in our example above will be an `int**` (pointer to pointer, or address of a pointer `arr`), since `arr` is `int*`.

### Incrementing Pointers

Since pointers point to memory addresses which are contiguous, it is therefore possible to increment a pointer to move to the next address. The pointer will step according to it's size, e.g. `int *` will be stepping 32 bits (4 bytes) each.

Let's look at an example:

```cpp
int arr[] = { 1, 2, 3, 4 };
int *p = arr;   // points to the first element in arr
p++;            // now p is pointing at the 2nd element
printf("p -> %d\n", *p);
printf("p -> %d\n", *(++p)); // pointer now pointing to the 3rd
```
This should be done strictly for _guaranteed_ contiguous memory addresses, i.e. arrays, and you should know where the end is (where to stop).

### Character Pointers

In C, we create a _string_ by using an array of characters (loosely). A pointer pointing to this array is therefore a character pointer.

> _It will be insane to just have one pointer pointing to one char, what's the point?_

Now, how do we tell we have reached the end of our "string"? We use a null terminator `\0`. That is when it is a proper string, else, it's just an array of characters.

Let's look at an example:
```cpp
char s[] = { 'h', 'e', 'l', 'l', 'o', '\0' };
char *ps = s;
// notice that the length of the array will always be +1 the length of the
// string, because of the \0
printf("%s, str length = %ld, array length = %d\n", ps, strlen(ps), sizeof(sl));
// a shorter way to initalize this:
char *ps2 = "another hello"; // using double quotes to denote string
printf("%s, length = %ld\n", ps2, strlen(ps2));
```

As we had mentioned earlier, there is no way to know you have reached the end of an array, unless you put a _sentinel_ value to mark the end. We use `\0` to mark the end of a string. For instance, this:
```cpp
char hackedStr[] = { 'g', 'o', '\0', 'o', 'd'};
printf("%s, str length = %ld, array length = %ld\n", hackedStr, strlen(hackedStr), sizeof(hackedStr));
```

## Pointer to Pointer

We can have a pointer pointing to a pointer, and even another pointer pointing to the/that pointer (`pointer -> pointer -> pointer`).

Let's look at a simple example:
```cpp
int y = 10;
int *py = &y;
int **ppy = &py;
int ***pppy = &ppy; // we can go on and on

printf("%p -> %p -> %p -> %d\n", pppy, ppy, py, y);
// we can deference any to get to our int value
// notice the symetry in the *
// as per the declaration
printf("%d, %d, %d\n", ***pppy, **ppy, *py);
// likewise you can modify through indirection
***pppy = 40;
printf("%d\n", y);
```

Likewise, you can have a pointer that points to the array pointer, eg:
```cpp
int arr2[] = { 2, 5, 6, 8 };
int *p2 = arr2;
int **ppArr = &p2;
printf("1st element in arr: %d\n", **ppArr);
printf("2nd element in arr: %d\n", *(*ppArr + 1)); // notice the brackets
```
> _We will see why this is important when we look at the the next section on passing by value and by reference._

## Pointers and Functions

### Passing by Value vs. by Reference

A pointer is a _value_ too, only that that value is a reference. Let that sink.

Therefore you can pass a pointer to a function _by value_ or _by reference_. Reference here will be a pointer to that pointer.

To illustrate this, let's look at the following example:
```cpp
void swap1(int *a, int *b)
{
    int *temp = a;
    a = b;
    b = temp;
}

int m = 30, n = 20;
int *pm = &m, *pn = &n;
swap1(pm, pn); // passed by value
printf("m -> %d, n -> %d\n", *pm, *pn); // no swap done!
```
Basically, we just passed by value (a copy of the pointers) to the function, and therefore, our original pointers remained untouched.

We have to pass by by refeference (a pointer to the pointer):
```cpp
void swap2(int **a, int **b)
{
    int *temp = *a;
    *a = *b;
    *b = temp;
}

int m = 30, n = 20;
int *pm = &m, *pn = &n;

swap2(&pm, &pn);
printf("m -> %d, n -> %d\n", *pm, *pn); // now swap done
```

### Returning Pointers
TBD

### Pointer to Functions
TBD

## `malloc`, `calloc` and `free`

- The C library function `void *malloc(size_t size)` allocates a block of _size_ bytes of memory, returning a pointer to the beginning of the block.
- Defined in `stdlib.h`
- The function returns a pointer to the allocated memory, or `NULL` if the request fails.

TBD

## Memory Leaks
- _Leak_ - failing to release a resource in a timely manner.
- Memory leak occurs when programmers create a memory in heap and forget to delete it.

## C++ Pointers

TBD

**Rodney's Challenge:**

```c
void allocate(char*** pppArray, int nSize, char* szName, int nLoc) {
  // implement
}
```

### Reference Material

- [MIT 6.096 Lecture 5 Notes, 2011](https://ocw.mit.edu/courses/electrical-engineering-and-computer-science/6-096-introduction-to-c-january-iap-2011/lecture-notes/MIT6_096IAP11_lec05.pdf)
- [mycodeschool YouTube playlist - "C/C++ Pointers"](https://www.youtube.com/watch?v=h-HBipu_1P0&list=PL2_aWCzGMAwLZp6LMUKI3cc7pgGsasm2_&index=2&t=0s)

### Further Reading

- [Linux source-code](https://elixir.bootlin.com/linux/latest/source)
- [Git source-code](https://github.com/git/git)
