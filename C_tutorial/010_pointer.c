#include <stdio.h>

/**
 * @brief Basic concepts on pointer.
 */
void basic_pointer();

/**
 * @brief deepth comprehension on pointer and array.
 * 
 */
void pointer_array();

int main(){
    // basic_pointer();
    pointer_array();
    return 0;
}

void basic_pointer() {
    int a = 20;
    // 1. Get variable address via `&` called reference operator.
    printf("a_address = %p\n", &a);
    // 2. We need a special variable to store the variable address(reffer to step1).
    // 3. So, in C, we use pointer to point to the variable memory address.
    // 4. Pointer Declaration: using `*` sign to declare a pointer variable
    int * p = &a;
    // 5. check the value of 'p'
    printf("p == %p\n",p);
    /**
     * NOTE:
     *  - how to understand '*', '&'
     *      '&': reference operator, to get memory address of variable
     *      '*':
     *          - When in declaration, it's used to declare a pointer variable to store a sepcified variable memory address.
     *          - When not in declaration, it's used as dereference operator, that means to access the value that the variable stored.
     *  - what the relationship between value,variable,variable_address, pointer.
     *      1.when variable is created, the system will be dispatch an address.
     *      2.we all know that variable used to store value. Actually, we use variable memory address to store and manipulate value.
     *      3.the key point is variable_memory_address, each operation on value via this address.
     *      4.a pointer is a special variable that declared with '*'sign and used to store variable memory address.
     * 
     */

    printf("a == %d\n", a); //20
    printf("*p == %d\n", *p);//20

    *p = 30;
    printf("a == %d\n", a);//30

    // In a word, Maybe '*p' can be regarded as an alians of 'a'.
}

void pointer_array() {
    int numbers[] = {1,2,3}; // NOTE: must follow `[]` after numbers.
    int count = sizeof(numbers)/ sizeof(numbers[0]);

    for (int i = 0; i < count; i++)
    {
        printf("index == %d, value == %d \n", i, numbers[i]);
        /*
        index == 0, value == 1 
        index == 1, value == 2 
        index == 2, value == 3 
        */
    }

    *numbers = 30;
    for (int i = 0; i < count; i++)
    {
        printf("index == %d, value == %d \n", i, numbers[i]);
        /*
        index == 0, value == 30 
        index == 1, value == 2 
        index == 2, value == 3 
        */
    }

    /*
    Fistly, we must know that array name is a sepcial pointer(without '*' sign).

    From above on, we can know that the array name actual points to the first element of the array.
    */

   printf("numbers_address = %p\n", numbers); // 0x7ff7b114177c
   printf("the first ele address = %p\n", &numbers[0]); //0x7ff7b114177c
   /*
   Accordding to the outputs, it proves array name points to the first ele of the arr.
   numbers == &numbers[0]
   */
    printf("%d \n",*(numbers+0)); // 30
    printf("%d \n",*(numbers+1)); // 2
    printf("%d \n",*(numbers+2)); // 3

    printf("---------seperate line ------\n");

    printf("%d \n",*(&numbers[0]+0)); // 30
    printf("%d \n",*(&numbers[0]+1)); // 2
    printf("%d \n",*(&numbers[0]+2)); // 3
    /*
    the two above part is the same.
    */

    /*
    So accessing ele in array actually is the offseting of pointer.
    */

   printf("---------seperate line 'subtle mistakes'------\n");

   /**
    * NOTE:
    *   There is a subtle mistake will be appear.
    */

   int * ptr = &numbers;
   int * ptr1 = &numbers + 1; //这里是整个数组的偏移，每加1,表示偏移一个数组单元,本例中表示 12 byte
   int * ptr2 = &numbers + 2;
    printf("%p \n",ptr);  // 0x7ff7bf7ff77c
    printf("%p \n",ptr1); // 0x7ff7bf7ff788 
    printf("%p \n",ptr2); // 0x7ff7bf7ff794
    // 由上可知，每次+1,便宜12个字节,由于 &numbers 和 &numbers + 1 之间的地址偏移量实际上是按数组大小（即 3 * sizeof(int)）计算的，所以打印的地址会相差 3 个 int 元素的大小（在 64 位系统中通常为 12 字节）
    
    printf("ptr1 - ptr == %d\n", ptr1 - ptr); // 3
    printf("ptr2 - ptr1 == %lx\n", ptr2 - ptr1); // 3

    // printf("%d \n",*(&numbers+0)); // !!!! 错误的数据
    // printf("%d \n",*(&numbers+1)); // !!!! 错误的数据
    // printf("%d \n",*(&numbers+2)); // !!!! 错误的数据

    // -----


    printf("%p \n",&numbers[0]);  // 0x7ff7b114177c 
    printf("%p \n",&numbers[0]+1); // 0x7ff7b1141780
    printf("%p \n",&numbers[0]+2);  //0x7ff7b1141784
    // 每次偏移 一个 int 字节
    printf("(&numbers[0]+2) - (&numbers[0]+1) == %lx;\n(&numbers[0]+1) - (&numbers[0]) == %lx;\n",((&numbers[0]+2) - (&numbers[0]+1)),((&numbers[0]+1) - (&numbers[0])));

    printf("%d \n",*(&numbers[0]));  // 0x7ff7b114177c 
    printf("%d \n",*(&numbers[0]+1)); // 0x7ff7b1141780
    printf("%d \n",*(&numbers[0]+2));  //0x7ff7b1141784
}