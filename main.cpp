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

  Screen s(w.ws_col / 3, w.ws_row);
  Cube c(w.ws_row / 2.0, {w.ws_row / 2.0, w.ws_row / 4.0, 0}, true);
  Vec3 rotationAxis(1, 0, 0);
  //Vec3 rotationAxis(0, 0, 1);
  double rotationAngle = M_PI / 4.0;
  for (int i = 0; i < 48; i++) {
    s.clear();
    for (size_t y = 0; y < s.getHeight(); y++) {
      for (size_t x = 0; x < s.getWidth(); x++) {
        if (c.rayCast(x, y))
          s.setPixel(x, y, '*');
      }
    }
    c.rotate(rotationAxis, rotationAngle);
    s.show();
    usleep(5e4);
  }

  return 0;
}