#include "list.h"
#include "stdio.h"
#include "stdlib.h"

node* init (void* data) {
    node* new = (node*)malloc(sizeof(node));
    new->content = data;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

void add(list *lst, void* data) {
    node* new = (node*) malloc(sizeof(node));
    new->content = data;
    new->next = NULL;
    new->prev = NULL;
    if (lst->head == NULL) {
        lst->head = new;
        lst->tail = lst->head;
    } else {
        new->prev = lst->tail;
        lst->tail->next = new;
        lst->tail = new;
    }
    lst->length++;
}

void lst_print(list *lst, void (*prnt) (void*)) {
    node* cur = lst->head;
    while(cur != NULL) {
        (*prnt)(cur->content);
        printf("\n");
        cur = cur->next;
    }
}

list* list_init(void *data) {
    list *lst = (list*)malloc(sizeof(list));
    lst->head = init(data);
    lst->tail = lst->head;
    lst->length = 1;
    return lst;
}

void destroy(list *lst) {
    if (lst) {
        int flag = 1;
        while (flag) {

            if (lst->head != lst->tail) delete(lst, lst->length - 1);
            else flag = 0;

            if (lst->head != lst->tail) delete(lst, 0);
            else flag = 0;

        }
        free(lst->head);
        free(lst);
    }
}

node* at_index(list *lst, int index) {
    if (index < 0 || index >= lst->length)
        return NULL;
    if (index == 0)
        return lst->head;
    if (index == lst->length - 1)
        return lst->tail;
    node* cur;
    int i;
    if (index > lst->length / 2) {
        cur = lst->tail;
        i = lst->length - 1;
        while (i != index) {
            cur = cur->prev;
            i--;
        }
    } else {
        cur = lst->head;
        i = 0;
        while (i != index) {
            cur = cur->next;
            i++;
        }
    }
    return cur;
}

void delete(list *lst, int index) {
    if (!lst)
        return;

    if (index < 0 || index >= lst->length)
        return;

    if (index == 0) {
        node *temp_head = lst->head;
        lst->head = temp_head->next;
        free(temp_head);
        return;
    }
    if (index == lst->length - 1) {
        node *temp_tail = lst->tail;
        lst->tail = temp_tail->prev;
        free(temp_tail);
        return;
    }
    node* cur;
    int i;
    if (index > lst->length / 2) {
        cur = lst->tail;
        i = lst->length - 1;
        while (i != index) {
            cur = cur->next;
            i--;
        }
    } else {
        cur = lst->head;
        i = 0;
        while (i != index) {
            cur = cur->next;
            i++;
        }
    }
    cur->next->prev = cur->prev;
    cur->prev->next = cur->next;
    free(cur);
    lst->length--;
}

void insert(list *lst, void *data, int index) {
    if (!lst)
        return;

    if (index < 0 || index >= lst->length)
        return;

    if (index == 0) {
        node* new = init(data);
        new->next = lst->head;
        lst->head->prev = new;
        lst->head = new;
        return;
    }
    if (index == lst->length - 1) {
        add(lst, data);
        return;
    }
    node* cur;
    int i;
    if (index > lst->length / 2) {
        cur = lst->tail;
        i = lst->length - 1;
        while (i != index) {
            cur = cur->next;
            i--;
        }
    } else {
        cur = lst->head;
        i = 0;
        while (i != index) {
            cur = cur->next;
            i++;
        }
    }
    node* new = init(data);
    new->next = cur;
    new->prev = cur->prev;
    cur->prev->next = new;
    cur->prev = new;
    lst->length++;
}
