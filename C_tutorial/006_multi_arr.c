#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


const int size_interval = 5;

struct myList
{
    int *data; // store arr items
    int numOfItems; // arr items count
    int size; // 存储块 store block 数量
};

void arr_basic_usage();

void get_arr_size();

void multi_dimension_arr();

void custom_multi_arr();

void struct_basic_usages();

int main(int argc, char const *argv[])
{

    // arr_basic_usage();

    // get_arr_size();

    multi_dimension_arr();

    // struct_basic_usages();

    // custom_multi_arr();
    
    return 0;
}

void multi_dimension_arr() {
    /**
     * NOTE:
     *  多维数组只有第一维也即最外层的数组不需要指定容量,其他必须指定且必须用常量指定.
     */
    int inner_container = 3;
    int arr[][3] = {
        {1,2,3},
        {4,5,6},
    };

    printf("%d",arr[1][1]);
    // 5
}

void get_arr_size() {
    int myArr[] = {1,2,3};
    /**
     * We can get the arr size via `sizeof` operator.
     */

    long unsigned int arr_size = sizeof(myArr);

    printf("myArr_size == %lu \n", arr_size);
    // myArr_size == 12 

    /**
     * NOTE:
     * sizeof returns the size of date type.
     * ----
     * 1. int size is 4 bytes.
     * 2. myArr includes 3 int types.
     * 3. so, myArr size is 12
     */

    // we can caculate the number of arr.
    int number = sizeof(myArr)/sizeof(myArr[0]);
    printf("the number of arr is %d \n", number);
    // the number of arr is 3 


    // modify arr ele
    myArr[2] = 4;

    // we also can caculate the average value of the arr
    int sum = 0;
    for (int i = 0; i < number; i++)
    {
        sum += myArr[i];
    }

    float average_num = (float) sum / number;

    printf("average_num == %.2f", average_num);

    
}

void arr_basic_usage() {
    /**
     * There are two steps to create an array.
     * 1. define the data type
     * 2. specify the name of array followed by square brackets[]
     */

    int myArr[] = {1,2,3};
    /**
     * access the ele from arr
     */
    printf("index == 0, value ==  %d\n", myArr[0]);
    printf("index == 1, value ==  %d\n", myArr[1]);
    printf("index == 2, value ==  %d\n", myArr[2]);

    /**
     * NOTE:
     *  all elements in array must be the same type.
     */
}

void add_item_to_list(struct myList *list_p, int list_item) {
    // Note: access value according to pointer, should use '->' operator.
    bool alloc_success = true;
    // if list is full, then resize the list memory size.
    if (list_p->numOfItems == list_p->size )
    {
        list_p->size += size_interval;

        int size_tmp = list_p->size;

        void *tmp = realloc(list_p->data,size_tmp * sizeof(int));

        if (tmp == NULL)
        {
            printf("realloc memory fail\n") ;
            alloc_success = false;
        } else {
            // reassign pointer to struct->data;
            list_p->data = (int *)tmp;
        }
    }

    if (alloc_success == true)
    {
        // add numbers to the last position.
        list_p->data[list_p->numOfItems] = list_item;
        list_p->numOfItems++;
    }
}

void custom_multi_arr() {
    // declare struct var type;
    struct myList arr;
    arr.numOfItems = 0;
    arr.size = size_interval;
    

    // malloc 函数的返回值 是 `void *` 类型，tmp_p 为 `void *`类型的指针变变量
    void *tmp_p = malloc(arr.size * sizeof(int));

    if (tmp_p == NULL)
    {
        printf("allocate memory fail");
    }


    arr.data = (int *)tmp_p;

    int anount = 17;

    for (int i = 0; i < anount; i++)
    {
        add_item_to_list(&arr, i + 10);
    }


    // Display the contents of the list
    for (int j = 0; j < arr.numOfItems; j++) {

        if (j % 10 == 0 && j > 0)
        {
            printf("\n");
        }
        

        printf("%d ", arr.data[j]);
    }
    
    // free memory.
    free(arr.data);
    arr.data = NULL;

}



void struct_basic_usages() {
    struct myList s; // struct myList 表示结构体的类型
    int arr[] = {1,2,3};
    s.data = arr;
    s.numOfItems = 3;
    s.size = 4;

    printf("s.numOfItems == %d\n", s.numOfItems);
    printf("s.size == %d\n", s.size);
    printf("s.data == %d\n",s.data[2]);

}