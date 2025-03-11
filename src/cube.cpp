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
