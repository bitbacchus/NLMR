// Generated by using Rcpp::compileAttributes() -> do not edit by hand
// Generator token: 10BE3573-1514-4C36-9D1C-5A225CD40393

#include <RcppArmadillo.h>
#include <Rcpp.h>

using namespace Rcpp;

// diamond_square
int diamond_square(arma::mat& nlm_mat, arma::uvec roughness);
RcppExport SEXP _NLMR_diamond_square(SEXP nlm_matSEXP, SEXP roughnessSEXP) {
BEGIN_RCPP
    Rcpp::RObject rcpp_result_gen;
    Rcpp::RNGScope rcpp_rngScope_gen;
    Rcpp::traits::input_parameter< arma::mat& >::type nlm_mat(nlm_matSEXP);
    Rcpp::traits::input_parameter< arma::uvec >::type roughness(roughnessSEXP);
    rcpp_result_gen = Rcpp::wrap(diamond_square(nlm_mat, roughness));
    return rcpp_result_gen;
END_RCPP
}

RcppExport SEXP ccl_4(SEXP);
RcppExport SEXP ccl_8(SEXP);

static const R_CallMethodDef CallEntries[] = {
    {"_NLMR_diamond_square", (DL_FUNC) &_NLMR_diamond_square, 2},
    {"ccl_4", (DL_FUNC) &ccl_4, 1},
    {"ccl_8", (DL_FUNC) &ccl_8, 1},
    {NULL, NULL, 0}
};

RcppExport void R_init_NLMR(DllInfo *dll) {
    R_registerRoutines(dll, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(dll, FALSE);
}
