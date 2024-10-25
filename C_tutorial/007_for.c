#include <stdio.h>

void test();



int main() {

    // test();


    float f = 1e-3;
    printf("%f",f);

    unsigned long int a = sizeof(char);

    printf("\n----%lu", a);

    double lf = 5e-8;
    printf("\n%.14lf", lf);
    return 0;
}


void test() {
int n = 4;

    for (int i = 0; i < n; i++)
    {
        
        for (int j = 0; j < i; j++)
        {
            /* code */
            printf("*");
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        
        for (int j = n-i; j > 0; j--)
        {
            /* code */
            printf("*");
        }
        printf("\n");
    }
    
}