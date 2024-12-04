#include <stdio.h>
#include <string.h>

/**
 * Enum: represents a group of constant values.
 * Enum in C is the same as in OC.
 *  The first case is 0, the second is 1 , and so forth.
 */

enum Level {
    Low,
    Middle,
    High
};

int main(int argc, char* argv[]) {

    enum Level l;

    // l = Low;
    // l = Middle;
    l = High;


    switch (l)
    {
    case Low:
        printf("in low level == %d", l);
        break;
    case Middle:
        printf("in Middle level == %d", l);
        break;
    case High:
        printf("in High level == %d", l);
        break;
    default:
        break;
    }

    return 0;
}