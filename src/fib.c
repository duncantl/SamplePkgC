/*#include "fib.h"*/

int
fib(int n)
{
   if(n == 0 || n == 1)
       return(n);
   int tmp = fib(n - 1) + fib(n - 2);
   return(tmp);
}



int
dynFib(int n)
{
    if(n == 0 || n == 1)
	return(n);
    else
	return(dynFib(n - 1) + dynFib(n - 2));
}
