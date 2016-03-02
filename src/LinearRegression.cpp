#include <armadillo>
#include "mlexerices/algorithm.hpp"

arma::vec linear_regression(const arma::mat &x,
                            const arma::mat &y,
                            const double alpha) {
  /* detect size */
  const size_t dim = x.n_rows;
  const size_t m = x.n_cols;
  /* add the intercept terms */
  arma::mat ex(dim + 1, m);
  ex.row(0).ones();
  ex.tail_rows(dim) = x;
  /* initialize theta */
  arma::vec theta(dim + 1, arma::fill::zeros);
  /* gradient descent */
  const double c = alpha / m;
  for (int r = 0; r < 1500; r++) {
    const arma::mat tt = theta.t();
    arma::vec d_cost(dim + 1, arma::fill::zeros);
    arma::vec::const_iterator yi = y.cbegin();
    for (int i = 0; i < m; i++) {
      const arma::vec &xi = ex.col(i);
      d_cost += (arma::mat(tt * xi)[0] - *yi++) * xi;
    }
    theta -= c * d_cost;
  }
  return theta;
}
