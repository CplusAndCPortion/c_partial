#include <stdio.h>
#include <stdlib.h>

const int interval_size = 5;

struct LxList
{
    int * data; // A Pointer that point to data(list) memory.
    int currentItems; // current stored items count.
    int size_block; // each resize interval unit.
};

/**
 * @brief expand Lxlist
 * 
 * @param list a pointer that points to struct list.
 * @param item will be add to list->data.
 */
void addItem(struct LxList *list, int item);

int main(int argc, char *argv[]) {

    struct LxList myList;
    int amount;

    // Create a list and start with enough space for 10 items
    myList.currentItems = 0;
    myList.size_block = interval_size;
    myList.data = malloc(myList.size_block * sizeof(int));

    // Find out if memory allocation was successful
    if (myList.data == NULL) {
        printf("Memory allocation failed");
        return 1; // Exit the program with an error code
    }

    // Add any number of items to the list specified by the amount variable
    amount = 44;
    for (int i = 0; i < amount; i++) {
        addItem(&myList, i + 1);
    }

    // Display the contents of the list
    for (int j = 0; j < myList.currentItems; j++) {
        printf("%d ", myList.data[j]);
    }

    // Free the memory when it is no longer needed
    free(myList.data);
    myList.data = NULL;



    return 0;
}

void addItem(struct LxList *list, int item) {
    // when size_block is equal to currentItems, list->data should reallocate with next size_block count to expand the memory size.
    if (list->size_block == list->currentItems)
    {
        int size = list->size_block * sizeof(*(list->data));
        int * ptr = realloc(list->data, size);
        if (ptr != NULL)
        {
            list->data = ptr;
            list->size_block = list->size_block + interval_size;
        }
    }
    
    list->data[list->currentItems] = item;
    list->currentItems ++ ;
}