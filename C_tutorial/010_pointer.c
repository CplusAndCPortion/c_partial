#include <stdio.h>

void test() {
    int myNumbers[4] = {25, 50, 75, 100};

    // Change the value of the first element to 13
    *myNumbers = 13;

    // Change the value of the second element to 17
    *(myNumbers +1) = 17;

    // Get the value of the first element
    printf("%d\n", *myNumbers);

    printf("pppp === %p\n", myNumbers);

    int a = 0x7ff7b57c180017 + 1;
    int b = 0x7ff7b57c180017 + 2;
    int c = 0x7ff7b57c180017 + 3;

    printf("--%x---%x ---%x--- \n",a,b,c);


    // Get the value of the second element
    printf("%d\n", *(myNumbers + 1)); // 表示把 指针 myNumbers 向后挪动一个位置
    printf("%d\n", *(myNumbers + 2));
    printf("%d\n", *(myNumbers + 3));

    printf("%d\n", *(myNumbers) + 1); // 这个却是取出 数组里第一元素分别 加 对应的数字  
    printf("%d\n", *(myNumbers) + 2);
    printf("%d\n", *(myNumbers) + 3);

}

int main(){
    /**
     * NOTE:
     *  Pointers are used to store the variables address.
     * 
     * using * sign to declare the pointer var
     * 
     */
    int a;
    int * pointer = &a;
    printf("p === %p\n", pointer);
    printf("&a == %p\n", &a);

    /**
     * Need * sign proceed on pointer to access the data which stored in the memory address.
     * You must know the `*` sign is Dereference Operator, And `&` sign is Reference Operator.
     */
    a = 90;
    printf("a_v == %d \n",*pointer);

    printf("a_v1 == %d", a);

    /**
     * 
     */

    test();
    return 0;
}