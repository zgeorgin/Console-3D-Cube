#pragma once
#include <cstddef>
#include <stddef.h>
#include <structs.h>
#include <vector>
#include <quaternion.h>
#include <math.h>

class Cube {
private:
  Vec3 center;
  std::vector<Vec3> points;

public:
  Cube(size_t side, Vec3 corner, bool hollow = true);
  bool rayCast(size_t x, size_t y);
  void rotate(const Vec3& rotationAxis, double rotationAngle);
};