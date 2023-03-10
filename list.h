#ifndef TITLED_LIST_H
#define TITLED_LIST_H
#include "stdlib.h"

typedef struct node {
    struct node* prev;
    struct node* next;
    void* content;
} node;

typedef struct lst {
    node* head;
    node* tail;
    int length;
} list;

node* init (void* data);
list* list_init(void *data);
void add(list *lst, void* data);
void lst_print(list *lst, void (*prnt) (void*));
void insert(list *lst, void* data, int index);
node* at_index(list *lst, int index);
void destroy(list *lst);
void delete(list *lst, int index);

#endif