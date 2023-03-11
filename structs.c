#include "structs.h"

#include <stdio.h>

#include "math.h"
#include "stdlib.h"

// input
int pnt_input(pnt* this) {
    int flag = 1;
    if (scanf("%lf %lf", &this->x, &this->y) != 2) flag = 0;
    return flag;
}

int sgt_input(sgt* this) {
    int flag = 1;
    if (!pnt_input(&this->start) || !pnt_input(&this->end)) flag = 0;
    return flag;
}

// output
void int_print(void* this) { printf("%d", *(int*)this); }
void double_print(void* this) { printf("%lf", *(double*)this); }
void pnt_output(void* this) {
    printf("(%.3lf, %.3lf)", ((pnt*)this)->x, ((pnt*)this)->y);
}
void sgt_output(void* this) {
    printf("(%.3lf, %.3lf) (%.3lf, %.3lf)", ((sgt*)this)->start.x,
           ((sgt*)this)->start.y, ((sgt*)this)->end.x, ((sgt*)this)->end.y);
}

double dist(pnt* a, pnt* b) {
    return pow(a->x - b->x, 2) + pow(a->y - b->y, 2);
}
// compare
int pnt_cmp(void* z, void* x, void* y) {
    pnt* a = (pnt*)x;
    pnt* b = (pnt*)y;
    pnt* o = (pnt*)z;
    double cos_a = (a->x - o->x) / sqrt(dist(a, o)) + 1.0;
    double cos_b = (b->x - o->x) / sqrt(dist(b, o)) + 1.0;

    return (cos_b - cos_a) / fabs(cos_b - cos_a);
}

int int_cmp(void* x, void* y) {
    int* a = x;
    int* b = y;
    return (*a - *b) / abs(*a - *b);
}