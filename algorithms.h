#ifndef COMPUTATIONALGEOMETRY_ALGORITHMS_H
#define COMPUTATIONALGEOMETRY_ALGORITHMS_H
#include "list.h"
#include "structs.h"
void rearrange(list* lst);
int orientation(pnt *x, pnt *y, pnt *z);
list* GrahamScan(list* lst);
#endif //COMPUTATIONALGEOMETRY_ALGORITHMS_H
