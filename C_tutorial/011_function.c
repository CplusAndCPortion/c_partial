#include <stdio.h>

/**
 * char *args[] 表示指向字符串指针的数组，里面存储的都是指向字符串的指针
 */

void myFunction(int myNumbers[]) {
    int num = sizeof(*myNumbers) / sizeof(myNumbers[0]);
  for (int i = 0; i < num; i++) {
    printf("%d\n", myNumbers[i]);
  }
}
int main(int num, char *args[]){
    int count = num;
    for (int i = 0; i < count; i++)
    {
        /* code */
        printf("arg[%d] == %s\n",i,args[i]);
    }
    

    int myNumbers[] = {1, 2, 3, 0, 5};
    myFunction(myNumbers);
    return 0;
}

// int main(int argc, char *argv[]) {
//     printf("Argument count: %d\n", argc);

//     for (int i = 0; i < argc; i++) {
//         printf("Argument %d: %s\n", i, argv[i]);
//     }

//     return 0;
// }