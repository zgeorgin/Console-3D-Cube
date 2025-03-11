#include <object.h>

bool Object::rayCast(size_t x, size_t y) {
  for (const Vec3 &point : points) {
    if (int(point.x + 0.5) == x && int(point.y + 0.5) == y)
      return true;
  }

  return false;
}

void Object::rotate(const Vec3 &axis, double angle) {
  Quaternion q(cos(angle / 2.0), sin(angle / 2.0) * axis);
  Quaternion q_n(cos(-angle / 2.0), sin(-angle / 2.0) * axis);
  for (Vec3 &point : points) {
    Quaternion newPos = q * Quaternion(0, point - center) * q_n;
    point = newPos.imag + center;
  }
}