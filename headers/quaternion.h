#pragma once

#include <structs.h>

struct Quaternion {
  double real;
  Vec3 imag;
  Quaternion() : real(0), imag() {}
  Quaternion(double real, Vec3 imag) : real(real), imag(imag) {}
};

Quaternion operator+(const Quaternion &q1, const Quaternion &q2);
Quaternion operator*(const Quaternion &q1, const Quaternion &q2);

