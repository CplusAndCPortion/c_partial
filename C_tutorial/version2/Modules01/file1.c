#include <stdio.h>
#include "variables.h"
#include "functions.h"

// 定义并初始化外部变量
int d = 3;
int f = 5;

void printExternVariables() {
    printf("d: %d, f: %d\n", d, f);
}

void printMessage() {
    printf("Hello from printMessage!\n");
}