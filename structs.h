#ifndef STRUCTS
#define STRUCTS

typedef struct point {
    double x;
    double y;
} pnt;
void pnt_output(void* this);
int pnt_input(pnt* this);

typedef struct segment {
    pnt start;
    pnt end;
} sgt;

void sgt_output(void* this);
int sgt_input(sgt* this);
void int_print(void* this);
void double_print(void* this);
int pnt_cmp(void* o, void* x, void* y);
double dist(pnt* a, pnt* b);
int int_cmp(void* x, void* y);
#endif