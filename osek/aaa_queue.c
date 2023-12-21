#include "aaa_type.h"
#include "aaa_queue.h"

void Memcpy(void *dest, void *src, int32_t length)
{
    uint8_t i = 0U;

    for(i = 0U ; i < length; i ++ )
    {
       *(char*)dest = *(char*)src;
       dest ++ ;
       src ++ ;
    }
    return;
}

bool is_full(queue* q) {
    return q->head == (q->tail + 1) % Length;
}

bool is_empty(queue* q) {
    return q->head == q->tail;
}

bool push(queue* q, void * item, int length) {
    if (is_full(q))
        return false;

    Memcpy((void *)q->buf[q->tail], item, length);
    q->tail = (q->tail + 1) % Length;
    // printf("q->tail=%d\r\n",q->tail);
    return true;
}

bool pop(queue* q, void * item, int length) {
    if (is_empty(q))
        return false;

    Memcpy(item, (void *)q->buf[q->head], length);
    q->head = (q->head + 1) % Length;
    // printf("q->head=%d\r\n",q->head);
    return true;
}