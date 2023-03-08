#include "list.h"
#include "structs.h"
#include "stdio.h"
#include "stdlib.h"

node* init (void* data) {
    node* new = malloc(sizeof(node*));
    new->content = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void add(list *lst, void* data) {
    if (lst->head == NULL) {
        lst->head = init(data);
        lst->tail = lst->head;
    } else {
        node* temp_tail = lst->tail;
        temp_tail->next = init(data);
        lst->tail = temp_tail->next;
        lst->tail->prev = temp_tail;
    }
    lst->length++;
}

void lst_print(list *lst, void (*prnt) (void*)) {
    node* cur = lst->tail;
    while(cur != NULL) {
        (*prnt)(cur->content);
        printf("\n");
        cur = cur->prev;
    }
}

void destroy(list *lst) {
    while(lst->tail->prev != lst->head && lst->head != lst->tail) {

        node* temp_tail = lst->tail;
        lst->tail = temp_tail->prev;
        lst->tail->next = NULL;
        free(temp_tail);

        node* temp_head = lst->head;
        lst->head = temp_head->next;
        lst->head->prev = NULL;
        free(temp_head);

    }
    if (lst->head == lst->tail) {
        free(lst->tail);
    } else {
        free(lst->tail);
        free(lst->head);

    }
    free(lst);
}

list* list_init(void *data) {
    list *lst = malloc(sizeof(list));
    lst->head = init(data);
    lst->tail = lst->head;
    lst->length = 1;
    return lst;
}
