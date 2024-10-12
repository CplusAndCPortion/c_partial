#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("argc == %d \n",argc);

    printf("argv0 == %s \n", argv[0]);
    printf("argv1 == %s \n", argv[1]);

    FILE * file;
    file = fopen("filename.txt", "w");
    fclose(file);

    return 0;
}
