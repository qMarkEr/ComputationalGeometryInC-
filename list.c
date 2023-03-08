#include "list.h"
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
    node* cur = lst->head;
    while(cur != NULL) {
        (*prnt)(cur->content);
        printf("\n");
        cur = cur->next;
    }
}

void destroy(list *lst) {
    while(lst->tail->prev != lst->head && lst->head != lst->tail) {
        delete(lst, 0);
        delete(lst, lst->length - 1);
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

void delete(list *lst, int index) {
    if (index < 0 || index >= lst->length) {
        return;
    }
    if (index == 0) {
        node* temp_head = lst->head;
        lst->head = temp_head->next;
        lst->head->prev = NULL;
        free(temp_head);

    } else if (index == lst->length - 1) {
        node* temp_tail = lst->tail;
        lst->tail = temp_tail->prev;
        lst->tail->next = NULL;
        free(temp_tail);

    } else if (index <= lst->length / 2) {
        int i = 0;
        node* cur = lst->head;
        while (i != index) {
            cur = cur->next;
            i++;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        free(cur);

    } else {
        int i = lst->length - 1;
        node* cur = lst->tail;
        while (i > index) {
            cur = cur->prev;
            i--;
        }
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        free(cur);
    }
    lst->length--;
}

void* at_index(list *lst, int index) {
    if (index < 0 || index >= lst->length) {
        return NULL;
    }
    if (index < lst->length / 2) {
        node* cur = lst->head;
        int i = 0;
        while (i != index) {
            cur = cur->next;
            i++;
        }
        return cur->content;
    } else {
        node* cur = lst->tail;
        int i = lst->length - 1;
        while (i != index) {
            cur = cur->prev;
            i--;
        }
        return cur->content;
    }
}

void insert(list *lst, void* data, int index) {
    if (index > lst->head) {
        return;
    }
    if (index == lst->length - 1) {
        add(lst, data);
        return;
    }
    if (index == 0) {
        node* temp = lst->head;
        lst->head = init(data);
        lst->head->next = temp;
        return;
    }
    if (index < lst->length / 2) {
        node* cur = lst->head;
        int i = 0;
        while (i != index - 1) {
            cur = cur->next;
            i++;
        }
        node* new = init(data);
        new->prev = cur;
        new->next = cur->next;
        cur->next = new;
        new->next->prev = new;
    } else {
        node* cur = lst->tail;
        int i = lst->length - 1;
        while (i != index) {
            cur = cur->prev;
            i--;
        }
        node* new = init(data);
        new->prev = cur;
        new->next = cur->next;
        cur->next = new;
        new->next->prev = new;
    }
    lst->length++;
}