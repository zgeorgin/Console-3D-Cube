#pragma once
#include <object.h>
#include <cstddef>
#include <stddef.h>
#include <vec.h>
#include <vector>
#include <quaternion.h>
#include <math.h>

class Cube : public Object {
public:
  Cube(size_t side, Vec3 corner, bool hollow = true);
};