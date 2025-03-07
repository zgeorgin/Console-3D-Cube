#include <cmath>
#include <cube.h>
#include <math.h>
#include <screen.h>
#include <sys/ioctl.h>
#include <unistd.h>

int main() {
  struct winsize w;

  // Получаем размеры окна терминала
  if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &w) == -1) {
    perror("Ошибка получения размеров терминала");
    return 1;
  }

  Screen s(80, w.ws_row);
  Cube c(20, {10, 5, 0}, true);
  Vec3 rotationAxis(1 / sqrt(2), 1 / sqrt(2), 0);
  double rotationAngle = M_PI / 12.0;
  for (int i = 0; i < 100; i++) {
    s.clear();
    for (size_t y = 0; y < s.getHeight(); y++) {
      for (size_t x = 0; x < s.getWidth(); x++) {
        if (c.rayCast(x, y))
          s.setPixel(x, y, '#');
      }
    }
    c.rotate(rotationAxis, rotationAngle);
    s.show();
    usleep(50000);
  }

  return 0;
}