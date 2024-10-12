#include <stdio.h>

int sum(int num);

int main() {
    int result = sum(3);
    printf("∑10 == %d",result);
    return 0;
}

int sum(int num) {

    printf("num == %d\n",num);

    printf("函数 Address : %p\n", &sum);  // 是指向函数代码的内存位置，通常在程序编译时确定。函数的地址在调用时不变。
    printf("栈帧 Address : %p\n", &num);  // 是在栈上分配的，用于存储特定函数调用的信息。每次调用该函数时都会创建一个新的栈帧，栈帧在函数执行期间存在，执行结束后会被销毁。

    /*
    一个栈帧通常包含以下部分：

        返回地址：当函数执行完毕后，控制流应该返回到的调用位置（即调用该函数的下一条指令地址）。
        函数参数：传递给函数的参数值。
        局部变量：在函数内部定义的局部变量。
        保存的寄存器状态：一些寄存器的值，以便在函数返回后可以恢复。
    */

    if (num > 0)
    {
        return num + sum(num - 1);
    } else {
        return 0;
    }
}