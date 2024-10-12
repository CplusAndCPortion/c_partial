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

void struct_basic_usages();

void custom_multi_arr();


int main(int argc, char const *argv[])
{
    // struct_basic_usages();

    custom_multi_arr();
    
    return 0;
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