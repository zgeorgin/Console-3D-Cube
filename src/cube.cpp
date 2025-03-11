#include <cube.h>

Cube::Cube(size_t side, Vec3 corner, bool hollow) {
  center = corner + Vec3{side / 2.0, side / 2.0, side / 2.0};

  if (!hollow) {
    for (double i = 0; i < side; i++) {
      for (double j = 0; j < side; j++) {
        for (double k = 0; k < side; k++) {
          if (i == 0 || j == 0 || k == 0 || i == side - 1 || j == side - 1 ||
              k == side - 1)
            points.push_back(Vec3(corner.x + i, corner.y + j, corner.z + k));
        }
      }
    }
  } else {
    for (double i = 0; i < side; i++) {
      for (double j = 0; j < side; j++) {
        for (double k = 0; k < side; k++) {
          if (i == 0 && j == 0 || i == 0 && k == 0 || j == 0 && k == 0 ||
              i == side - 1 && j == side - 1 ||
              i == side - 1 && k == side - 1 ||
              j == side - 1 && k == side - 1 || i == 0 && j == side - 1 ||
              i == 0 && k == side - 1 || j == 0 && k == side - 1 ||
              i == side - 1 && j == 0 || i == side - 1 && k == 0 ||
              j == side - 1 && k == 0)
            points.push_back(Vec3(corner.x + i, corner.y + j, corner.z + k));
        }
      }
    }
  }
}

bool Cube::rayCast(size_t x, size_t y) {
  for (const Vec3 &point : points) {
    if (int(point.x + 0.5) == x && int(point.y + 0.5) == y)
      return true;
  }

  return false;
}

void Cube::rotate(const Vec3 &axis, double angle) {
  Quaternion q(cos(angle / 2.0), sin(angle / 2.0) * axis);
  Quaternion q_n(cos(-angle / 2.0), sin(-angle / 2.0) * axis);
  for (Vec3 &point : points) {
    Quaternion newPos = q * Quaternion(0, point - center) * q_n;
    point = newPos.imag + center;
  }
}