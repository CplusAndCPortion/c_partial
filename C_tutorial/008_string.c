#include <stdio.h>
#include <string.h>


void str_represention();

void string_func();

int main() {

    // str_represention();

    string_func();
    return 0;
}
void string_func() {

    /*
    strlen exclude the end sign '\0';
    */

    char str1[] = "hello";
    char str2[] = {'h','e','l','l','o','\0'};

    int str1_len = sizeof(str1) / sizeof(str1[0]);
    int str2_len = sizeof(str2) / sizeof(str2[0]);
    printf("str1_len == %d\n", str1_len); // 6
    printf("str2_len == %d\n", str2_len); // 6

    printf("string1_len == %lu\n", strlen(str1));
    printf("string2_len == %lu\n", strlen(str2));
    // string1_len == 5
    // string2_len == 5


}

void str_represention(){
    char str1[] = "hello";
    char str2[] = {'h','e','l','l','o','\0'};
    printf("str1 == %s\n", str1);
    printf("str2 == %s\n", str2);
    /*
    str1 == hello
    str2 == hello
    */
   /**
    * NOTE:
    *   '\0' refers to the null terminating operator.
    */

   int str1_len = sizeof(str1) / sizeof(str1[0]);
   int str2_len = sizeof(str2) / sizeof(str2[0]);
   printf("str1_len == %d\n", str1_len);
   printf("str2_len == %d\n", str2_len);
   /*
   str1_len == 6
   str2_len == 6
    */

}