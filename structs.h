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
void int_double(void* this);
#endif