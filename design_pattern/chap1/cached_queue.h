/******************************************************************************/
/*! @addtogroup Group2
    @file       cached_queue.h
    @brief      
    @date       2024/05/17
    @author     Development Dept at Tokyo
    @par        Revision
    $Id$
    @par        Copyright (C)
    Japan CashMachine Co, Limited. All rights reserved.
******************************************************************************/

#ifndef _CACHED_QUEUE_H_
#define _CACHED_QUEUE_H_

/* CODE */
#include "queue.h"

typedef struct CachedQueue_s CachedQueue;
struct CachedQueue_s
{
    /* data */
    Queue* queue;
};



#endif


