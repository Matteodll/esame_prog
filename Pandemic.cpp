#include "Pandemic.hpp"

#include <algorithm>
#include <cassert>

// class constructor
Pandemic::Pandemic(double beta, double gamma, int n)
    : beta_{beta}, gamma_{gamma}, n_{n}, board_(n * n) {
  assert(beta >= 0 && beta <= 1);
  assert(gamma >= 0 && gamma <= 1);
  assert(n > 0);
}

// operator() overload to get the state
State Pandemic::operator()(int i, int j) const {
  return (i >= 0 && i < n_ && j >= 0 && j < n_) ? board_[i * n_ + j]
                                                : State::Removed;
}

// operator() overload to set the state
void Pandemic::operator()(int i, int j, State s) {
  assert(i >= 0 && i < n_ && j >= 0 && j < n_);
  board_[i * n_ + j] = s;
}

// size getter
int Pandemic::get_size() const { return n_; }

// board size getter
int Pandemic::get_board_size() const { return board_.size(); }

// method count state
int Pandemic::count(State s) const {
  return std::count(board_.begin(), board_.end(), s);
}