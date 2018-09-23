#include <RcppArmadillo.h>

using namespace Rcpp;

// [[Rcpp::export]]
int diamond_square(arma::mat& nlm_mat,
                   arma::uvec steps,
                   arma::uvec roughness,
                   arma::uvec dev){

  const int n = steps.size();

  // main loop
  for(int z = 0; z < n; ++z){

   int halfstep  = steps[z]/2;
   int interstep = steps[z];
   int

  }

  return n;
}




/*** R
diamond_square(matrix(5, 9, 7), 1)

*/
