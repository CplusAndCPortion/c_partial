#include <stdio.h>

void analyse_main_func(int num, char *args[]);

// 下面连个方法等价
void array_as_func_param(int arr[], int size);
void array_as_func_param_(int *arr, int size);

/**
 * @brief main entrance
 * 
 * @param num args num
 * @param args 表示指向字符串指针的数组，里面存储的都是指向字符串的指针
 * @return int , the terminate sign
 */
int main(int num, char *args[]){
    
    // analyse_main_func(num, args);

    int myNumbers[] = {1, 2, 3, 0, 5};
    /*
    既然数组名其实是指向第一个元素的地址，那为什么 sizeof(numbers) 在定义数组之后，能获取到其大小呢？而在调用函数传递时，函数内部的sizeof(numbers) ,却获取不到数组的大小呢？
    1. 数组在定义的时候，myNumbers 是一个常量指针，不只是包含收个元素的地址信息，还涵盖数组占用内存的大小，如上案例，当数组 myNumbers 在编译的时候，编译其会将其识别为 int[5] 的类型(数组中有五个元素)； 因此sizeof(myNumbers),在此时指的是`int[5]`类型所占有的存储大小
    2. 数组名退化为指针；在将数组传递给函数，或者对数组进行额外操作比如修改元素，数组名都会退化成指针，比如本案例中会退化成 `int * ` 类型的指针；数组退化为指针的行为是 C 语言中的一个重要特性，这样做是为了简化内存管理和提高效率。因此在座位函数参数传递时，传递本质是数组第一个元素的地址，为了获取整个数组的大小，还需要额外传递数组的大小，
    */
    int size = sizeof(myNumbers)/sizeof(myNumbers[0]);
    array_as_func_param(myNumbers, size);
    printf("-----------------\n");
    array_as_func_param_(myNumbers, size);
    return 0;
}


void array_as_func_param(int arr[], int size) {
  int count = size;
  for (int i = 0; i < count; i++)
  {
    printf("index == %d; value == %d\n", i, arr[i]);
  }
}

void array_as_func_param_(int *arr, int size) {
  int count = size;
  for (int i = 0; i < count; i++)
  {
    printf("index == %d; value == %d\n", i, arr[i]);
  }
}

void analyse_main_func(int num, char *args[]) {
int count = num;
    for (int i = 0; i < count; i++)
    {
        /* code */
        printf("arg[%d] == %s\n",i,args[i]);
    }
}