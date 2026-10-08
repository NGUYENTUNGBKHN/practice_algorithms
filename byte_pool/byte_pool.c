/**
 * @file byte_pool.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2026-09-27
 * 
 * @copyright Copyright (c) 2026
 * 
 */

 /***************************************************************************************************************
 **                                                   INCLUDES
 ***************************************************************************************************************/
#include "byte_pool.h"
#include "stdlib.h"
#include "string.h"
 /***************************************************************************************************************
 **                                         EXTERNAL FUNCTION PROTOTYPES
 ***************************************************************************************************************/
 
 
 /***************************************************************************************************************
 **                                        EXTERNAL VARIABLE DECLARATIONS
 ***************************************************************************************************************/
 
 
 /***************************************************************************************************************
 **                                          INTERNAL MACRO DEFINITIONS
 ***************************************************************************************************************/
#define FREE_BLOCK      0xFFFFFFFF 
 
 /***************************************************************************************************************
 **                                         COMMON VARIABLE DEFINITIONS
 ***************************************************************************************************************/
 
 
 /***************************************************************************************************************
 **                                        INTERNAL VARIABLE DEFINITIONS
 ***************************************************************************************************************/
 int byte_pool_created_count = 0;
 byte_pool_t *byte_pool_current;
 /***************************************************************************************************************
 **                                         INTERNAL FUNCTION PROTOTYPES
 ***************************************************************************************************************/
 
 
 /***************************************************************************************************************
 **                                             FUNCTION DEFINITIONS
 ***************************************************************************************************************/
 
void byte_pool_create(byte_pool_t *pool, void *memory_area, int memory_size)
{
    char *temp_ptr;
    char **free_ptr;
    char *block_ptr;
    char **block_dir_ptr;

    byte_pool_t *next;
    byte_pool_t *prev;

    /* Clear pool comntrol pointer */
    memset(pool, 0, sizeof(byte_pool_t));

    /* Round the pool size */
    memory_size = memory_size/ALIGN_BYTE*ALIGN_BYTE;

    /* Set byte pool start */
    pool->byte_pool_start = (char*)((void*)memory_area);

    /* Set pool size */
    pool->byte_pool_size = memory_size;
    
    /* Set available byte  */
    pool->byte_pool_available = memory_size - (ALIGN_BYTE + sizeof(void*));

    /* Set pool list and pool search */
    pool->byte_pool_list = (char*)((void*)memory_area);
    pool->byte_pool_search = (char*)((void*)memory_area);

    /* Setup end section */

    /* Move block_ptr to end of pool */
    block_ptr = (char*)((void*)memory_area);
    block_ptr = (char*)block_ptr + (int)memory_size;
    /* Assign pool into block end of pool */
    block_ptr = (char*)block_ptr - ALIGN_BYTE;
    temp_ptr = (char*)((void*)memory_area);
    block_dir_ptr = (char*)(block_ptr);
    *block_dir_ptr = (char*)(temp_ptr);
    /* Assign next block address is start of pool */
    block_ptr = (char*)block_ptr - ALIGN_BYTE;
    block_dir_ptr = (char*)(block_ptr);
    *block_dir_ptr = (char*)((void*)memory_area);

    /* Setup start section */
    temp_ptr = (char*)((void*)memory_area);
    block_dir_ptr = (char*)temp_ptr;
    *block_dir_ptr = (char*)(block_ptr);

    block_ptr = (char*)((void*)memory_area);
    block_ptr = (char*)block_ptr - sizeof(void*);
    free_ptr = (char*)(block_ptr);
    *free_ptr = FREE_BLOCK;


    /* Setup created link list byte pool */
    if (byte_pool_created_count == 0)
    {
        byte_pool_current = pool;
        pool->byte_pool_created_next = pool;
        pool->byte_pool_created_prev = pool;
    }   
    else
    {
        next = byte_pool_current;
        prev = next->byte_pool_created_prev;
        
        next->byte_pool_created_prev = pool;
        prev->byte_pool_created_next = pool;

        pool->byte_pool_created_next = next;
        pool->byte_pool_created_prev = prev;
    }

    byte_pool_created_count++;

}

char *byte_pool_search(byte_pool_t *pool, int memory_size)
{
    int theoretical_size = 0;
    char *current_ptr;
    char *work_ptr;
    char *free_ptr;
    int available_byte = 0;
    int examine_block = 0;

    /* Calculate theoretical size of pool */
    theoretical_size = pool->byte_pool_available - (ALIGN_BYTE + sizeof(void*));

    /*  */
    if (theoretical_size > memory_size)
    {
        /* Insufficient memory  */
        return 0;
    }
    else
    {
        /* Sufficient memory */

        /* Assign current pointer to pool search */
        current_ptr = pool->byte_pool_search;
        /* Increment fragment */
        pool->byte_pool_fragment ++;
        examine_block = pool->byte_pool_fragment;
        /* Set available byte zero */
        available_byte = 0;

        do
        {
            work_ptr = (char*)current_ptr + ALIGN_BYTE;
            free_ptr = work_ptr;

            /* Is it Check this fragment free ? */
            if (*free_ptr == FREE_BLOCK)
            {
                
            }
            /* Move to next block */
            else
            {

            }
            
            if (examine_block != 0)
            {
                examine_block --;
            }

        } while (!examine_block);
    }
}

void byte_pool_allocate(byte_pool_t *pool, void **pointer, int allocated_size, int wait_option)
{
    char *work_ptr;
    int finish = 0;
    int count = 0;

    do
    {
        /* Implement search available block */
        work_ptr = byte_pool_search(pool, allocated_size);

        finish = 1;

    } while (!finish);
    
    *pointer = (void*)work_ptr;
    
    if (work_ptr != 0)
    {
        return;
    }
    else
    {
        if (wait_option == 1) // Wait
        {
            printf("suspend current thread\n");
        }
        else // No wait
        {
            printf("no memory\n");
            return;
        }
    }

}

void byte_pool_release(byte_pool_t *pool, char *pointer)
{

}


 
 /***************************************************************************************************************
 **                                                End of file
 ***************************************************************************************************************/


