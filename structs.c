#include "structs.h"
#include <stdio.h>

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
void int_double(void* this) {
    printf("%lf", *(double*) this);
}

int pnt_cmp(void *x, void *y) {
    pnt* a = x;
    pnt* b = y;
    double angle_a = a->y / (a->x * a->x + a->y * a->y);
    double angle_b = b->y / (b->x * b->x + b->y * b->y);
    if (angle_a > angle_b) {
        return 1;
    } else if (angle_a < angle_b) {
        return -1;
    }
    return 0;
}