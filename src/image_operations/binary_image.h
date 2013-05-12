#ifndef IMAGE_H
#define IMAGE_H

#include <string>

class Image
{
 private:
  int width;
  int height;

 public:
  Image();
  void LoadFromFile(const std::string& filename);
  bool GetPixel(int x, int y);
  void SetPixel(int x, int y);
};

#endif
