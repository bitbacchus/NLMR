#include "rcpp_neigh.h"
using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
NumericMatrix rcpp_neigh(int nrow,
                         int ncol,
                         NumericMatrix mat,
                         int n_categories,
                         NumericVector cells_per_cat,
                         int neighbourhood,
                         float p_neigh,
                         float p_empty) {

    std::vector<std::pair<int, int> > cell_index =
            random_cell_indecies(ncol, nrow, 1);

    for (int cat = n_categories; cat >= 0; cat--)
    {
        int n_cells = cells_per_cat(cat);

        while (n_cells > 0) {

            // NumericMatrix s = rcpp_which(mat(Range(1, nrow),
            //                                  Range(1, ncol)), 0);

            //int row_pos = as<int>(Rcpp::sample(s.nrow(), 1));
            //            int row = s(row_pos, 0) + 1; // why + 1 ?
            //            int col = s(row_pos, 1) + 1;
            assert(!cell_index.empty());
            int col = cell_index.back().first;
            int row = cell_index.back().second;

            double adjacent;

            double up_cell = mat(row - 1, col);
            double left_cell = mat(row, col - 1);
            double right_cell = mat(row, col + 1);
            double low_cell = mat(row + 1, col);

            if (neighbourhood == 8) {

                int upleft_cell = mat(row - 1, col - 1);
                int upright_cell = mat(row - 1, col + 1);
                int lowleft_cell = mat(row + 1, col - 1);
                int lowright_cell = mat(row + 1, col + 1);

                adjacent = sum(NumericVector::create(up_cell,
                                                     left_cell,
                                                     right_cell,
                                                     low_cell,
                                                     upleft_cell,
                                                     upright_cell,
                                                     lowleft_cell,
                                                     lowright_cell));
            } else {

                adjacent = sum(NumericVector::create(up_cell,
                                                     left_cell,
                                                     right_cell,
                                                     low_cell));
            }

            if (adjacent > 0) {

                double rnd_num = Rcpp::as<double>(Rcpp::runif(1));

                if (rnd_num < p_neigh) {
                    mat(row, col) = cat;
                    // Rcout << "The value of mat(row, col) : " << mat(row, col) << "\n";
                    n_cells--;
                    cell_index.pop_back();
                } else {
                    std::random_shuffle(cell_index.begin(), cell_index.end());
                }

            } else {

                double rnd_num = Rcpp::as<double>(Rcpp::runif(1));

                if (rnd_num < p_empty) {
                    mat(row, col) = cat;
                    // Rcout << "The value of mat(row, col) : " << mat(row, col) << "\n";
                    n_cells--;
                    cell_index.pop_back();
                } else {
                    std::random_shuffle(cell_index.begin(), cell_index.end());
                }

            }

            mat(0, _)         = mat(nrow, _);
            mat(nrow + 1, _)  = mat(1, _);
            mat(_, 0)         = mat(_, ncol);
            mat(_, ncol + 1)  = mat(_,1);
        }
    }

    return mat;
}

std::vector<std::pair<int, int> > random_cell_indecies(int ncol, int nrow, int offset)
{
    std::vector<std::pair<int, int> > cell_index(nrow * ncol);
    int cntr = 0;
    for (int col = 0; col < ncol; col++) {
        for (int row = 0; row < nrow; row++) {
            cell_index[cntr].first = col + offset;
            cell_index[cntr].second = row + offset;
            cntr++;
        }
    }
    std::random_shuffle(cell_index.begin(), cell_index.end());

    return cell_index;
}

//NumericMatrix rcpp_which(const NumericMatrix& X, int what) {

//    int n_rows = X.nrow();

//    NumericVector rows(0);
//    NumericVector cols(0);

//    for(int ii = 0; ii < n_rows * n_rows; ii++)
//    {
//        if(X[ii] == what)
//        {
//            rows.push_back(ii % n_rows); // rows.push_back(ii % n_rows + 1);
//            cols.push_back(floor(ii / n_rows)); // cols.push_back(floor(ii / n_rows) + 1);
//        }
//    }
//    NumericMatrix out (rows.size(), 2);
//    out(_,0) = rows; out(_,1)=cols;
//    return out;

//}

/*** R
categories = 15
cat = categories - 1
ncol = 300
nrow = 300
p_neigh = 0.6
p_empty = 0.2
neighbourhood = 4
mat <- matrix(0, nrow + 2, ncol + 2)
no_cat <- rep(floor(nrow * ncol / categories), categories)
table(rcpp_neigh(nrow, ncol, mat, cat, no_cat, neighbourhood, p_neigh, p_empty))
*/

