#ifndef IMAGE_PERIMETER_H
#define IMAGE_PERIMETER_H

#include "../binary_image.h"

class ImagePerimeter
{
 private:
  bool IsPixelInPerimeter(int x, int y);
  int perimeter;
  BinaryImage image;

 public:
  ImagePerimeter(const BinaryImage& image);
  void RunAlgorithm();
  int GetPerimeter();
};

#endif
