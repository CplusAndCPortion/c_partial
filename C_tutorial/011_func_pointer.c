#include <stdio.h>
// 函数指针
/**
 * @brief 函数指针也是一个指针变量，只不过该指针变量指向的是函数的地址
 * 
 * @return int 
 */
typedef int (*Func_ptr)(int, int); //此处是声明了一个函数指针类型(Func_ptr)，该函数指针类型指向的函数的返回值是int，参数是两个int

/**
 * @brief 这个函数就是一个复合上述函数指针类型的函数
 * 
 * @param a 
 * @param b 
 * @return int 
 */
int add(int a, int b) {
    return a + b;
}

int main() {
    int a = 1, b = 2;
    Func_ptr ptr = add; //声明一个函数指针变量ptr，并将其指向add函数
    int sum = ptr(a, b); //调用add函数
    printf("sum = %d\n", sum);
    printf(" add = %p\n", add);
    printf(" ptr = %p\n", ptr);
    return 0;
}