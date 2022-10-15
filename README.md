# list_lib

This is library implements a function `remove_duplicates` that checks wether there exist integer values repeted in a list. If any, the function removes them.
It also includes a function for creating new lists, and one for appending values to it. This were useful in implementing `remove_duplicates` and adding functionality to work with files.
The API looks like this:

```c
#ifndef LIST_LIB_LIST_LIB_H
#define LIST_LIB_LIST_LIB_H
#define CHARS_IN_INT 11
#include <stdlib.h>
#include <stdio.h>


typedef struct list List;

List *list_new();
List *list_append(List *l, int value_to_add);
List *remove_duplicates(List *l);
List *lread(const char *path);
void lwrite(List *l);

#endif //LIST_LIB_LIST_LIB_H
```

Important notes
- The input file must only contain integer values in the range **-2147483648 to 2147483647**, i.e. a signed integer. This can be changed to be an unsigned int type by changing the `CHARS_IN_INT` symbol in [`list_lib.h`](https://github.com/Los-Hackers666/list_lib/blob/main/source_code/list_lib.h) to the value **10**.
- The symbol `CHARS_IN_INT` mentioned above accounts for the maximum number of characters in an integer.
- The values inside of the input file must be separated by line breaks.

## `remove_duplicates()`

```c
List *remove_duplicates(List *l)
{
    if(l->head == NULL)
    {
        return l;
    }

    Node *value_to_compare = l->head;
    Node *tmp;

    
    while(value_to_compare->next != NULL)
    {
        Node *current_position = value_to_compare;
        
        while(current_position->next != NULL)
        {       
            if(value_to_compare->value == current_position->next->value)
            {
                tmp = current_position->next;
                current_position->next = current_position->next->next;

                free(tmp);
            } else 
            {
                current_position = current_position->next;
            }
        }

        value_to_compare = value_to_compare->next;
    }

    return l;
}
```

### Description

Receives a pointer to a list as the argument. 
First, the function checks if the list passed as the argument is not empty, if it is, returns the empty list. If it is not empty, checks if there is something to compare, i.e. there is an element after the current one. If the next position is not null, then:
Verify if the value of value_to_compare is equal to the value of the next node. if the condition is satisfied then: 
A temporary node is created that stores the detected copy and go to the next position. The memory occupied by the repeated node is released.
´value_to_compare´ is assigned to the next node on the list.
Finally, the processed list is returned.

## `lread()`

```c
List *lread(const char *path)
{
    FILE *file = NULL;

    char *endptr;
    int value;

    List* l = list_new();

    file = fopen(path,"r");

    char buffer[CHARS_IN_INT];

    if(file == NULL)
    {
        printf("Cannot open file %s", path);
        return l;
    }

    // reads int in a line and adds it to a list
    while(fgets(buffer,CHARS_IN_INT,file) != NULL)
    {
        value = strtol(buffer, &endptr, 0);
        list_append(l, value);
    }

    fclose(file);

    return l;
}
```

### Description

Receives a path as the argument, from which the input file should be read. 
First, creates a new empty list that will store the integers within the specified file. If the file was succesfully opened, reads the contents and stores them in the previously created list, adding them at the end with the `list_append()` function. 
The `strol()` function is used to parse the characters read as integers, so that they can be manipulated by the `remove_duplicates()` function.
When done, returns the populated list.

## `lwrite()`

```c
void lwrite(List *l)
{
    FILE *results = NULL;
    results = fopen("results.txt","w");

    Node *current = l->head;
    //char svalue[CHARS_IN_INT];

    while(current != NULL)
    {
        //snprintf(svalue, (sizeof(char) * CHARS_IN_INT) + 1, "%d\n", current->value);
        //fputs(svalue, results);
        fprintf(results, "%d\n", current->value);
        current = current->next;
    }

    fclose(results);
}
```

### Description

Takes a list as the argument, to write its contents to a `results.txt` file.
The `while` loop iterates over the elements of the list, and prints them to the `results.txt` file, separating each of them with a line break.


