#include <stdlib.h>

void    free_matrix(char **arr)
{
    int i;

    i = 0;
    if (arr)
    {
        while (arr[i])
        {
            free(arr[i]);
            i++;
        }
    }
    free(arr);
}

