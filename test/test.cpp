#include <conio.h>
#include <joy.h>
#include <matplotlibcpp.h>

#include <iostream>
#include <vector>

namespace plt = matplotlibcpp;

void Plot(my_lib::Joy joy) {
  std::vector<int> x{0};
  std::vector<int> y{0};
  std::vector<int> u{joy.RX};
  std::vector<int> w{joy.RY};
  plt::clf();
  plt::quiver(x, y, u, w);
  plt::pause(0.01);
}

int main() {
  my_lib::Joy joy;

  while (TRUE) {
    if (_kbhit()) {
      if (getch() == 'q') break;
    }
    BOOL retval = joy.UpdateState();
    if (retval == FALSE) {
      break;
    }
    Plot(joy);
  }
  return 0;
}
