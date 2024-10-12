#include <stdio.h>
#include <math.h>

void arr_change(int arr[]){
    arr[4] = 1000;
}

void test01() {
    int arr[] = {1,2,3,4,6};

    if (sizeof(arr) == sizeof(int[5])) {
        printf("x is an int[5]\n");
    } else
    {
        printf("not match type\n");
    }
    

    // int arr1[8] = arr;

    arr_change(arr); // actually, it is the pointer of the first element in array that passed to func.

    printf("%d",arr[4]);
}

int main() {

    int a = sqrt(16);
    printf("a == %d \n", a);

    float b = ceil(1.2);
    float c = floor(1.2);
    float d = round(1.2);
    float e = round(1.5);

    printf("b = %f;c = %f;d = %f;e = %f \n",b,c,d,e);

    double power_res = pow(3,2);
    printf("power_res == %lf \n", power_res);
    
    printf("int size == %lu \n", sizeof(int));

    printf("float size == %lu \n", sizeof(float));

    printf("double size == %lu \n", sizeof(double));
    
    return 0;
}