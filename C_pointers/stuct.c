#include <stdio.h>
#include <string.h>

struct Person
{
    char name[50];
    int age;
    float salary;
};
// 3727.03 +

void printPerson(struct Person *p) {
    printf("Name: %s\n", (*p).name);
    printf("Age: %d\n", (*p).age);
    printf("Salary: %.2f\n", (*p).salary);

    printf("\n");
    printf("Name: %s\n", p->name);
    printf("Age: %d\n", p->age);
    printf("Salary: %.2f\n", p->salary);
}

int main(int argc, char const *argv[]) {

    char *name = "Lynsio";
    printf("Name: %s\n", name);

    struct Person person1;
    person1.age = 22;
    person1.salary = 12000.00;
    // person1.name = "John Doe";
    strcpy(person1.name, name);
    printPerson(&person1);

    return 0;
}