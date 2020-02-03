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
- [Pointer to pointer, and on ...](#pointer-to-pointer)
- [Pointers and Functions](#pointers-and-functions)
    - passing by reference
    - returning pointers
    - pointer to functions
- [`malloc`, `calloc` and `free`](#malloc-calloc-and-free)
- [Memory Leaks](#memory-leaks)
- C++ Pointers
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
> My own preference and the prevalent practice is to put the `*` just before the name of the variable as opposed to putting it after the type, as some do. The later is also misleading when you have a list of variables in one line, e.g. `int* ptr, x, y` vs. `int *ptr, x, y`.

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
    // somewhere in memory and we can get it's location 
    // by &px, e.g.
    printf("%p\n", &px);
    // so
    printf("%p stores -> %p (px), which stores -> %d (x)\n", &px, px, *px);
    ```

## Null Pointers

- Any pointer set to `0` is called a _null pointer_, since there's no memory location `0`, it is an invalid pointer.
- Dereferencing such a pointer leads to a runtime error. One should check whether the pointer is null before dereferencing it.

    ```c
    int *myFunc()
    {
        int x = 30;
        return &x;
    }
    ```
- `x` is deallocated when `myFunc` exits, so the pointer that the function returns is invalid. (For instance GCC will give a warning and won't compile).


## Pointers and Arrays

- An array is a list of values arranged sequentially in memory.

## Pointer to Pointer
TBD

## Pointers and Functions

### passing by reference
TBD

### returning pointers
TBD

### pointer to functions
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
