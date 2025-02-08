#include <stdio.h>
#include <string.h>
/**
 * @brief 共用体是一种特殊的数据类型，允许在相同的内存位置存储不同的数据类型。
 *        您可以定义一个带有多成员的共用体，但是任何时候只能有一个成员带有值。共用体提供了一种使用相同的内存位置的有效方式。
 *        共用体的大小是所有成员中最大的成员的大小。
 * 
 * 共用体的作用:
 * 1. 节省内存，提高内存利用率
 * 2. 用于处理不同类型的数据
 *
 * 
 * @return int 
 */

union Data
{
    int i;
    float f;
    char str[20];
};

void test01() {
    union Data data;
    printf("Memory size occupied by data: %lu\n", sizeof(data));
    // Memory size occupied by data: 20
    data.i = 10;
    data.f = 220.5;
    strcpy(data.str, "C Programming");
    printf("data.i : %d\n", data.i);
    printf("data.f : %f\n", data.f);
    printf("data.str : %s\n", data.str);
    /**
     * data.i : 1917853763
     * data.f : 4122360580327794860452759994368.000000
     * data.str : C Programming
     * 
     * 为什么会出现i和f的值不对？
     *      因为最后赋给变量的值占用了内存位置，这也是 str 成员能够完好输出的原因。(使用共用体的时候，只能给其中一个成员赋值，如果多个成员赋值，最后一个成员的值会覆盖前面的值)
     * 
     * 如何解决上述问题？
     *      1. 同一时间只使用一个成员
     */
}

void test02() {
    union Data data;
    data.i = 10;
    printf("data.i : %d\n", data.i);
    data.f = 220.5;
    printf("data.f : %f\n", data.f);
    strcpy(data.str, "C Programming");
    printf("data.str : %s\n", data.str);
    /**
     * data.i : 10
     * data.f : 220.500000
     * data.str : C Programming
     * 这种情况下，输出的结果是正确的，因为同一时间只使用一个成员。
     */
}


int main() {
    test01();
    printf("--------------\n");
    test02();
    return 0;
}