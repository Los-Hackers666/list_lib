# list_lib

This is library implements a function `remove_duplicates` that checks wether there exist integer values repeted in a list. If any, the function removes them.
It also includes a function for creating new lists, and one for appending values to it. This were useful in implementing `remove_duplicates` and adding 
functionality to work with files.
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
## `remove_duplicates`

```c
List *remove_duplicates(List *l)
{
    if(l->head == NULL)
    {
        return l;
    }

    Node *value_to_compare = l->head;
    Node *tmp;

    // check if there is something to compare
    while(value_to_compare->next != NULL)
    {
        Node *current_position = value_to_compare;
        // check that the position following the compare value is not null
        while(current_position->next != NULL)
        {
            // if the value of value_to_compare is equal to the value of the next node
            if(value_to_compare->value == current_position->next->value)
            {
                tmp = current_position->next;// create a temporary node that stores detected copy
                current_position->next = current_position->next->next;// change to the next position

                free(tmp);// release the memory occupied by the repeated node
            } else // go to the next node
            {
                current_position = current_position->next;
            }
        }

        value_to_compare = value_to_compare->next;//value_to_compare is assigned to the next node on the list
    }

    return l;// return the processed list
}
```


Important notes:


