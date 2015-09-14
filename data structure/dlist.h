/*dlist.h*/
#ifndef DLIST_H_
#define DLIST_H_

#include <stdlib.h>

typedef struct  DListElmt_
{
    void *data;
    struct DListElmt_ *prev;
    struct DListElmt_ *next;
}DListElmt;

typedef struct DList_
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destroy)(void *data);
    DListElmt *head;
    DListElmt *tail;
};

void dlist_init(DList *list, void (*destroy)(void *data));
void dlist_destroy(DList *list);
int dlist_ins_next(DList *list, DListElmt *element, const void *data);
int dlist_ins_prev(DList *list, DListElmt *element, const void *data);
int dlist_remove(DList *list, DListElmt *element, void **data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(element) ((element)->prev== NULL ? 1 : 0)
#define list_is_tail(element) ((element)->next== NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)
#define list_prev(element) ((element)->prev)

#endif
