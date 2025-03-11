#pragma once
#include <vec.h>
#include <vector>
#include <stddef.h>
#include <quaternion.h>
#include <math.h>

class Object
{
protected:
  Vec3 center;
  std::vector<Vec3> points;

public:
  bool rayCast(size_t x, size_t y);
  void rotate(const Vec3& rotationAxis, double rotationAngle);
};