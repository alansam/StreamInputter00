//  For nuber generation:
//  @see: https://www.random.org/integers/?mode=advanced

#include <iostream>
#include <iomanip>
#include <string>

#include "model_cli.hpp"
#include "view_cli.hpp"
#include "ctrl_cli.hpp"

using namespace std::literals::string_literals;

#define sfy(str) #str ": "

static
auto const file_nm = "./numbers.txt"s;
static
inline
void deets(int argc, char const * argv[]);

/*
 *  MARK:  main()
 */
int main(int argc, char const * argv[]) {
  std::cout << "StreamInputter00\n"s;
  std::cout << "In function "s << __func__ << "()"s
            << std::endl;

  deets(argc, argv);

  cli_ctrl troller(file_nm);
  menu00(troller);

  return 0;
}

/*
 *  MARK:  deets()
 */
static
inline
void deets(int argc, char const * argv[]) {
  std::cout << "Program Name: "s << argv[0] << '\n';
  std::cout << std::setw(32)
            << sfy(__cplusplus)
            << __cplusplus
            << '\n';

#ifdef __cpp_constexpr
  std::cout << std::setw(32)
            << sfy(__cpp_constexpr)
            << __cpp_constexpr
            << '\n';
#endif
#ifdef __cpp_constexpr_in_decltype
  std::cout << std::setw(32)
            << sfy(__cpp_constexpr_in_decltype)
            << __cpp_constexpr_in_decltype
            << '\n';
#endif
#ifdef __cpp_constexpr_dynamic_alloc
  std::cout << std::setw(32)
            << sfy(__cpp_constexpr_dynamic_alloc)
            << __cpp_constexpr_dynamic_alloc
            << '\n';
#endif
#ifdef __cpp_consteval
  std::cout << std::setw(32)
            << sfy(__cpp_consteval)
            << __cpp_consteval
            << '\n';
#endif
#ifdef __cpp_constinit
  std::cout << std::setw(32)
            << sfy(__cpp_constinit)
            << __cpp_constinit
            << '\n';
#endif
  std::cout << std::endl;
}
