#include <stdio.h>
#include "variables.h"
#include "functions.h"
/*
当使用的时候，需要编译两个文件，然后链接两个文件。
gcc file1.c file2.c -o program


NOTE:
    注意事项
定义和初始化：外部变量必须在一个文件中定义和初始化，而在其他文件中仅声明。extern 声明不能进行初始化。

作用域：extern 变量和函数具有全局作用域，可以在程序的任何地方访问。

重复定义：避免在多个文件中重复定义相同的变量或函数，这会导致链接错误。

头文件使用：通常将 extern 声明放在头文件中，然后在需要的源文件中包含该头文件。

*/
int main() {
    // 使用外部变量
    printf("d in main: %d\n", d);
    printf("f in main: %d\n", f);
   
    // 调用外部函数
    printExternVariables();
    printMessage();
   
    return 0;
}