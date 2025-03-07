#include <quaternion.h>

Quaternion operator+(const Quaternion &q1, const Quaternion &q2) {
  return Quaternion(q1.real + q2.real, q1.imag + q2.imag);
}

Quaternion operator*(const Quaternion &q1, const Quaternion &q2) {
  return Quaternion(q1.real * q2.real - scalProd(q1.imag, q2.imag),
                    q1.real * q2.imag + q2.real * q1.imag +
                        vecProd(q1.imag, q2.imag));
}
