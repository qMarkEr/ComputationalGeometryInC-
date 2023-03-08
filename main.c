#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "list.h"

int main() {
    int a[4];
    for (int i = 0; i < 2; ++i) {
        scanf("%d", &a[i]);
    }
    list* lst = list_init(&a[0]);
    for (int i = 1; i < 2; ++i) {
        add(lst, &a[i]);
        printf("\n");
    }
    a[3] = 1010;
    insert(lst, &a[3], 1);
    lst_print(lst, *int_print);

    destroy(lst);
    return 0;
}
