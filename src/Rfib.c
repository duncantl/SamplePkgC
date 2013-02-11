/*#include "fib.h" */

/* For a .C routine */
void
Rfib(int *n, int *ans)
{
    int tmp = fib(*n);
    *ans = tmp;
    /* No return as we are returning nothing - void.
       Not like R which would return the last value */
}
