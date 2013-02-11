/*

  vector = rnorm(10)
  .C("sumElements", as.numeric(vector), length(vector), r = numeric(1))$ r

 */

int countHowManyTimesICalled_sumElements = 0;

void
sumElements(double *els, int *len, double *ans)
{
    int i;
    double total = 0;
    int numElements = *len;  // len[0]

    for(i = 0; i < numElements; i++) { // i = i + 1
	total += els[i];
    }
    *ans = total;

    countHowManyTimesICalled_sumElements++;

}


/*
  .Call("R_call_sumElements", x)
 */
#include <Rdefines.h>

SEXP
R_call_sumElements(SEXP x)
{
    int n = LENGTH(x);
    int i;
    double total = 0;
    if(TYPEOF(x) != REALSXP && TYPEOF(x) != INTSXP) {
	PROBLEM "idiot"
	    ERROR;
    }


    for(i = 0; i < n; i++) {
	total += TYPEOF(x) == REALSXP ? REAL(x)[i] : INTEGER(x)[i];
    }

    double *tmp = (double *) malloc(sizeof(double) * n);
    SEXP tmp =NEW_NUMERIC(n);
    double *realValues = REAL(tmp);


    SEXP ans = ScalarReal(total);
    PROTECT(ans);
    SEXP names = NEW_CHARACTER(n);
    PROTECT(names);
    for(i = 0; i < n; i++) {
	SET_STRING_ELT(names, i, makeName(i));
    }
    SET_NAMES(ans, names);
    UNPROTECT(2);
    return(ans);
//    return(ScalarReal(total));
}
