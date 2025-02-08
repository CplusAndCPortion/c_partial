#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 生成随机数
 * 
 * @return int 
 */
int generate_random() {
    return rand();
}

typedef int (*Func_ptr)(void);
// void populate_array(int array[], int size, int (*func_ptr)(void)) 
void populate_array(int array[], int size, Func_ptr func_ptr) 
{
    for (int i = 0; i < size; i++) {
        array[i] = func_ptr();
    }
}

int main() {
    int array[5];
    populate_array(array, 5, generate_random);
    for(int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}