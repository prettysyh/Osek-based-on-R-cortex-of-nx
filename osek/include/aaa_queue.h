#ifndef _QUEUE_H
#define _QUEUE_H

#define Length 64
#define MSG 16

typedef struct queue {
    uint8_t buf[Length][MSG];
    uint32_t head, tail;
} queue, *QueueHandle;


bool is_full(queue* q);
bool is_empty(queue* q);
bool push(queue* q, void * item, int length);
bool pop(queue* q, void * item, int length);

#endif