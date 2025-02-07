#include <stdio.h>
void test01();

void test02();

void test03();

void test04();

void test05();

void test06();


/**
 * @brief copy int array to another int array.
 * 
 */
void test07();

void test08();

int main() {
    // test03();
    // test04();
    // test05();
    // test06();
    // test07();
    test08();
    return 0;
}

void test08() {
    char str[10] = {'h', 'e', 'l', 'l', 'o', '\0'};
    puts(str);
    str[3] = 'H'; // str[3] is equal to *(str + 3)
    *(str + 4) = 'W';
    puts(str);

    3[str] = 'P'; // 3[str] is equal to *(3 + str)
     *(4 + str) = 'W';
    puts(str);
}

void test07_cpy(int desc[], const int src[], int nbr) {



    for (int i = 0; i < nbr; i++)
    {
        /* code */
        // desc[i] = src[i];
        *(desc + i) = *(src + i);
    }
    
}

void test07() {
    int arrA[5] = {10,20,30,40,50};
    int arrB[5];
    test07_cpy(arrB, arrA, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("The %d element of the array is %d\n", i, arrB[i]);
    }
}

void test06() {
    char str1[] = {'T', 'E', 'D', '\0'};
    puts(str1);

    char str2[] = "TED";
    puts(str2);

}

// const: the value of the pointer cannot be changed.
char * my_strcpy(char *dest, const char *src) {
    char *original_dest = dest; // save the original address of dest.
    // *src = 'A'; // error: assignment of read-only location '*src'
   printf("original_dest address is %p\n", original_dest);

    while (*src != '\0')
    {
        /* code */
        *dest++ = *src++;
    }
    *dest = '\0'; // Here, if you return dest, this will return the address of the last element of the dest array.
    printf("The address of the last element of the dest array is %p\n", dest);
    return original_dest;
}

void test05() {
    char strA[80] = "1234567890";
    char strB[80];

    char *p = my_strcpy(strB, strA);
    puts(strB);
    puts("-----");
    puts(p);
}

void test04() {
    char strA[80] = "A string to be used for demonstration purposes";
    char strB[80];

    /**
     * @brief If the size of strB is greater than the size of strA, such as follows, the result will be the same as the previous one. Because the size of strB is greater than the size of strA, and when located at the end of the strA, the '\0' will be copied to the strB.
     * 
     */
    // char strB[80] = "12345678901234567890123456789012345678901234567890";


    char *pA;
    char *pB;

    puts(strA);
    pA = strA;
    puts(pA);
    pB = strB;
    putchar('\n');

    while (*pA != '\0')
    {
        /* code */
        *pB++ = *pA++;
    }
    *pB = '\0';
    puts(strB);
    puts(pB);
    
}

void test03() {
    int arr[6] = {1,-2,3,-4,5, 100};
    // Commonly used subscript to access array elements.
    // we can also access array elements via pointer alternatively.
    int *ptr;
    ptr = &arr[0]; // the pointer points to the first element of the array.
    printf("The first element of the array is %d\n", *ptr);

    for (int i = 0; i < 6; i++)
    {   
        printf("The %d element of the array is %d\n", i, arr[i]);
        // printf("The %d element of the array is %d\n", i, *(ptr + i));
        // printf("The %d element of the array is %d\n", i, *(ptr++));


    }
    
}

void test02() {
    int j, k;
    int *ptr;
    j = 1;
    k = 2;
    ptr = &k;
    
    printf("j has the value %d and is stored at %p\n", j, (void *)&j);
    // j has the value 1 and is stored at 0x7ff7b420084c

    printf("k has the value %d and is stored at %p\n", k, (void *)&k);
    // k has the value 2 and is stored at 0x7ff7b4200848
    printf("ptr has the value %p and is stored at %p\n", ptr, (void *)&ptr);
    // ptr has the value 0x7ff7b4200848 and is stored at 0x7ff7b4200840

    printf("The value of the integer pointed to by ptr is %d\n", *ptr);
    // The value of the integer pointed to by ptr is 2

}

void test01() {
    int j, k;
    k = 2;
    j = 7;
    k = j;

    int *ptr = NULL;
    // int *ptr;
    if (ptr == NULL)
    {
        /* code */
        printf("ptr is NULL\n");
        printf("ptr address value is %p\n", ptr);
    } else {
        printf("ptr is not NULL\n");
        printf("ptr value is %d\n", *ptr);
        printf("ptr address value is %p\n", ptr);
    }
    
}