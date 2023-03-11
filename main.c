#include <stdlib.h>

#include "algorithms.h"
#include "list.h"
#include "structs.h"

int main() {
    int size = 10;
    pnt* a = (pnt*)malloc(sizeof(pnt) * size);
    list* lst = list_init();
    for (int i = 0; i < size; ++i) {
        pnt_input(&a[i]);
        add(lst, &a[i]);
    }
    list* hull = GrahamScan(lst);
    list_print(hull, pnt_output);
    destroy(lst);
    destroy(hull);
    free(a);
    return 0;
}