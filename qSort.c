#include "qSort.h"

#include "list.h"

void quick_sort(list* lst, int low, int high, int (*cmp)(void*, void*, void*)) {
    if (low < high) {
        int splitter = partition(lst, low, high, *cmp);
        quick_sort(lst, splitter + 1, high, *cmp);
        quick_sort(lst, low, splitter - 1, *cmp);
    }
}
int partition(list* lst, int low, int high, int (*cmp)(void*, void*, void*)) {
    node* pivot = find(lst, high);
    node* O = find(lst, 0);  // origin
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if ((*cmp)(O, pivot->content, find(lst, j)->content) > 0) {
            i++;
            swap(find(lst, i), find(lst, j));
        }
    }
    swap(find(lst, ++i), pivot);
    return i;
}
void swap(node* x, node* y) {
    if (x != y) {  // to not swap same elements
        void* temp = x->content;
        x->content = y->content;
        y->content = temp;
    }
}