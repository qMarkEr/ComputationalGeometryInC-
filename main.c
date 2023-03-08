#include <stdio.h>
#include <stdlib.h>
#include "structs.h"
#include "list.h"

int main() {
//    pnt* a = malloc(sizeof(pnt*));
//    a->x = 1;
//    a->y = 2;
    int a[4];
    for (int i = 0; i < 4; ++i) {
        scanf("%d", &a[i]);
    }
    list* lst = list_init(&a[0]);
    for (int i = 1; i < 4; ++i) {
        add(lst, &a[i]);
        printf("\n");
    }
 //   free(a);
    lst_print(lst, *int_print);
    printf("%d", lst->length);
    destroy(lst);
    return 0;
}
