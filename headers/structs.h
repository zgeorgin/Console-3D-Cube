#pragma once

struct Vec3 {
  double x, y, z;
  Vec3() : x(0), y(0), z(0) {}
  Vec3(double x, double y, double z) : x(x), y(y), z(z) {}
};

Vec3 operator+(const Vec3 &v1, const Vec3 &v2);

Vec3 operator-(const Vec3 &v1, const Vec3 &v2);

Vec3 operator*(const Vec3 &v, double a);

Vec3 operator*(double a, const Vec3 &v);

double scalProd(const Vec3 &v1, const Vec3 &v2);

Vec3 vecProd(const Vec3 &v1, const Vec3 &v2);