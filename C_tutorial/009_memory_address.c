#include <stdio.h>

int main() {
    /**
     * when a variable is created, a memory address is asgined to the variable;
     * 
     * & is a reference operator.
     */

    int a;
    a = 5;
    printf("a memory address is %p",&a);
    // a memory address is 0x7ff7b61d6828

    return 0;
}