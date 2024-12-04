#include <stdio.h>
#include <string.h>


void revision_char();

void str_represention();

void string_func();

// void concatenate_string();

void copy_string();


int main() {

    // revision_char();

    // str_represention();

    // string_func();

    // concatenate_sting();

    copy_string();

    return 0;
}

void revision_char() {
    char c = 'A';
    printf("%c",c);
    printf("\n");
    printf("%i",c); // the 'i' formatter sepcifier is equal to 'd'. the result represtends ASCII code
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

void concatenate_string(){
    char str1[20] = "Hello";
    char str2[] = " world";

    /*
    Note that the size of `str1` should be large enough to store the result of the two strings combined (20 in our example).
    */
    strcat(str1, str2);

    printf("str1 == %s\n", str1);
    printf("str2 == %s\n", str2);
}

void copy_string() {
    char str1[20] = "hello lingxiao";
    char str2[20];
    /*
    char *strcpy(char *dst(destination), const char *src(source)) 
     */
    strcpy(str2,str1); // this will copy str1(source) to str2(destination)
    printf("str2 == %s\n",str2);
}