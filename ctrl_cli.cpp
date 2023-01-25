#include "ctrl_cli.hpp"
#include "model_cli.hpp"
#include "view_cli.hpp"

using namespace std::literals::string_literals;

static
auto constexpr NL { '\n' };

static
auto constexpr PANIC { 10ul };

static
auto const dl0 = std::string(40, '=');
static
auto const dl1 = std::string(40, '.');
static
auto const dl2 = std::string(40, '`');
static
auto const dl3 = std::string(40, '~');

/*
 *  MARK:  menu00()
 */
cli_ctrl & menu00(cli_ctrl & troller) {
  std::cout << "In function "s << __func__ << "()"s
            << std::endl;
  auto stopper { 0ul };
  int choice { emenu::EXIT };
  do {
    std::cout << NL
              << dl0
              << NL
              << std::setw(3) << emenu::LOAD_METHOD1
              << ": Load data (method"s
              << std::setw(3) << emenu::LOAD_METHOD1
              << ", manual)"s
              << NL
              << std::setw(3) << emenu::LOAD_METHOD2
              << ": Load data (method"s
              << std::setw(3) << emenu::LOAD_METHOD2
              << ", manual)"s
              << NL
              << std::setw(3) << emenu::LOAD_METHOD3
              << ": Load data (method"s
              << std::setw(3) << emenu::LOAD_METHOD3
              << ", file)"s
              << NL
              << std::setw(3) << emenu::SHOW_DATA
              << ": Show data"s
              << NL
              << std::setw(3) << emenu::EXIT
              << ": Exit"s
              << NL
              << dl0
              << std::endl;
    std::cout << " ? "s;
    std::cin >> choice;
    std::cout << NL << "{echo} "s << choice << NL << std::endl;
  
    switch (choice) {
    case emenu::LOAD_METHOD1:
      {
        troller.valid = false;
        troller.io_method = LOAD_METHOD1;
        std::cout << dl1 << NL;
        std::cout << "Provide data:"s << NL;
        troller.vdata.clear();
        troller.vdata = vector_manual_load01(troller.vdata);
        troller.valid = true;
        std::sort(troller.vdata.begin(),
                  troller.vdata.end(),
                  std::less<int>());
      }
      choice = emenu::NUL;
      break;

    case emenu::LOAD_METHOD2:
      {
        troller.valid = false;
        troller.io_method = LOAD_METHOD2;
        std::cout << dl2 << NL;
        std::cout << "Provide data:"s << NL;
        troller.vdata.clear();
        troller.vdata = vector_manual_load01(troller.vdata);
        troller.valid = true;
        std::sort(troller.vdata.begin(),
                  troller.vdata.end(),
                  std::greater<int>());
      }
      choice = emenu::NUL;
      break;

    case emenu::LOAD_METHOD3:
      {
        troller.valid = false;
        troller.io_method = LOAD_METHOD3;
        std::cout << dl3 << NL;
        troller.vdata.clear();
        if (troller.file_name.size() > 0) {
          std::cout << "Loading data from file \""s
                    << troller.file_name
                    << "\""s
                    << NL;
          troller.vdata = vector_file_load00(troller.vdata, troller.file_name);
          troller.valid = true;
          std::sort(troller.vdata.begin(),
                    troller.vdata.end(),
                    std::less<int>());
        }
        else {
          std::cout << "GRONK!: filename not provided"s
                    << NL;
        }
      }
      choice = emenu::NUL;
      break;

    case emenu::SHOW_DATA:
      if (troller.valid) {
        vector_show00(troller.vdata);
      }
      else {
        std::cout << "Nothing to do ..."s << NL;
      }
      choice = emenu::NUL;
      stopper = 0ul;
      break;

    case emenu::EXIT:
      std::cout << "Bye!"s << NL << std::endl;
      stopper = 0ul;
      break;

    default:
      choice = emenu::NUL;
      break;
    }

    std::cin.clear();
    if (stopper++ > PANIC) {
      std::cout << "GRONK: Whoa Nellie!"s << NL << NL;
      break;
    }
  } while (choice != emenu::EXIT);

  return  troller;
}
