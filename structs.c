#include "structs.h"
#include <stdio.h>
#include "stdlib.h"
#include "math.h"

void pnt_output(void* this) {
    printf("(%.3lf, %.3lf)", ((pnt*)this)->x, ((pnt*)this)->y);
}
void sgt_output(void* this) {
   printf("(%.3lf, %.3lf) (%.3lf, %.3lf)", ((sgt*)this)->start.x,
          ((sgt*)this)->start.y,
          ((sgt*)this)->end.x,
          ((sgt*)this)->end.y
          );
}
int pnt_input(pnt* this) {
    int flag = 1;
    if(scanf("%lf %lf", &this->x, &this->y) != 2) flag = 0;
    return flag;
}

int sgt_input(sgt* this) {
    int flag = 1;
    if (!pnt_input(&this->start) || !pnt_input(&this->end)) flag = 0;
    return flag;
}

void int_print(void* this) {
    printf("%d", *(int*) this);
}
void double_print(void* this) {
    printf("%lf", *(double*) this);
}

int pnt_cmp(void *x, void *y) {
    pnt* a = x;
    pnt* b = y;
    double angle_a = a->x / (a->x * a->x + a->y * a->y);
    double angle_b = b->x / (b->x * b->x + b->y * b->y);
    return (angle_a - angle_b) / fabs(angle_a - angle_b);
}

int int_cmp(void* x, void* y) {
    int* a = x;
    int* b = y;
    return (*a - *b) / abs(*a - *b);
}