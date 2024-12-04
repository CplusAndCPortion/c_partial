#include <stdio.h>
#include <string.h>

// Structure is used to group several related variables into one place.
// Each variable in the structure is known as a member of the structure.
struct MyStructure
{
    int myNum;
    char myLetters;
}; //NOTE!!! There is an ; at the end of structure.

struct Person {
    int age;
    char gender;
    char name[30];
};

/**
 * @brief Declaration Stucture first, and then assgin values to it.
 */
void init_struct_1();

/**
 * @brief declaration and assignment at the same time when init structure.
 * 
 */
void init_struct_2();

/**
 * @brief using string in struct.
 * NOTE:  assignment in string var in stuct, should use string 'strcpy' func. assignment directly will not work, and cause errors.
 * 
 */
void string_in_struct();

void copy_struct();


int main(int argc, char const *argv[])
{
    // init_struct_1();
    // init_struct_2();
    // string_in_struct();
    copy_struct();
    return 0;
}

void init_struct_1() {
    // create a structure variable
    struct MyStructure s;

    // assign values to the member of structure;
    s.myLetters = 'B';
    s.myNum = 18;
    // print values
    printf("s.myLetters == %c \n",s.myLetters);
    printf("s.myNum == %d \n",s.myNum);
    /*
    s.myLetters == B 
    s.myNum == 18 
     */
}

void init_struct_2() {
    struct MyStructure s = {20, 'Z'}; // 20 assign to myNum, and 'Z' assign to myLetters
    printf("s.myLetters == %c \n",s.myLetters);
    printf("s.myNum == %d \n",s.myNum);
}

void string_in_struct() {
    

    struct Person p;
    p.age = 18;
    p.gender = 'M';
    /*
    array type 'char[30]' is not assignable.
    p.name = "Jackie"; 
    */
    strcpy(p.name, "Jackie");
    printf("p.age == %d \n",p.age);
    printf("p.gender == %c \n",p.gender);
    printf("p.name == %s \n",p.name);

    printf("-------seperate line-------\n");
    
    /**
     * In this way ,we do not need call the 'strcpy' explicitly.
     * 
     */
    struct Person p1 = {18,'F',"John"};
    printf("p1.age == %d \n",p1.age);
    printf("p1.gender == %c \n",p1.gender);
    printf("p1.name == %s \n",p1.name);
}

void copy_struct() {
    struct Person p1 = {18,'F',"John"};

    struct Person p2 = p1;
    printf("p2.age == %d \n",p2.age);
    printf("p2.gender == %c \n",p2.gender);
    printf("p2.name == %s \n",p2.name);

    strcpy(p2.name,"lingxiao");
    printf("p2.name == %s \n",p2.name);

    printf("-------seperate line-------\n");
    printf("p1_address == %p\n",&p1); // 0x7ff7baee9830
    printf("p2_address == %p\n",&p2); // 0x7ff7baee9808
    /*
    We can know that p2 and p1 are distinct, p2 is a new struct, according to their memory address.
     */
}