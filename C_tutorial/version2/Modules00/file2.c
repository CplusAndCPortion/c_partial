#include <stdio.h>
/*
当使用的时候，需要编译两个文件，然后链接两个文件。
gcc file1.c file2.c -o program
*/
// 声明外部变量
extern int d;//  extern 关键字声明的变量是外部变量，表示该变量在其他文件中定义。
extern int f;
// 声明外部函数
extern void printMessage();//关键字 extern 表示这个函数是在其他文件中定义的，而不是在当前文件中。

// 声明外部函数
void printExternVariables();//这个函数没有使用 extern 关键字，意味着它可能在当前文件中定义，或者在其他文件中定义并通过其他方式链接到当前文件中。这里需要注意：如果在其他文件中已经定义了这个函数，在当前文件中再次定义会报错，信息如下： 1 duplicate symbol for

int main() {
    // 使用外部变量
    printf("d in main: %d\n", d);
    printf("f in main: %d\n", f);
    
    // 调用其他文件中定义的函数cd
    printExternVariables();

    printMessage();
    
    return 0;
}

// void printExternVariables() {
//     printf("printExternVariables \n");
// }