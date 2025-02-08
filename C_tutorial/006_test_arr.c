#include <stdio.h>
#include <string.h>

int main() {
    int numbers[][4] = {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };
    int count = sizeof(numbers)/sizeof(numbers[0]);
    printf("count == %d\n", count);

    for (int i = 0; i < count; i++)
    {
        /*
        Note:
        1. 在C语言中,不能直接将一个数组赋值给另一个数组，但是可以通过memcpy函数来实现。！！！
        */
        // int tmp[4] = numbers[i];

        int tmp[4];
        memcpy(tmp, numbers[i], sizeof(tmp));
        
        for (int j = 0; j < 4; j++)
        {
            printf("index == %d, value == %d\n", j, tmp[j]);
        }
    }
    
    return 0;
}