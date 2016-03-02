#include <iostream>
#include <fstream>
#include <vector>
#include <armadillo>
#include "mlexerices/io.hpp"
#include "mlexerices/algorithm.hpp"

void usage(const char *self) {
  std::cout << self << " x_values y_values" << std::endl;
}

int main(int argc, const char *argv[]) {
  if (argc != 3) {
    usage(argv[0]);
    std::exit(-1);
  }
  arma::rowvec x_set = read_content(argv[1], " ");
  arma::rowvec y_set = read_content(argv[2], " ");
  arma::vec theta = linear_regression(x_set, y_set, 0.07);
  std::cout << theta;
  return 0;
}