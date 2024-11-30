#include "miniRT.h"

void free_split_array(char **arr)
{
    int i;

    i = 0;
    if (!arr)
        return (NULL);
    while(arr[i] != NULL)
    {
        free(arr[i]);
    }
    free(arr);
}