#include "algorithms.h"

#include "list.h"
#include "qSort.h"
#include "structs.h"

void rearrange(list* lst) {
    node* bottom = find(lst, 0);
    for (int i = 1; i < lst->length; ++i) {
        pnt* pnt_bottom = (pnt*)bottom->content;
        node* temp = find(lst, i);
        pnt* pnt_temp = (pnt*)temp->content;
        if (pnt_bottom->y > pnt_temp->y ||
            (pnt_bottom->y == pnt_temp->y && pnt_bottom->x < pnt_temp->x)) {
            bottom = temp;
        }
    }
    swap(bottom, find(lst, 0));
}

int orientation(pnt* a, pnt* b, pnt* c) {
    return (b->x - a->x) * (c->y - b->y) - (b->y - a->y) * (c->x - b->x);
}
list* GrahamScan(list* lst) {
    if (lst->length < 3) return NULL;

    if (lst->length == 3) return lst;

    rearrange(lst);
    quick_sort(lst, 1, lst->length - 1, pnt_cmp);

    list* res = list_init();

    add(res, find(lst, 0)->content);
    add(res, find(lst, 1)->content);

    for (int i = 2; i < lst->length; ++i) {
        while (res->length > 1 &&
               orientation(find(res, res->length - 2)->content,
                           find(res, res->length - 1)->content,
                           find(lst, i)->content) < 0) {
            delete (res, res->length - 1);
        }
        add(res, find(lst, i)->content);
    }
    return res;
}