/*queue.h*/
#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdlib.h>

#include "list.h"

typedef List Queue;

#define queue_init list_init
#define queue_destroy list_destroy
int queue_enqueue(Queue *queue, const void *data);
int queue_dequeue(Queue *queue, void **data);
#define queue_peak(queue) ((queue)->head == NULL ? NULL : (queue)->head->data)
#define queue_size list_size

#endif
