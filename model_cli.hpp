#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

std::vector<int> & vector_manual_load00(std::vector<int> & data);
std::vector<int> & vector_manual_load01(std::vector<int> & data);
std::vector<int> & vector_file_load00(std::vector<int> & data, std::string const & fname);
