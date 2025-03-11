#include <screen.h>

void Screen::show() {
  for (size_t i = 0; i < height; i++) {
    for (size_t j = 0; j < width; j++) {
      char pixel = getPixel(j, i);
      std::cout << pixel << ' ';
    }
    std::cout << '\n';
  }
}