#include <vec.h>

Vec3 operator+(const Vec3 &v1, const Vec3 &v2) {
  return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vec3 operator-(const Vec3 &v1, const Vec3 &v2) {
  return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3 operator*(const Vec3 &v, double a) {
  return Vec3(v.x * a, v.y * a, v.z * a);
}

Vec3 operator*(double a, const Vec3 &v) {
  return Vec3(v.x * a, v.y * a, v.z * a);
}

double scalProd(const Vec3 &v1, const Vec3 &v2) {
  return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vec3 vecProd(const Vec3 &v1, const Vec3 &v2) {
  return Vec3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.z * v2.z,
              v1.x * v2.y - v1.y * v2.x);
}