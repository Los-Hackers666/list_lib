//
// Created by Los-Hackers666 on 14/10/2022.
//

#include "list_lib.h"

int main(int argc, char **argv) {
    List *l = lread();
    remove_duplicates(l);
    lwrite(l);
    return 0;
}