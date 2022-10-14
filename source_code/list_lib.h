//
// Created by Los-Hackers666 on 14/10/2022.
//

#ifndef LIST_LIB_LIST_LIB_H
#define LIST_LIB_LIST_LIB_H
#define CHARS_IN_INT 11
#include <stdlib.h>
#include <stdio.h>


typedef struct list List;

List *list_new();
List *list_append(List *l, int value_to_add);
List *remove_duplicates(List *l);
List *lread();
void lwrite(List *l);
#endif //LIST_LIB_LIST_LIB_H
