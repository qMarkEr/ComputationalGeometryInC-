#include <stdlib.h>
#include "structs.h"
#include "list.h"
#include "stdio.h"

int main() {

    pnt* a = (pnt*) malloc(sizeof(pnt) * 4);
    pnt_input(&a[0]);
    list* lst = list_init(&a[0]);
    for (int i = 1; i < 4; ++i) {
        pnt_input(&a[i]);
        add(lst, &a[i]);
    }
    lst_print(lst, pnt_output);
    insert(lst, &a[2], 2);
    delete(lst, 2);
    printf("\n");
    lst_print(lst, pnt_output);
    destroy(lst);
    free(a);
    return 0;
}