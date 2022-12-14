//
// Created by Los-Hackers666 on 14/10/2022.
//

#include "list_lib.h"

typedef struct node
{
    int value;
    struct node *next;
}Node;

struct list
{
    Node *head;
};

List *list_new()
{
    List *new = malloc(sizeof(List));
    new->head = NULL;

    return  new;
}

Node *node_new(int value)
{
    Node *new = malloc(sizeof(Node));
    new->value = value;
    new->next = NULL;

    return new;
}

List *list_append(List *l, int value_to_add)
{
    if(l->head == NULL)
    {
        l->head = node_new(value_to_add);

        return l;
    }

    Node *current = l->head;

    while(current->next != NULL)
    {
        current = current->next;
    }

    current->next = node_new(value_to_add);
    return l;
}

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

// file handling
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

    //fclose(results);
}
