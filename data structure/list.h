/*list.h*/

#ifndef LIST_H_
#define LIST_H_

#include <stdlib.h>

typedef struct ListElmt_
{
    void *data;
    struct ListElmt_ * next;
} ListElmt;

typedef struct list_
{
    int size;
    int (*match)(const void *key1, const void *key2);
    void (*destyoy)(void *data);
    ListElmt *head;
    ListElmt *tail;
} List;

/**
 * 返回值 无
 * 描述：初始化由参数list指定的链表。该函数必须在链表做其他操作之前调用。当调用list_destroy时，destroy参数提供了一种释放动态分配的数据的方法。例如，如果链表包含采用malloc动态分配的数据，当链表被销毁时，destroy应该设置为free用来释放数据。对于包含喊几个动态分配成员的结构化数据，destroy应该设置为一个用户自定义的析构函数，通过对每一个动态分配的成员以及对结构体自身调用free来释放数据。如果连败哦包含不应该释放的数据，destroy应该设置为NULL。
*/
void list_init(List *list, void (*destroy)(void *data));

/**
 * 返回值 无
 * 描述：销毁由参数list指定的链表。调用list_destroy后任何其他的操作都不允许执行，除非再次调用list_init，list_destroy将链表中所有的元素都移除，如果传给list_init参数destroy不为NULL，则移除链表中的每个元素时都调用该函数一次。
 * 复杂度 O(n)
 */
void list_destroy(List *list);

/**
*返回值:如果元素插入成功则返回0，否则返回1
*描述:在list指定的链表中element后面插入一个新元素。如果element设置为NULL，则新元素插入链表头部。新元素包含一个只想data的指针，因此只要钙元素还在链表中，data所引用的内存空间就应该合法。管理data所引用的空间是调用者的责任。
*复杂度:O(1)
*/
int list_ins_next(List *list, ListElmt *element, const void *data);

/**
 * [list_rem_next description]
 * @param  list    [description]
 * @param  element [description]
 * @param  data    [description]
 * @return         [description]
 */
int list_rem_next(List *list, ListElmt *element, void **data);

#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define list_is_head(list,element) ((element) ==(list)-?head ? 1 : 0)
#define list_is_tail(element) ((element)->next== NULL ? 1 : 0)
#define list_data(element) ((element)->data)
#define list_next(element) ((element)->next)

#endif
