// #ifdef DEBUG
// # define DEBUG_PRINT(x) printf x
// #else
// # define DEBUG_PRINT(x) do {} while (0)
// #endif

// Helper functions

void printArray(char* varName, int* a, int sz)
{
    printf("%s => [ ", varName);
    int cnt = 0;
    while (cnt < sz)
    {
        // don't add `,` on the last element
        char sep = cnt == (sz - 1) ? '\0' : ',';
        printf("%d%c ", *a, sep);
        cnt++;
        // increment pointer to the next mem location/segment
        a++;
    }
    printf("]\n");
}

void printMirrorArray(char* varName, int** a, int sz)
{
    printf("%s => [ ", varName);
    int cnt = 0;
    while (cnt < sz)
    {
        // don't add `,` on the last element
        char sep = cnt == (sz - 1) ? '\0' : ',';
        printf("%d%c ", **a, sep); // only change made btw the prev func: **a
        cnt++;
        // increment pointer to the next mem location/segment
        a++;
    }
    printf("]\n");
}

void swap(int** a, int** b)
{
    printf("%p, %p\n", *a, *b);
    int* temp = *a;
    *a = *b;
    *b = temp;
    printf("%p, %p\n", *a, *b);
}

// write own printLine

// challenge!
// then update ans: https://stackoverflow.com/questions/36410146/c-creating-a-printline-function
// int printLine(const char *format, ...)
// {
//     va_list args;
//     va_start(args, *format);
//     printf("%s\n", args);
// }
