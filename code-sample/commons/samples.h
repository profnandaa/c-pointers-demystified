struct Person {
    char* name;
    int age;
};

// this truly modifies the struct
// pointed at
void modifyStruct(struct Person *p)
{
    p->name = "Modified Name";
}


// this modifies the copy of the struct
// passed to it, but then that is it
// the original remains unchanged
void modifyStruct2(struct Person p)
{
    p.name = "Modified Name";
}

// this will crash the caller
// if they don't check for null pointer
// x is deallocated once myFunc returns
// supposedly "pointer-to-x" is null.
int *myFunc()
{
    int x = 30;
    // return &x; // gcc won't compile
    return 0;
}

