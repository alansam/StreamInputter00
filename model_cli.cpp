#include "model_cli.hpp"

using namespace std::literals::string_literals;

/*
 *  MARK:  model_load00()
 */
std::vector<int> & vector_manual_load00(std::vector<int> & data) {
  std::cout << "In function "s << __func__ << "()"s
            << std::endl;
  data = std::vector<int>(
      (std::istream_iterator<int>(std::cin)),
      std::istream_iterator<int>());

  return data;
}

/*
 *  MARK:  model_manual_load01()
 */
std::vector<int> & vector_manual_load01(std::vector<int> & data) {
  std::cout << "In function "s << __func__ << "()"s
            << std::endl;
  std::istream_iterator<double> cii(std::cin);
  std::istream_iterator<double> eos;
  std::copy(cii, eos, std::back_inserter(data));

  return data;
}

/*
 *  MARK:  vector_file_load00()
 */
std::vector<int> & vector_file_load00(std::vector<int> & data, std::string const & fname) {
  std::cout << "In function "s << __func__ << "()"s
            << std::endl;

  auto i_file = std::ifstream(fname);
  auto i_iter = std::istream_iterator<int>(i_file);
  auto eof = std::istream_iterator<int>();

  if (i_file.is_open()) {
    data = std::vector<int>(i_iter, eof);
    i_file.close();
  }

  return data;
}