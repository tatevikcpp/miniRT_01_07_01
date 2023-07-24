#include "minirt.h"

void    mult_matrix(int A[4][4], int B[4][4])
{
    int C[4][4];
    int mult;
    int i;
    int j;
    int k;

    i = 0;
    while (i < 4)
    {
        j = 0;
        while (j < 4)
        {
            mult = 0;
            k = 0;
            while (k < 4)
            {
                mult += A[i][k] * B[k][j];
                k++
            }
            C[i][j] = mult;
            j++;
        }
        i++;
    }
}
