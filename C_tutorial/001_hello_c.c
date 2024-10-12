#include <stdio.h>
#include <stdbool.h>

void test01_basic() {
    printf("Hello World!\n");
    printf("I am learning C.\n");
    printf("And it is awesome! \n");

    char c = 'a';
    printf("%c \n",c);

    int a = 97;
    printf("%c \n",a);

    bool b = false;
    printf("%d",b);

    // printf("\n--------");

    int numbers[] = {11,22,33,44,55};

    int count = sizeof(numbers)/sizeof(int);
    printf("\nt == %d",count);

    

    for (int i = 0; i < count; i++)
    {
        printf("\n-- index == %d; value == %d", i, numbers[i]);
    }

}

void multidimensional_arr() {

    int arr[][3] = {{1,2,3},{4,5,6},{7,8,9}};

    // printf("%s",arr);
    printf("%d",arr[0][1]);

    int inner_arr0[] = {1,2,3,4,5,6};
    int inner_arr1[] = {11,22,33,44,55,66};
    int inner_arr2[] = {111,222,333,444,555,666};
    int inner_arr3[] = {1,2,3,4,5,6};

    printf("%lu",sizeof(inner_arr3));

    printf("------");

    // int out_arr[][6] = {inner_arr0,inner_arr1,inner_arr2,inner_arr3};


    int out_arr[4][6] = {{1,2,3,4,5,6},{11,22,33,44,55,66},{111,222,333,444,555,666},{1,2,3,4,5,6}};

    printf("%lu",sizeof(out_arr));





}

void test_string() {
    char s1[] = "Hello _";
    char s2[] = {'H','e','l','l','o',' ', '_', '\0'};
    /*
    Both of above codes is the same.
    '\0' mark the end of chars, knowing as 'null terminating character', to tell the C this is the end of string.

    Note:
        1. all above string's length is 8. 
        2. using s1 type double quotations omit the '\0', but there is exist in underlayer.
    */
   int s1_len = sizeof(s1)/sizeof(s1[0]);
   printf("s1 length is %d\n",s1_len);

   for (char i = 0; i < s1_len; i++)
   {
        printf("s1 -- index == %d --- value == %c \n", i, s1[i]);
   }
   
   /*
    * the output of above for loop as follow:
    *   s1 -- index == 0 --- value == H 
    *   s1 -- index == 1 --- value == e 
    *   s1 -- index == 2 --- value == l 
    *   s1 -- index == 3 --- value == l 
    *   s1 -- index == 4 --- value == o 
    *   s1 -- index == 5 --- value ==   
    *   s1 -- index == 6 --- value == _ 
    *   s1 -- index == 7 --- value == Null  // this refer to 'null terminating character' which tells c that is the end of string.
    */

   printf("-----------------------------------\n");

   /*
   s2 string size and output is the same as s1.
   */

   int s2_len = sizeof(s2)/sizeof(s2[0]);
   printf("s2 length is %d\n",s2_len);

   for (char i = 0; i < s2_len; i++)
   {
        printf("s2 -- index == %d --- value == %c \n", i, s2[i]);
   }

}

void test_scanf() {
    int a, b;

    printf("Pls type a and b (Using Enter)\n");

    scanf("%d %d", &a, &b);

    printf("a == %d, b == %d", a, b);
    
    /**
     * If you excute the code in IDE, but have no effect; You can excute the unix excution file after complier.
     */

    
}

void test_memory_pointer_address() {
    int a = 45;
    printf("a =================== %d \n",a); 
    printf("&a ================== %p \n",&a); 


    /*
    上述两种都是 指向 int 类型的指针变量，没有本质区别，只是书写风格不同。
    */

    int* ptr = &a;
    printf("ptr ================= %p\n", ptr);  

    int *ptr_1 = &a;
    printf("ptr_1 =============== %p\n", ptr_1); 
    //------------------------------------------
    
    

   /**
    * &a        type == int *; 获取指针变量的值         
    * ptr       type == int *; 声明指针变量的类型       
    * &ptr      type == int **                       
    * p_ptr     type == int **;
    * 
    * `&` 符号获取指针变量， 指针 变量的 类型 一定是 int *...; 其中
    */

    int **p_ptr2 = &ptr;
    printf("p_ptr2 ============== %p\n", p_ptr2); 
    printf("p_ptr2_v ============ %d\n", **p_ptr2); 

    int ***p_p_ptr3 = &p_ptr2;
    printf("p_p_ptr3 ============ %p\n", p_p_ptr3); 
    printf("p_p_ptr3_v ========== %d\n", ***p_p_ptr3); 


    int ****p_p_p_ptr4 = &p_p_ptr3;
    printf("p_p_p_ptr4 ========== %p\n", p_p_p_ptr4); 
    printf("p_p_p_ptr4_v ======== %d\n", ****p_p_p_ptr4); 

    int *****p_p_p_p_ptr5 = &p_p_p_ptr4;
    printf("p_p_p_p_ptr5 ======== %p\n", p_p_p_p_ptr5); 
    printf("p_p_p_p_ptr5_v ====== %d\n", *****p_p_p_p_ptr5); 

    int ******p_p_p_p_p_ptr6 = &p_p_p_p_ptr5;
    printf("p_p_p_p_p_ptr6 ====== %p\n", p_p_p_p_p_ptr6); 
    printf("p_p_p_p_p_ptr6_v ==== %d\n", ******p_p_p_p_p_ptr6); 

    int *******p_p_p_p_p_p_ptr7 = &p_p_p_p_p_ptr6;
    printf("p_p_p_p_p_p_ptr7 ==== %p\n", p_p_p_p_p_p_ptr7); 
    printf("p_p_p_p_p_p_ptr7_v == %d\n", *******p_p_p_p_p_p_ptr7); 
    

    /*
    来观察下 上述所有的输出
    a =================== 45 
    &a ================== 0x7ff7ba57d84c 
    ptr ================= 0x7ff7ba57d84c
    ptr_1 =============== 0x7ff7ba57d84c
    p_ptr2 ============== 0x7ff7ba57d840
    p_ptr2_v ============ 45
    p_p_ptr3 ============ 0x7ff7ba57d830
    p_p_ptr3_v ========== 45
    p_p_p_ptr4 ========== 0x7ff7ba57d828
    p_p_p_ptr4_v ======== 45
    p_p_p_p_ptr5 ======== 0x7ff7ba57d820
    p_p_p_p_ptr5_v ====== 45
    p_p_p_p_p_ptr6 ====== 0x7ff7ba57d818
    p_p_p_p_p_ptr6_v ==== 45
    p_p_p_p_p_p_ptr7 ==== 0x7ff7ba57d810
    p_p_p_p_p_p_ptr7_v == 45
    */

   /*
   观察上述输出
   `*` 
        - on left  hand denotes declare pointer variable type.
        - on right hand denotes get the value which the pointer variable referance.
   */

}

void pointer_in_arr_or_str() {
    int arr[] = {41,51,61,71};
    printf("%d\n",arr[0]);

    /*
      arr 和 &arr 的区别
      ---------------
      arr
           - 指向数组第一个元素的指针
           - 类型为`int *`         4 字节 (假设 int 为 4 字节)
           - 当你对 arr 进行指针运算时（如 arr + 1），它会指向下一个元素（即 arr[1]）。
      &arr
           - 指向整个数组的指针
           - 类型为`int (*)[4]`    16 字节 (4 个 int)
           - 当你对 &arr 进行指针运算时（如 &arr + 1），它会跳过整个数组的大小（例如，4 个 int 大小的数组，跳过 16 字节）。
    */ 
    
    printf("arr       = %p\n", arr);       // 打印数组第一个元素的地址
    printf("&arr      = %p\n", &arr);      // 打印整个数组的地址
    printf("arr + 1   = %p\n", arr + 1);   // 打印数组第二个元素的地址
    printf("&arr + 1  = %p\n", &arr + 1);  // 打印跳过整个数组后的地址
    /*
    arr       = 0x7ff7bb40a830
    &arr      = 0x7ff7bb40a830
    arr + 1   = 0x7ff7bb40a834
    &arr + 1  = 0x7ff7bb40a840
    */

    printf("\n\n\n\n");

    printf("arr_p ===== %p\n", &arr);
    printf("arr[0]_p == %p\n", &arr[0]);
    printf("arr[1]_p == %p\n", &arr[1]);
    printf("arr[2]_p == %p\n", &arr[2]);
    printf("arr[3]_p == %p\n", &arr[3]);


    printf("arr_p' ===== %p\n", arr);
    printf("arr[0]_p' == %p\n", arr+0);
    printf("arr[1]_p' == %p\n", arr+1);
    printf("arr[2]_p' == %p\n", arr+2);
    printf("arr[3]_p' == %p\n", arr+3);

    printf("\n\n\n\n");

    printf("arr_p_v ===== %d\n", *arr);
    printf("arr[0]_p_v == %d\n", *(&arr[0]));
    printf("arr[1]_p_v == %d\n", *(&arr[1]));
    printf("arr[2]_p_v == %d\n", *(&arr[2]));
    printf("arr[3]_p_v == %d\n", *(&arr[3]));

    printf("arr[0]_p_v' == %d\n", *(arr + 0));
    printf("arr[1]_p_v' == %d\n", *(arr + 1));
    printf("arr[2]_p_v' == %d\n", *(arr + 2));
    printf("arr[3]_p_v' == %d\n", *(arr + 3));

}

int main(){
    
    // test01_basic();

    // multidimensional_arr();

    // test_string();

    // test_scanf();
    
    // test_memory_pointer_address();

    pointer_in_arr_or_str();

    return 0;
}