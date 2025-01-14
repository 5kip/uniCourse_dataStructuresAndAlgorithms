#inlcude <stdlib.h>
#include <iostream>

// This program was designed to show you how the stack works.
// You shouldn't dereference pointers which are no longer in scope.
// Never do that, it's undefined behavior (anything can happen).

// Note that this program may break if you use optimizations.
// Also, I have only tried it on Zig C++ (Clang) on Windows.

// Also note, that this produces a warning on Zig C++ (Clang), which is expected.

int* stackMemory1()
{
    int a = 1;
    return &a;
}

int* stackMemory2()
{
    int a = 2;
    return &a;
}

int main()
{
    int* b = stackMemory1();
    int a1 = *b;
    int* c = stackMemory2();
    int a2 = *c;
    int a3 = *b;

    std::cout << a1 << std::endl; // prints 1
    std::cout << a2 << std::endl; // prints 2
    std::cout << a3 << std::endl; // prints 2
    std::cout << ((std::byte*) b - (std::byte*) c) << std::endl; // prints 0, pointers are equal

    return 0;
}