/******************************************************************************/
/*! @addtogroup Group2
    @file       queue.c
    @brief      
    @date       2024/05/17
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* Constructor */
void Queue_Init(Queue* const me,
                int (*is_full)(Queue* const me),
                int (*is_empty)(Queue* const me),
                int (*get_size)(Queue* const me),
                int (*insert)(Queue* const me, int k),
                int (*remove)(Queue* const me)
                )
{
    me->head = 0;
    me->tail = 0;
    me->size = 0;

    me->is_full = is_full;
    me->is_empty = is_empty;
    me->get_size = get_size;
    me->insert = insert;
    me->remove = remove;
}

/* Destructor */
void Queue_cleanup(Queue* const me)
{
    /* do nothing */
}

/* funcion */
int Queue_is_full(Queue* const me)
{
    return (me->head + 1) % QUEUE_SIZE == me->tail;
}

int Queue_is_empty(Queue* const me)
{
    return (me->head == me->tail);
}

int Queue_get_size(Queue* const me)
{
    return (me->size);
}

int Queue_insert(Queue* const me, int k)
{
    if (!me->is_full(me))
    {
        me->buffer[me->head] = k;
        me->head = (me->head + 1) % QUEUE_SIZE;
        ++me->size;
    }
}
int Queue_remove(Queue* const me)
{
    int value = -9999;
    if (!me->is_empty(me))
    {
        value = me->buffer[me->tail];
        me->head = (me->head + 1) % QUEUE_SIZE;
        --me->size;
    }
    return value;
}

Queue* Queue_create()
{
    Queue* me = (Queue*)malloc(sizeof(Queue));
    if(me == NULL)
    {
        return NULL;
    }

    Queue_Init(me,
               Queue_is_full,
               Queue_is_empty,
               Queue_get_size,
               Queue_insert,
               Queue_remove);
    return me;
}
void Queue_destroy(Queue* const me)
{
    if (me != NULL)
    {
        Queue_cleanup(me);
        free(me);
    }
}




