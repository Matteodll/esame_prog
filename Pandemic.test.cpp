#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "Pandemic.hpp"
#include "doctest.h"

TEST_CASE("Testing class Pandemic") {
  SUBCASE("Testing get_size and get_board_size method") {
    Pandemic p1{0.5, 0.3, 50};
    Pandemic p2{.3, .5, 1};

    CHECK(p1.get_size() == 50);
    CHECK(p2.get_size() == 1);

    CHECK(p1.get_board_size() == 2500);
    CHECK(p2.get_board_size() == 1);
  }

  SUBCASE("Testing operator() overloads") {
    Pandemic p{0.5, 0.3, 5};
    p(1, 1, State::Susceptible);
    p(2, 3, State::Infected);
    p(3, 2, State::Removed);
    CHECK(p(1, 1) == State::Susceptible);
    CHECK(p(2, 3) == State::Infected);
    CHECK(p(3, 2) == State::Removed);
    CHECK(p(1, 2) == State::Susceptible);
    CHECK(p(1, 5) == State::Removed);
    CHECK(p(-10, 2) == State::Removed);
    CHECK(p(2, -10) == State::Removed);
    CHECK(p(-10, -10) == State::Removed);
    CHECK(p(20, 2) == State::Removed);
    CHECK(p(3, 20) == State::Removed);
    CHECK(p(20, 20) == State::Removed);
    CHECK(p(0, 0) == State::Susceptible);

    Pandemic p1{0.3, 0.4, 50};
    p1(20, 20, State::Removed);
    p1(21, 21, State::Removed);
    p1(12, 12, State::Infected);
    p1(11, 12, State::Removed);
    CHECK(p1(1, 1) == State::Susceptible);
    CHECK(p1(12, 12) == State::Infected);
    CHECK(p1(20, 20) == State::Removed);
    CHECK(p1(1, 2) == State::Susceptible);
    CHECK(p1(21, 21) == State::Removed);
    CHECK(p1(-1, 2) == State::Removed);
    CHECK(p1(2, -1) == State::Removed);
    CHECK(p1(-1, -1) == State::Removed);
    CHECK(p1(50, 2) == State::Removed);
    CHECK(p1(3, 50) == State::Removed);
    CHECK(p1(50, 50) == State::Removed);
    CHECK(p1(0, 0) == State::Susceptible);
  }

  SUBCASE("Testing count()") {
    Pandemic p{0.5, 0.3, 5};
    p(1, 1, State::Susceptible);
    p(1, 3, State::Infected);
    p(4, 3, State::Infected);
    p(4, 4, State::Infected);
    p(2, 3, State::Infected);
    p(3, 2, State::Removed);
    p(3, 3, State::Removed);
    p(3, 4, State::Removed);
    CHECK(p.count(State::Susceptible) == 18);
    CHECK(p.count(State::Removed) == 3);
    CHECK(p.count(State::Infected) == 4);

    Pandemic p1{0.2, 0.5, 100};
    p1(50, 23, State::Infected);
    p1(10, 7, State::Infected);
    p1(5, 12, State::Infected);
    p1(70, 36, State::Infected);
    p1(80, 23, State::Infected);
    p1(56, 89, State::Infected);
    p1(34, 97, State::Infected);
    p1(26, 63, State::Infected);
    p1(52, 45, State::Infected);
    p1(54, 47, State::Infected);
    p1(29, 39, State::Infected);
    p1(30, 33, State::Infected);
    p1(22, 21, State::Removed);
    p1(23, 21, State::Removed);
    p1(28, 21, State::Removed);
    CHECK(p1.count(State::Susceptible) == 9985);
    CHECK(p1.count(State::Infected) == 12);
    CHECK(p1.count(State::Removed) == 3);
  }
}