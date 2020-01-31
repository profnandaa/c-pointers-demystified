# C/C++ Pointers Demystified

**Outline:**
- Pointers Explained
- Declaring pointers
- Dereferencing pointers
- Null pointers
- Pointers and Arrays
    - General
        - how do you tell you are at the end of the array?
    - Character Pointers
    - Incrementing pointers
- Pointer to pointer (...xN)
- Pointers and Functions
    - passing by reference
    - returning pointers
    - pointer to functions
- `malloc`, `calloc` and `free`
- Memory Leaks
- C++ Pointers - _*wont' covers this for the session!_
    - `unique_ptr`
    - `shared_ptr`
    - `make_shared`
    - References
    - RAII - _resource acquisition is initialization_

## Pointers Explained

**Pointers** are variables that store the address of another variable.
    - Allow us to _indirectly_ access variables (i.e. we can talk about its address rather than its _value_)

> add diagram here

### Importance of Pointers:

- More flexible pass-by-reference
- Manipulate complex data structures efficiently, even if their data is scattered in deferent memory locations
- Use polymorphism - calling functions on data without knowing exactly what kind of data it is. (_needs example!_)


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
- `x` is deallocated when `myFunc` exits, so the pointer that the function returns is invalid. (For instance GCC will give a warning and won't compile)


## Pointers and Arrays

- An array is a list of values arranged sequentially in memory.

## `malloc`, `calloc` and `free`

- The C library function `void *malloc(size_t size)` allocates a block of _size_ bytes of memory, returning a pointer to the beginning of the block.
- Defined in `stdlib.h`
- The function returns a pointer to the allocated memory, or `NULL` if the request fails.

## Memory Leak
- _Leak_ - failing to release a resource in a timely manner.
- Memory leak occurs when programmers create a memory in heap and forget to delete it.

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
