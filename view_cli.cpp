#include "view_cli.hpp"

using namespace std::literals::string_literals;

static
auto constexpr sw { 6 };

/*
 *  MARK:  vector_show00()
 */
void vector_show00(std::vector<int> const & data, size_t cc) {
  std::cout << "In function "s << __func__ << "()"s
            << std::endl;
  auto col { 1ul };
  std::cout << '\n';
  std::for_each(data.cbegin(), data.cend(), [&col, cc](auto & vi) {
    std::cout << std::setw(sw) << vi
              << (col++ % cc == 0 ? "\n"s : ""s);
  });
  std::cout << std::endl;

  return;
}
