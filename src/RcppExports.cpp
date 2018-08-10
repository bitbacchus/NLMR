// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <Rcpp.h>

using namespace Rcpp;

// freq_c
IntegerVector freq_c(const IntegerVector& dat, const IntegerVector& lc_class);
RcppExport SEXP _NLMR_freq_c(SEXP datSEXP, SEXP lc_classSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< const IntegerVector& >::type dat(datSEXP);
    Rcpp::traits::input_parameter< const IntegerVector& >::type lc_class(lc_classSEXP);
    rcpp_result_gen = Rcpp::wrap(freq_c(dat, lc_class));
    return rcpp_result_gen;
END_RCPP
}

RcppExport SEXP ccl_4(SEXP);
RcppExport SEXP ccl_8(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_NLMR_freq_c", (DL_FUNC) &_NLMR_freq_c, 2},
    {"ccl_4",        (DL_FUNC) &ccl_4,        1},
    {"ccl_8",        (DL_FUNC) &ccl_8,        1},
    {NULL, NULL, 0}
};

RcppExport void R_init_NLMR(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
