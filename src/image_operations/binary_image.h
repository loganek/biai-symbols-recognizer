#ifndef BINARY_IMAGE_H
#define BINARY_IMAGE_H

#include <string>
#include "image_loader.h"

class BinaryImage
{
 private:
  Size size;
  bool* imageBuffer;

  void ReleaseBuffer();
  bool CheckRange(int x, int y);

 public:
  BinaryImage();
  ~BinaryImage();
  void LoadFromFile(const std::string& filename);
  bool GetPixel(int x, int y);
  void SetPixel(int x, int y, bool value);

  const Size& GetSize();
};

#endif
