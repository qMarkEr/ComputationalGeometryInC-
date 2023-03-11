#ifndef COMPUTATIONALGEOMETRY_QSORT_H
#define COMPUTATIONALGEOMETRY_QSORT_H
#include "list.h"

void quick_sort(list *lst, int low, int high, int (*cmp) (void*, void*, void*));
int partition(list* lst, int low, int high, int (*cmp) (void*, void*, void*));
void swap (node* x, node* y);
#endif //COMPUTATIONALGEOMETRY_QSORT_H