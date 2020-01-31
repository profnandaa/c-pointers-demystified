// Rodney's Challenge
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void allocate(char ***pppArray, int nSize, char *szName, int nLoc) {
  // // implement
  // if (!pppArray) return;
  // char *s[nSize];
  // s[nLoc] = szName; 
  // *pppArray = &s;
}

void leak(int **arr)
{
  int a[] = { 1, 2, 3 };
  *arr = a;
}

void leak2(int **a)
{
  int b = 30;
  *a = &b;
}

void leakForReal(int **arr)
{
  int* a = (int*)calloc(3, sizeof(int));
  a[0] = 400;
  a[1] = 6;
  a[2] = 10;

  *arr = a;
}

int doSomething()
{
  int a = 5;
  char* name = "MS";
  return strlen(name);
}

int main()
{
  int *a, *b, *r;
  leak(&a);
  leak2(&b);
  leakForReal(&r);
  printf("%d, %d, %d\n", a[0], *b, r[0]);
  doSomething(); // stack is "corrupted"
  // now pointing to gabbage, to be collected
  printf("%d, %d, %d\n", a[0], *b, r[0]);

  return 0;
}