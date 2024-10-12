#include <stdio.h>
#include <stdlib.h>

void test_arr_1() {

    int arr[] = {41,52,63,74};

    printf("%p\n", &arr[0]);
    printf("%p\n", arr);
    printf("%d\n", arr[0]);
    printf("%d\n", *arr);

}

void test_arr_2() {
    int *arr; //  注意:这里是声明一个指针变量；表示 arr 是一个指向 int 类型变量的指针

    /*

    *arr = calloc(4, sizeof(*arr));

    上面的写法是错误的，
     *arr DeReference.表示解引用，即访问指针所指向的内存地址中的值。表示访问 arr 所指向的地址的值，
    */

   arr = calloc(4, sizeof(*arr));  // sizeof(*arr) 表示 arr 指向的数据类型的大小。

   printf("arr[0]  == %d \n", arr[0]); //0
   printf("arr[1]  == %d \n", arr[1]); //0
   printf("arr[2]  == %d \n", arr[2]); //0
   printf("arr[3]  == %d \n", arr[3]); //0

   arr[0] = 41;
   arr[1] = 52;
   arr[2] = 63;
   arr[3] = 74;

   printf("arr[0]  == %d \n", arr[0]); 
   printf("arr[1]  == %d \n", arr[1]); 
   printf("arr[2]  == %d \n", arr[2]); 
   printf("arr[3]  == %d \n", arr[3]); 

   printf("*arr  == %d \n", *arr); 

   printf("*arr_p  == %p \n", arr); 
   printf("*arr_p  == %p \n", arr + 1); 
   printf("*arr_p  == %p \n", arr + 2); 
   printf("*arr_p  == %p \n", arr + 3); 


   printf("*arr_p_v  == %d \n", *(arr)); 
   printf("*arr_p_v  == %d \n", *(arr + 1)); 
   printf("*arr_p_v  == %d \n", *(arr + 2)); 
   printf("*arr_p_v  == %d \n", *(arr + 3)); 




    
}

void test_3() {
    int *ptr1 = malloc(4);
    char *ptr2 = (char*) ptr1;
    ptr1[0] = 1684234849;

    printf("sss == %p \n",ptr1);

    printf("%d is %c %c %c %c", *ptr1, ptr2[0], ptr2[1], ptr2[2], ptr2[3]);
}


int main(){
    // test_arr_1();
    // test_arr_2();
    test_3();
    return 0;
}