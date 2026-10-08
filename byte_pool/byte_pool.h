/**
 * @file byte_pool.h
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-09-27
 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef _BYTE_POOL_H_
#define _BYTE_POOL_H_
#ifdef __cplusplus
extern "C"
{
#endif

/* CODE */

#define ALIGN_BYTE      4
typedef struct BYTE_POOL_S byte_pool_t;

struct BYTE_POOL_S
{
    int byte_pool_available;            /* number of available bytes in the pool */
    int byte_pool_fragment;             /* number of fragment in the pool */
    char *byte_pool_list;               /* Pointer to head of byte pool list */
    char *byte_pool_search;             /* Pointer to search available bytes */
    char *byte_pool_start;              /* Start address byte pool area */
    int   byte_pool_size;               /* Size of pool */
    char *byte_pool_suspension_list;    /*  */
    int byte_pool_suspension_cnt;   
    byte_pool_t 
        *byte_pool_created_next,
        *byte_pool_created_prev;
};


#ifdef __cplusplus
}
#endif
#endif


