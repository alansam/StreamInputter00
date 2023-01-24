#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std::literals::string_literals;

enum emenu {
  NUL = 0,
  LOAD_METHOD1 = 1, LOAD_METHOD2, LOAD_METHOD3,
  SHOW_DATA, EXIT = 9,
};

struct cli_ctrl {
  emenu io_method;
  bool valid;
  std::vector<int> vdata;
  std::string file_name;
  cli_ctrl(std::string const & fn = ""s)
  : io_method { emenu::NUL },
    valid { false },
    file_name { fn } {
    vdata = std::vector<int>();
  }
};

cli_ctrl & menu00(cli_ctrl & ctrl);
