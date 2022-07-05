#ifndef PANDEMIC_HPP
#define PANDEMIC_HPP

#include <vector>

enum class State : char { Susceptible, Infected, Removed };

class Pandemic {
  const double beta_;
  const double gamma_;
  const int n_;
  std::vector<State> board_;

 public:
  // class constructor
  Pandemic(double beta, double gamma, int n);

  // operator() overload to get the state
  State operator()(int i, int j) const;

  // operator() overload to set the state
  void operator()(int i, int j, State s);

  // size getter
  int get_size() const;

  // board size getter
  int get_board_size() const;

  // method count state
  int count(State s) const;
};

#endif