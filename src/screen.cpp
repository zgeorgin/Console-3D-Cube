#include <screen.h>

void Screen::show() {
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      std::cout << getPixel(j, i);
    }
    std::cout << '\n';
  }
}