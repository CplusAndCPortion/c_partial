#include<stdio.h>
#include<string.h>
#include <stdlib.h>

/**
 * OverView:
 *  Memory management is very importane section in C.
 *  It is the process of handling how much memory a program uses via different operations.
 */

/**
 * @brief Get the memory size object using 'sizeof';
 * 
 */
void get_memory_size();

/**
 * @brief allocate_memory
 * 
 * The process of reserving memory is called allocation.
 * The way to allocate memory depends on the type of memory [Static memory and Dynamic memory].
 *  Static Memory: 
 *      that is reserved for variables before the  program runs. Allocation of 
 *      static memory is also known as compile time memory alloction.
 *      C allocates memeory for each variable automatically when the program is compiled.
 *  Dynamic Memory:
 *      Allocate memory after program running. This can also be called as a runtime memory allocation. Always use 'malloc' and 'calloc' functions.
 * 
 */
void allocate_memory();


int main (int agrc, char* argv[]) {
    
    // get_memory_size();

    allocate_memory();

    return 0;

}

void get_memory_size() {
    int myInt;
    float myFloat;
    double myDouble;
    char myChar;

    printf("%lu\n", sizeof(myInt));      // 4 bytes
    printf("%lu\n", sizeof(myFloat));    // 4 bytes
    printf("%lu\n", sizeof(myDouble));   // 8 bytes
    printf("%lu\n", sizeof(myChar));     // 1 byte

    // also you can replace the variable name with its type
    printf("----seperate line----- \n");
    printf("%lu\n", sizeof(int));      // 4 bytes
    printf("%lu\n", sizeof(float));    // 4 bytes
    printf("%lu\n", sizeof(double));   // 8 bytes
    printf("%lu\n", sizeof(char));     // 1 byte

}

/**
 * @brief static memory allocation reffer to the process of compile time generally. It mainly allocate memory for the variable depending on its data type.
 *  such as `int arr[10]`, system will allocate 40 bytes for arr after compilation process.
 */
void static_memory_() {
    int arr[10];
    // C allocates memeory for arr automatically when the program is compiled.
    printf("arr size == %lu \n", sizeof(arr)); // 40 

}

void dynamic_memory_() {
    int *ptr1, *ptr2;
    printf("%p \n",ptr1);
    printf("%p \n",ptr2);
    ptr1 = malloc(sizeof(*ptr1));
    // ptr2 = malloc(sizeof(*ptr2));
    ptr2 = calloc(2, sizeof(*ptr2));

    // printf("%lu \n",sizeof(ptr1));
    printf("%lu \n",sizeof(*ptr1));
    printf("%lu \n",sizeof(*ptr2));

    printf("%d \n",*ptr2);
}

void allocate_memory() {
    // static_memory_();
    dynamic_memory_();
}