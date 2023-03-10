#include "qSort.h"
#include "list.h"

void quick_sort(list *lst, int low, int high, int (*cmp) (void*, void*)) {
    if (low < high) {
        int splitter = partition(lst, low, high, *cmp);
        quick_sort(lst, splitter + 1, high, *cmp);
        quick_sort(lst, low, splitter - 1, *cmp);
    }
}
int partition(list* lst, int low, int high, int (*cmp) (void*, void*)) {
    node* pivot = at_index(lst, high);
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if ((*cmp)(pivot->content, at_index(lst, j)->content) > 0) {
            i++;
            swap(at_index(lst, i), at_index(lst, j));
        }
    }
    swap(at_index(lst, ++i), pivot);
    return i;
}

void swap (node* x, node* y) {
    void* temp = x->content;
    x->content = y->content;
    y->content = temp;
}