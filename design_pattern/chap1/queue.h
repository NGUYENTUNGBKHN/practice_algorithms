/******************************************************************************/
/*! @addtogroup Group2
    @file       queue.h
    @brief      
    @date       2024/05/17
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/

#ifndef _QUEUE_H_
#define _QUEUE_H_

#define QUEUE_SIZE 10

typedef struct Queue_s Queue;
struct Queue_s
{
    int buffer[QUEUE_SIZE];
    int head;
    int tail;
    int size;

    int (*is_full)(Queue* const me);
    int (*is_empty)(Queue* const me);
    int (*get_size)(Queue* const me);
    int (*insert)(Queue* const me, int k);
    int (*remove)(Queue* const me);
};

/* Constructor */
void Queue_Init(Queue* const me,
                int (*is_full)(Queue* const me),
                int (is_empty)(Queue* const me),
                int (*get_size)(Queue* const me),
                int (*insert)(Queue* const me, int k),
                int (*remove)(Queue* const me)
                );
/* Destructor */
void Queue_cleanup(Queue* const me);

/* funcion */
int Queue_is_full(Queue* const me);
int Queue_is_empty(Queue* const me);
int Queue_get_size(Queue* const me);
int Queue_insert(Queue* const me, int k);
int Queue_remove(Queue* const me);

Queue* Queue_create();
void Queue_destroy(Queue* const me);


#endif

