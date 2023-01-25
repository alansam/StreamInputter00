#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

/*
 *  MARK:  Class versioning.
 *  Consistent version info.
 */
class versioning {
public:
  consteval
  versioning(uint16_t V_ = 0u, uint16_t R_ = 0u, uint16_t M_ = 0u)
  : ver_ { V_ }, rel_ { R_ }, mod_ { M_ } {}

  auto consteval ver(uint16_t V_) { return ver_ = V_; }
  auto consteval ver(void) const { return ver_; }
  auto consteval rel(uint16_t R_) { return rel_ = R_; }
  auto consteval rel(void) const { return rel_; }
  auto consteval mod(uint16_t M_) { return mod_ = M_; }
  auto consteval mod(void) const { return mod_; }
  auto const vrm(void) const {
    auto vrm_ = std::stringstream();
    vrm_ << std::setfill('0');
    vrm_ << std::setw(3) << ver_
         << '.'
         << std::setw(3) << rel_
         << '.'
         << std::setw(3) << mod_;
    return vrm_.str();
  }

private:
  uint16_t ver_;
  uint16_t rel_;
  uint16_t mod_;
};
