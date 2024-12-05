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
 * 
 *      But the variable that defined in function is not belog static memory, 
 *      it's in Stack Memory. And will be allocated dynamically.
 * 
 *  Dynamic Memory:
 *      Allocate memory after program running. This can also be called as a runtime memory allocation. Always use 'malloc' or 'calloc' functions that will be return a pointer.
 *      Dynamic Memory does not belog to variable, it can only be accessed with pointers.
 *      
 *      Stack Memory, belog to dynamic memory.
 *      when a function is called, stack memory is allocated for the variables in functions.
 *      when the function returns the stack memory is freed.
 *      (You can analyse recursion function through this epitome)
 * 
 */
void allocate_memory();

/**
 * In this section, we say access memory reffer to access dynamic memeoy.
 * 
 * Dynamic memory behaves like an array, with its data type specified by the type of the pointer.
 * 
 * NOTE, 
 *      Dynamic memory does not have it's own data type, it just a sequence of bytes.
 *      The Data Type in the memory is determined by the pointer type.
 * 
 */
void access_memory();

/**
 * @brief If the memory size you reserved is not enough, you can make it larger through reallocate function.
 *        for more click https://www.w3schools.com/c/c_memory_reallocate.php
 * 
 */
void reallocate_memory();


int main (int agrc, char* argv[]) {
    
    // get_memory_size();

    // allocate_memory();

    // access_memory();

    reallocate_memory();

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
    int *ptr1, *ptr2, *ptr3; ;
    /**
     * both pt1 and pt2 are pointer.
     * Crisis: Do not access a pointer without initialization.
     */
    // printf("ptr1 == %p \n",ptr1);
    // printf("ptr2 == %p \n",ptr2);
    printf("sizeof(*ptr1) == %lu \n",sizeof(*ptr1));
    printf("sizeof(*ptr2) == %lu \n",sizeof(*ptr2));
    printf("-------seperate line ------ \n");

    // malloc and calloc functions will assign memory address to corresponse pointer.
    ptr1 = malloc(sizeof(*ptr1)); 
    ptr2 = calloc(2, sizeof(*ptr2));
    ptr3 = malloc(sizeof(*ptr3));
    printf("ptr1 == %p \n",ptr1);
    printf("ptr2 == %p \n",ptr2);
    printf("ptr3 == %p \n",ptr3);
    /*
    输出的结果可能会变化
    ptr1 == 0x7fd7d6104080 
    ptr2 == 0x7fd7d6104090 
    ptr3 == 0x7fd7d61040a0 
    看一下这个地址，ptr1,ptr2,ptr3分别分配了 4,8,4字节，为什么内存地址却相差16个字节呢?
    答案是系统在分配内存的时候是根据内存块或者内存单元来开辟内存空间的，而这个内存块或者内存单元的单位是16字节,所以不足16字节会按照16字节分配。

    也可以通过下面的案例继续验证
    */
   
    ptr1 = malloc(32); 
    ptr2 = calloc(3, 16);
    ptr3 = malloc(48);
    printf("ptr1_ == %p \n",ptr1);
    printf("ptr2_ == %p \n",ptr2);
    printf("ptr3_ == %p \n",ptr3);
    /*
        ptr1 == 0x7ff75a705a40 
        ptr2 == 0x7ff75a705a50 
        ptr3 == 0x7ff75a705a60 
        ptr1_ == 0x7ff75a705a70 
        ptr2_ == 0x7ff75a705a90 
        ptr3_ == 0x7ff75a705ac0 
        ptr1_到ptr2_之间差了 2 个 16byte, 因为我们给pt1 分配了 32个字节
        ptr2_到ptr3_之间差了 3 个 16byte, 因为我们给pt2 分配了 3个 16字节
     */


    /**
     * 由于 ptr1 和 ptr2 指向 int 类型的内存区域
     * sizeof(*ptr1) 和 sizeof(*ptr2) 输出的结果
     * 都会是 int 类型的大小（通常为 4 字节）
     */
    printf("sizeof(*ptr1) == %lu \n",sizeof(*ptr1));
    printf("sizeof(*ptr2) == %lu \n",sizeof(*ptr2));

    printf("*ptr1 == %d \n",*ptr1);
    printf("*ptr2 == %d \n",*ptr2);

    

}

void allocate_memory() {
    // static_memory_();
    dynamic_memory_();
}

void access_memory() {
    int *ptr;
    ptr = calloc(4, sizeof(*ptr));
    ptr[0] = 40;
    ptr[1] = 30;
    ptr[2] = 50;
    ptr[3] = 70;

    // Read from the memory
    printf("%d\n", *ptr); // 40 
    printf("%d %d %d %d", ptr[0], ptr[1], ptr[2], ptr[3]); //40 30 50 70
}

void reallocate_memory() {
    int *ptr1, *ptr2, size;
    size = 3 * sizeof(*ptr1);
    ptr1 = malloc(size);
    printf("%d bytes allocated at address %p \n", size, ptr1);
    // 12 bytes allocated at address 0x7f9819705a40 

    // Resize the memory to hold six integers
    size = 6 * sizeof(*ptr1);
    ptr2 = realloc(ptr1, size);

    printf("%d bytes reallocated at address %p \n", size, ptr2);
    // 24 bytes reallocated at address 0x7f9819705a40 

    /**
     * @brief 为避免内存泄漏,你必须在使用完成之后释放内存!
     * 
     */
    free(ptr1);
   

}