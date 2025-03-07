#pragma once

#include <cstddef>
#include <iostream>
#include <stddef.h>
class Screen {
private:
  size_t width, height;
  char *data;

public:
  Screen(size_t width, size_t height)
      : width(width), height(height), data(new char[width * height]) {
    this->clear();
  }
  ~Screen() { delete[] data; }

  void clear() {
    for (size_t i = 0; i < width * height; i++)
      data[i] = ' ';
  }
  void setPixel(size_t x, size_t y, char c) { data[y * width + x] = c; }
  char getPixel(size_t x, size_t y) { return data[y * width + x]; }
  size_t getWidth() { return width; }
  size_t getHeight() { return height; }
  void show();
};