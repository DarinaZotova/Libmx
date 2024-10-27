#include "../inc/libmx.h"

void *mx_realloc(void *ptr, size_t size) 
{
    void *new_blk = NULL;

    if (size > 0) 
    {
        if (ptr == NULL) 
        {
            new_blk = malloc(size);
        } 
        else 
        {
            new_blk = malloc(size);
            if (new_blk) 
            {
                mx_memcpy(new_blk, ptr, size);
                free(ptr);
            }
        }
    }

    return new_blk;
}
