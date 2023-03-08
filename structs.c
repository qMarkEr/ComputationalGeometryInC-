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